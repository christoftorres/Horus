#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import io
import csv
import time
import json
import shutil
import zipfile
import tracemalloc

from utils.utils import *
from utils import settings
from .data_flow_analysis import TaintRunner
from .memory_management import MemoryManager
from .call_flow_analysis import CallFlowAnalysis
from .in_memory_zip import InMemoryZip

class Extractor:
    def extract_facts_from_trace(self, facts_folder, trace, step, max_step, block, transaction, taint_runner, stats, compress, in_memory_zip):
        #if settings.DEBUG_MODE:
        if True:
            tracemalloc.start()

        if not compress:
            def_facts           = open(facts_folder+"/def.facts",           "a")
            use_facts           = open(facts_folder+"/use.facts",           "a")
            arithmetic_facts    = open(facts_folder+"/arithmetic.facts",    "a")
            bitwise_logic_facts = open(facts_folder+"/bitwise_logic.facts", "a")
            storage_facts       = open(facts_folder+"/storage.facts",       "a")
            condition_facts     = open(facts_folder+"/condition.facts",     "a")
            transfer_facts      = open(facts_folder+"/transfer.facts",      "a")
            call_facts          = open(facts_folder+"/call.facts",          "a")
            throw_facts         = open(facts_folder+"/throw.facts",         "a")
            selfdestruct_facts  = open(facts_folder+"/selfdestruct.facts",  "a")
            error_facts         = open(facts_folder+"/error.facts",         "a")
            block_facts         = open(facts_folder+"/block.facts",         "a")
            transaction_facts   = open(facts_folder+"/transaction.facts",   "a")

        call_flow_analysis = CallFlowAnalysis(transaction)
        memory_manager = MemoryManager(transaction)
        execution_begin = time.time()

        balances = {}
        first_step = step
        while step in trace:
            if settings.DEBUG_MODE:
                if step == first_step:
                    print("")
                    print("Extracting facts from transaction: "+transaction["hash"]+" (block: "+str(transaction["blockNumber"])+")")
                    print(transaction["from"].lower()+" --> "+transaction["to"].lower())
                    print("")
                    print("Step \t PC \t Operation\t Gas       \t GasCost \t Depth \t Contract")
                    print("-------------------------------------------------------------------------------------------------------------------")
                print(str(step)+" \t "+str(trace[step]["pc"])+" \t "+trace[step]["op"].ljust(10)+"\t "+str(trace[step]["gas"]).ljust(10)+" \t "+str(trace[step]["gasCost"]).ljust(10)+" \t "+str(trace[step]["depth"])+" \t "+str(call_flow_analysis.get_caller())+(" \t "+"[Error]" if "error" in trace[step] else ""))

            # Use facts
            if trace[step]["op"] in [
                "ADD", "SUB", "MUL",                                                        # Arithmetic opcodes
                "AND",                                                                      # Bitwise logic opcodes
                "SHA3",                                                                     # Hash computation opcodes
                "SSTORE", "SLOAD",                                                          # Storage opcodes
                "JUMPI",                                                                    # Flow opcodes
                "LOG3",                                                                     # Event opcodes
                "CALL", "DELEGATECALL",                                                     # Call opcodes
                "SELFDESTRUCT",
               ]:
                values = taint_runner.check_taint(trace[step])
                if values:
                    for i in values:
                        if compress:
                            in_memory_zip.append(facts_folder+"/use.facts", "%d\t%d\r\n" % (step, i))
                        else:
                            use_facts.write("%d\t%d\r\n" % (step, i))

            taint_runner.propagate_taint(trace[step], call_flow_analysis.get_caller())

            # Def facts
            if trace[step]["op"] in [
                "ADD", "SUB", "MUL",                                                        # Arithmetic opcodes
                "AND",                                                                      # Bitwise logic opcodes
                "SHA3",                                                                     # Hash computation opcodes
                "BALANCE", "ORIGIN", "CALLER", "CALLDATALOAD", "CALLDATACOPY",              # Environmental opcodes
                "BLOCKHASH", "COINBASE", "TIMESTAMP", "NUMBER", "DIFFICULTY", "GASLIMIT",   # Block opcodes
                "SLOAD",                                                                    # Storage opcodes
                "CALL",                                                                     # Call opcodes
               ]:
                taint_runner.introduce_taint(step, trace[step])
                if compress:
                    in_memory_zip.append(facts_folder+"/def.facts", "%d\t%s\r\n" % (step, trace[step]["op"]))
                else:
                    def_facts.write("%d\t%s\r\n" % (step, trace[step]["op"]))

            # Arithmetic facts
            if trace[step]["op"] in ["ADD", "SUB", "MUL", "DIV"]:
                _opcode = trace[step]["op"]
                _first_operand = int(trace[step]["stack"][-1], 16)
                _second_operand = int(trace[step]["stack"][-2], 16)
                if   trace[step]["op"] == "ADD":
                    _arithmetic_result = _first_operand + _second_operand
                elif trace[step]["op"] == "SUB":
                    _arithmetic_result = _first_operand - _second_operand
                elif trace[step]["op"] == "MUL":
                    _arithmetic_result = _first_operand * _second_operand
                elif trace[step]["op"] == "DIV":
                    if _second_operand != 0:
                        _arithmetic_result = int(_first_operand / _second_operand)
                    else:
                        _arithmetic_result = 0
                if not "error" in trace[step]:
                    _evm_result = int(trace[step + 1]["stack"][-1], 16)
                else:
                    _evm_result = 0
                if compress:
                    in_memory_zip.append(facts_folder+"/arithmetic.facts", "%d\t%s\t%s\t%s\t%s\t%s\r\n" % (step, _opcode, _first_operand, _second_operand, _arithmetic_result, _evm_result))
                else:
                    arithmetic_facts.write("%d\t%s\t%s\t%s\t%s\t%s\r\n" % (step, _opcode, _first_operand, _second_operand, _arithmetic_result, _evm_result))

            # Bitwise logic facts
            elif trace[step]["op"] in ["AND", "OR", "XOR"]:
                _opcode = trace[step]["op"]
                _first_operand = int(trace[step]["stack"][-1], 16)
                _second_operand = int(trace[step]["stack"][-2], 16)
                if compress:
                    in_memory_zip.append(facts_folder+"/bitwise_logic.facts", "%d\t%s\t%s\t%s\r\n" % (step, _opcode, _first_operand, _second_operand))
                else:
                    bitwise_logic_facts.write("%d\t%s\t%s\t%s\r\n" % (step, _opcode, _first_operand, _second_operand))

            # Storage facts
            elif trace[step]["op"] in ["SSTORE", "SLOAD"]:
                _opcode = trace[step]["op"]
                _transaction_hash = transaction["hash"]
                _block_number = transaction["blockNumber"]
                _caller = transaction["from"]
                _contract = call_flow_analysis.get_caller()
                _storage_index = trace[step]["stack"][-1]
                if compress:
                    in_memory_zip.append(facts_folder+"/storage.facts", "%d\t%s\t%d\t%s\t%s\t%s\t%s\r\n" % (step, _opcode, _block_number, _transaction_hash, _caller, _contract, _storage_index))
                else:
                    storage_facts.write("%d\t%s\t%d\t%s\t%s\t%s\t%s\r\n" % (step, _opcode, _block_number, _transaction_hash, _caller, _contract, _storage_index))

            # Condition facts
            elif trace[step]["op"] == "JUMPI":
                if compress:
                    in_memory_zip.append(facts_folder+"/condition.facts", "%d\t%s\r\n" % (step, transaction["hash"]))
                else:
                    condition_facts.write("%d\t%s\r\n" % (step, transaction["hash"]))

            # Transfer facts
            elif trace[step]["op"] == "LOG3":
                # This is the signature (topic) of the following ERC-20 event: Transfer(address,address,uint256)
                if trace[step]["stack"][-3] == "ddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef":
                    _transaction_hash = transaction["hash"]
                    offset = int(trace[step]["stack"][-1], 16)
                    size = int(trace[step]["stack"][-2], 16)
                    _from = normalize_32_byte_hex_address(trace[step]["stack"][-4])
                    _to = normalize_32_byte_hex_address(trace[step]["stack"][-5])
                    _value = int(memory_manager.memory_read_bytes(offset, size).hex(), 16)
                    if compress:
                        in_memory_zip.append(facts_folder+"/transfer.facts", "%d\t%s\t%s\t%s\t%s\r\n" % (step, _transaction_hash, _from, _to, _value))
                    else:
                        transfer_facts.write("%d\t%s\t%s\t%s\t%s\r\n" % (step, _transaction_hash, _from, _to, _value))

            # Call facts
            elif trace[step]["op"] in ["CREATE", "CREATE2", "CALL", "CALLCODE", "DELEGATECALL", "STATICCALL"]:
                i = step + 1
                while i < max_step and trace[step]["depth"] < trace[i]["depth"]:
                    i += 1
                _transaction_hash = transaction["hash"]
                _opcode = trace[step]["op"]
                _caller = call_flow_analysis.get_caller()
                if trace[step]["op"] in ["CREATE", "CREATE2"]:
                    if not "error" in trace[step]:
                        _callee = normalize_32_byte_hex_address(trace[i]["stack"][-1])
                    else:
                        _callee = ""
                else:
                    _callee = normalize_32_byte_hex_address(trace[step]["stack"][-2])
                if trace[step]["op"] in ["CREATE", "CREATE2"]:
                    _amount = int(trace[step]["stack"][-1], 16)
                elif trace[step]["op"] in ["DELEGATECALL", "STATICCALL"]:
                    _amount = 0
                else:
                    _amount = int(trace[step]["stack"][-3], 16)
                _depth = trace[step]["depth"]
                if trace[step]["op"] in ["CREATE", "CREATE2"]:
                    if _callee != 0:
                        _success = 1
                    else:
                        _success = 0
                elif not "error" in trace[step]:
                    _success = int(trace[i]["stack"][-1], 16)
                else:
                    _success = 0
                if trace[step]["op"] in ["CREATE", "CREATE2"]:
                    offset = int(trace[step]["stack"][-2], 16)
                    size = int(trace[step]["stack"][-3], 16)
                elif trace[step]["op"] in ["CALL", "CALLCODE"]:
                    offset = int(trace[step]["stack"][-4], 16)
                    size = int(trace[step]["stack"][-5], 16)
                elif trace[step]["op"] in ["DELEGATECALL", "STATICCALL"]:
                    offset = int(trace[step]["stack"][-3], 16)
                    size = int(trace[step]["stack"][-4], 16)
                _input_data = memory_manager.memory_read_bytes(offset, size)
                if _caller not in balances:
                    balances[_caller] = settings.W3.eth.getBalance(settings.W3.toChecksumAddress(_caller), transaction["blockNumber"]-1)
                balances[_caller] -= _amount
                if compress:
                    in_memory_zip.append(facts_folder+"/call.facts", "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\r\n" % (step, _transaction_hash, _opcode, _caller, _callee, _input_data.hex(), _amount, _depth, _success))
                else:
                    call_facts.write("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\r\n" % (step, _transaction_hash, _opcode, _caller, _callee, _input_data.hex(), _amount, _depth, _success))

            # Throw facts
            elif trace[step]["op"] in ["REVERT", "INVALID", "ASSERTFAIL"]:
                _transaction_hash = transaction["hash"]
                _opcode = trace[step]["op"]
                _caller = call_flow_analysis.get_caller()
                _depth = trace[step]["depth"]
                if compress:
                    in_memory_zip.append(facts_folder+"/throw.facts", "%d\t%s\t%s\t%s\t%d\r\n" % (step, _transaction_hash, _opcode, _caller, _depth))
                else:
                    throw_facts.write("%d\t%s\t%s\t%s\t%d\r\n" % (step, _transaction_hash, _opcode, _caller, _depth))

            # Selfdestruct facts
            elif trace[step]["op"] in ["SELFDESTRUCT", "SUICIDE"]:
                _transaction_hash = transaction["hash"]
                _caller = transaction["from"]
                _destination = normalize_32_byte_hex_address(trace[step]["stack"][-1])
                _contract = call_flow_analysis.get_caller()
                if _contract not in balances:
                    _balance = settings.W3.eth.getBalance(settings.W3.toChecksumAddress(_contract), transaction["blockNumber"]-1)
                else:
                    _balance = balances[_contract]
                if compress:
                    in_memory_zip.append(facts_folder+"/selfdestruct.facts", "%d\t%s\t%s\t%s\t%s\t%s\r\n" % (step, _transaction_hash, _caller, _contract, _destination, _balance))
                else:
                    selfdestruct_facts.write("%d\t%s\t%s\t%s\t%s\t%s\r\n" % (step, _transaction_hash, _caller, _contract, _destination, _balance))

            # Error facts
            if "error" in trace[step]:
                # Fix for https://github.com/ethereum/go-ethereum/issues/2576
                # There are four different EVM exceptions: "out of gas", "invalid jump destination", "invalid instruction" and "stack underflow"
                _error_message = "out of gas" # Default error message in Geth is 'out of gas'
                if trace[step]["error"]:
                    _error_message = trace[step]["error"]
                if compress:
                    in_memory_zip.append(facts_folder+"/error.facts", "%s\t%s\r\n" % (transaction["hash"], _error_message))
                else:
                    error_facts.write("%s\t%s\r\n" % (transaction["hash"], _error_message))

            call_flow_analysis.analyze_call_flow(step, max_step, trace)
            memory_manager.manage_memory(trace, step, transaction)
            step += 1
        taint_runner.clear_machine_state()

        # Block facts
        if compress:
            in_memory_zip.append(facts_folder+"/block.facts", "%d\t%d\t%d\t%d\r\n" % (block["number"], block["gasUsed"], block["gasLimit"], block["timestamp"]))
        else:
            block_facts.write("%d\t%d\t%d\t%d\r\n" % (block["number"], block["gasUsed"], block["gasLimit"], block["timestamp"]))

        # Transaction facts
        if max_step in trace and trace[max_step]["op"] in ["STOP", "RETURN", "SELFDESTRUCT"]:
            _status = 1
        else:
            _status = 0
        if compress:
            in_memory_zip.append(facts_folder+"/transaction.facts", "%s\t%s\t%s\t%s\t%d\t%d\r\n" % (transaction["hash"], transaction["from"], transaction["to"], transaction["input"].replace("0x", ""), _status, transaction["blockNumber"]))
        else:
            transaction_facts.write("%s\t%s\t%s\t%s\t%d\t%d\r\n" % (transaction["hash"], transaction["from"], transaction["to"], transaction["input"].replace("0x", ""), _status, transaction["blockNumber"]))

        if not compress:
            def_facts.close()
            use_facts.close()
            arithmetic_facts.close()
            bitwise_logic_facts.close()
            storage_facts.close()
            condition_facts.close()
            transfer_facts.close()
            call_facts.close()
            throw_facts.close()
            selfdestruct_facts.close()
            error_facts.close()
            block_facts.close()
            transaction_facts.close()

        if settings.DEBUG_MODE:
            print("-------------------------------------------------------------------------------------------------------------------")

        execution_end = time.time()
        execution_delta = execution_end - execution_begin
        stats["extraction_times"].append(execution_delta)
        print("Extracting facts for transaction "+str(transaction["hash"])+" took %.2f second(s)." % execution_delta)

        #if settings.DEBUG_MODE:
        if True:
            current, peak = tracemalloc.get_traced_memory()
            print("Memory usage: %d MB (%d MB)" % (int(current/1024/1024), int(peak/1024/1024)))

        return step

    def extract_facts_from_transactions(self, connection, transactions, blocks, facts_folder, compress):
        step = 0
        trace = {}
        max_step = 0
        taint_runner = TaintRunner()

        extracted_transactions = 0
        if compress:
            if os.path.isfile(facts_folder+".zip"):
                archive = zipfile.ZipFile(facts_folder+".zip", "r")
                file = io.TextIOWrapper(archive.open(facts_folder+"/transaction.facts"))
                reader = csv.reader(file, delimiter='\t')
                extracted_transactions = sum(1 for row in reader)
        else:
            if os.path.isfile(facts_folder+"/transaction.facts"):
                with open(facts_folder+"/transaction.facts") as file:
                    reader = csv.reader(file, delimiter='\t')
                    extracted_transactions = sum(1 for row in reader)

        if len(transactions) != extracted_transactions:
            if compress:
                if os.path.isfile(facts_folder+".zip"):
                    os.remove(facts_folder+".zip")
            else:
                if os.path.isdir(facts_folder):
                    shutil.rmtree(facts_folder)
        else:
            print("Transactions have already been extracted.")
            return

        if not compress and not os.path.isdir(facts_folder):
            os.mkdir(facts_folder)

        stats = {"transactions": [], "retrieval_times": [], "extraction_times": []}

        in_memory_zip = None
        if compress:
            in_memory_zip = InMemoryZip()
            in_memory_zip.append(facts_folder+"/def.facts", "")
            in_memory_zip.append(facts_folder+"/use.facts", "")
            in_memory_zip.append(facts_folder+"/arithmetic.facts", "")
            in_memory_zip.append(facts_folder+"/bitwise_logic.facts", "")
            in_memory_zip.append(facts_folder+"/storage.facts", "")
            in_memory_zip.append(facts_folder+"/condition.facts", "")
            in_memory_zip.append(facts_folder+"/transfer.facts", "")
            in_memory_zip.append(facts_folder+"/call.facts", "")
            in_memory_zip.append(facts_folder+"/throw.facts", "")
            in_memory_zip.append(facts_folder+"/selfdestruct.facts", "")
            in_memory_zip.append(facts_folder+"/error.facts", "")
            in_memory_zip.append(facts_folder+"/block.facts", "")
            in_memory_zip.append(facts_folder+"/transaction.facts", "")

        for transaction in transactions:
            stats["transactions"].append(transaction["hash"])
            retrieval_begin = time.time()
            trace_response = request_debug_trace(connection, settings.CONNECTION_RETRIES, settings.RPC_HOST, settings.RPC_PORT, settings.REQUEST_TIMEOUT, settings.REQUEST_RETRY_INTERVAL, transaction["hash"])
            #request_debug_trace_stream(settings.RPC_HOST, settings.RPC_PORT, transaction["hash"])
            retrieval_end = time.time()
            retrieval_delta = retrieval_end - retrieval_begin
            stats["retrieval_times"].append(retrieval_delta)
            if "error" in trace_response:
                print("An error occured in retrieving the trace: "+str(trace_response["error"]))
                raise Exception("An error occured in retrieving the trace: {}".format(trace_response["error"]))
            else:
                for k in range(len(trace_response["result"]["structLogs"])):
                    trace[k+step] = trace_response["result"]["structLogs"][k]
                    max_step = k+step
            if settings.DEBUG_MODE:
                print("Retrieving transaction "+transaction["hash"]+" took %.2f second(s). (%d MB)" % (retrieval_delta, (deep_getsizeof(trace, set()) / 1024) / 1024))
            else:
                print("Retrieving transaction "+transaction["hash"]+" took %.2f second(s)." % (retrieval_delta))
            if blocks:
                block = blocks[transaction["blockNumber"]]
            else:
                block = format_block(settings.W3.eth.getBlock(transaction["blockNumber"]))
            step = self.extract_facts_from_trace(facts_folder, trace, step, max_step, block, transaction, taint_runner, stats, compress, in_memory_zip)
            # Free memory
            trace = {}

        print()
        print("Retrieval times: \t "+str(min(stats["retrieval_times"]))+"  Min \t "+str(max(stats["retrieval_times"]))+" Max \t "+str(sum(stats["retrieval_times"])/len(stats["retrieval_times"]))+" Mean.")
        print("Extraction times: \t "+str(min(stats["extraction_times"]))+" Min \t "+str(max(stats["extraction_times"]))+" Max \t "+str(sum(stats["extraction_times"])/len(stats["extraction_times"]))+" Mean.")

        if compress:
            in_memory_zip.append(facts_folder+"/stats.json", json.dumps(stats))
            in_memory_zip.writetofile(facts_folder+".zip")
        else:
            with open(facts_folder+"/stats.json", "w") as jsonfile:
                json.dump(stats, jsonfile)
