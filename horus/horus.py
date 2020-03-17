#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import time
import copy
import http
import json
import shlex
import shutil
import requests
import argparse
import traceback
import subprocess

from web3 import Web3
from operator import itemgetter

from utils.utils import *
from utils import settings
from extractor.data_flow_analysis import TaintRunner
from extractor.call_flow_analysis import CallFlowAnalysis

def extract_facts_from_trace(facts_folder, trace, step, block, transaction, taint_runner):
    def_facts           = open(facts_folder+"/def.facts",           "a")
    use_facts           = open(facts_folder+"/use.facts",           "a")
    arithmetic_facts    = open(facts_folder+"/arithmetic.facts",    "a")
    bitwise_logic_facts = open(facts_folder+"/bitwise_logic.facts", "a")
    storage_facts       = open(facts_folder+"/storage.facts",       "a")
    call_facts          = open(facts_folder+"/call.facts",          "a")
    throw_facts         = open(facts_folder+"/throw.facts",         "a")
    selfdestruct_facts  = open(facts_folder+"/selfdestruct.facts",  "a")
    error_facts         = open(facts_folder+"/error.facts",         "a")
    block_facts         = open(facts_folder+"/block.facts",         "a")
    transaction_facts   = open(facts_folder+"/transaction.facts",   "a")

    call_flow_analysis = CallFlowAnalysis(transaction)
    execution_begin = time.time()

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
            print(str(step)+" \t "+str(trace[step]["pc"])+" \t "+trace[step]["op"].ljust(10)+"\t "+str(trace[step]["gas"]).ljust(10)+" \t "+str(trace[step]["gasCost"]).ljust(10)+" \t "+str(trace[step]["depth"])+" \t "+str(call_flow_analysis.call_stack[-1])+(" \t "+"[Error]" if "error" in trace[step] else ""))

        taint_runner.propagate_taint(trace[step], call_flow_analysis.call_stack[-1])

        # Def facts
        if trace[step]["op"] in [
            "ADD", "SUB", "MUL", "DIV",                                                 # Arithmetic opcodes
            "AND", "OR", "XOR",                                                         # Bitwise logic opcodes
            "ORIGIN", "CALLER", "CALLDATALOAD", "CALLDATACOPY",                         # Environmental opcodes
            "BLOCKHASH", "COINBASE", "TIMESTAMP", "NUMBER", "DIFFICULTY", "GASLIMIT",   # Block opcodes
            "SSTORE", "SLOAD",                                                          # Storage opcodes
            "JUMPI",                                                                    # Flow opcodes
            "CREATE", "CALL", "CALLCODE", "DELEGATECALL", "STATICCALL",                 # Call opcodes
            "REVERT", "INVALID", "ASSERTFAIL",                                          # Throw opcodes
            "SELFDESTRUCT", "SUICIDE"                                                   # Selfdestruct opcodes
           ]:
            taint_runner.introduce_taint(step, trace[step])
            def_facts.write("%d\t%s\r\n" % (step, trace[step]["op"]))

        # Use facts
        values = taint_runner.check_taint(trace[step])
        if values:
            for i in values:
                use_facts.write("%d\t%d\r\n" % (step, i))

        # Arithmetic facts
        if trace[step]["op"] in ["ADD", "SUB", "MUL", "DIV"]:
            opcode = trace[step]["op"]
            first_operand = int(trace[step]["stack"][-1], 16)
            second_operand = int(trace[step]["stack"][-2], 16)
            if   trace[step]["op"] == "ADD":
                arithmetic_result = first_operand + second_operand
            elif trace[step]["op"] == "SUB":
                arithmetic_result = first_operand - second_operand
            elif trace[step]["op"] == "MUL":
                arithmetic_result = first_operand * second_operand
            elif trace[step]["op"] == "DIV":
                if second_operand != 0:
                    arithmetic_result = int(first_operand / second_operand)
                else:
                    arithmetic_result = 0
            evm_result = int(trace[step + 1]["stack"][-1], 16)
            arithmetic_facts.write("%d\t%s\t%s\t%s\t%s\t%s\r\n" % (step, opcode, first_operand, second_operand, arithmetic_result, evm_result))

        # Bitwise logic facts
        elif trace[step]["op"] in ["AND", "OR", "XOR"]:
            opcode = trace[step]["op"]
            first_operand = int(trace[step]["stack"][-1], 16)
            second_operand = int(trace[step]["stack"][-2], 16)
            bitwise_logic_facts.write("%d\t%s\t%s\t%s\r\n" % (step, opcode, first_operand, second_operand))

        # Storage facts
        elif trace[step]["op"] in ["SSTORE", "SLOAD"]:
            opcode = trace[step]["op"]
            transaction_hash = transaction["hash"]
            block_number = transaction["blockNumber"]
            caller = transaction["from"]
            contract = call_flow_analysis.call_stack[-1]
            storage_index = trace[step]["stack"][-1]
            storage_facts.write("%d\t%s\t%d\t%s\t%s\t%s\t%s\r\n" % (step, opcode, block_number, transaction_hash, caller, contract, storage_index))

        # Call facts
        elif trace[step]["op"] in ["CREATE", "CALL", "CALLCODE", "DELEGATECALL", "STATICCALL"]:
            i = step + 1
            while i < len(trace)-1 and trace[step]["depth"] < trace[i]["depth"]:
                i += 1
            transaction_hash = transaction["hash"]
            opcode = trace[step]["op"]
            caller = call_flow_analysis.call_stack[-1]
            if trace[step]["op"] == "CREATE":
                callee = normalize_32_byte_hex_address(trace[i]["stack"][-1])
            else:
                callee = normalize_32_byte_hex_address(trace[step]["stack"][-2])
            if trace[step]["op"] == "CREATE":
                amount = int(trace[step]["stack"][-1], 16)
            else:
                amount = int(trace[step]["stack"][-3], 16)
            depth = trace[step]["depth"]
            if trace[step]["op"] == "CREATE":
                if callee != 0:
                    success = 1
                else:
                    success = 0
            else:
                success = int(trace[i]["stack"][-1], 16)
            if trace[step]["op"] == "CREATE":
                offset = 2 * int(trace[step]["stack"][-2], 16)
                size = 2 * int(trace[step]["stack"][-3], 16)
            elif trace[step]["op"] in ["CALL", "CALLCODE"]:
                offset = 2 * int(trace[step]["stack"][-4], 16)
                size = 2 * int(trace[step]["stack"][-5], 16)
            elif trace[step]["op"] in ["DELEGATECALL", "STATICCALL"]:
                offset = 2 * int(trace[step]["stack"][-3], 16)
                size = 2 * int(trace[step]["stack"][-4], 16)
            input_data = ''.join(trace[step]["memory"])[offset:offset+size]
            call_facts.write("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\r\n" % (step, transaction_hash, opcode, caller, callee, input_data, amount, depth, success))

        # Throw facts
        elif trace[step]["op"] in ["REVERT", "INVALID", "ASSERTFAIL"]:
            opcode = trace[step]["op"]
            caller = call_flow_analysis.call_stack[-1]
            depth = trace[step]["depth"]
            throw_facts.write("%d\t%s\t%s\t%d\r\n" % (step, opcode, caller, depth))

        # Selfdestruct facts
        elif trace[step]["op"] in ["SELFDESTRUCT", "SUICIDE"]:
            caller = transaction["from"]
            destination = hex(int(trace[step]["stack"][-1], 16))
            selfdestruct_facts.write("%d\t%s\t%s\r\n" % (step, caller, destination))

        # Error facts
        if "error" in trace[step]:
            # Fix for https://github.com/ethereum/go-ethereum/issues/2576
            # There are four different EVM exceptions: "out of gas", "invalid jump destination", "invalid instruction" and "stack underflow"
            error_message = "out of gas" # Default error message in Geth is 'out of gas'
            if trace[step]["error"]:
                error_message = trace[step]["error"]
            error_facts.write("%s\t%s\r\n" % (transaction["hash"], error_message))

        call_flow_analysis.analyze_call_flow(step, trace)
        step += 1
    taint_runner.clear_machine_state()

    # Block facts
    block_facts.write("%d\t%d\t%d\r\n" % (block["number"], block["gasUsed"], block["gasLimit"]))

    # Transaction facts
    transaction_facts.write("%s\t%s\t%s\t%s\t%d\r\n" % (transaction["hash"], transaction["from"], transaction["to"], transaction["input"].replace("0x", ""), transaction["blockNumber"]))

    def_facts.close()
    use_facts.close()
    arithmetic_facts.close()
    bitwise_logic_facts.close()
    storage_facts.close()
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
    print("Extracting facts for transaction "+str(transaction["hash"])+" took %.2f second(s)." % execution_delta)

    return step

def extract_facts_from_transactions(connection, transactions, facts_folder):
    step = 0
    trace = {}

    if os.path.isdir(facts_folder):
        shutil.rmtree(facts_folder)
    if not os.path.isdir(facts_folder):
        os.mkdir(facts_folder)

    taint_runner = TaintRunner()

    for transaction in transactions:
        retrieval_begin = time.time()
        trace_response = request_debug_trace(connection, settings.REQUEST_TIMEOUT, settings.REQUEST_RETRY_INTERVAL, transaction["hash"])
        if "error" in trace_response:
            print("An error occured in retrieving the trace: "+str(trace_response["error"]))
            raise Exception("An error occured in retrieving the trace: {}".format(trace_response["error"]))
        else:
            for k in range(len(trace_response["result"]["structLogs"])):
                trace[k+step] = trace_response["result"]["structLogs"][k]
        retrieval_end = time.time()
        retrieval_delta = retrieval_end - retrieval_begin
        print("Retrieving transaction "+transaction["hash"]+" took %.2f second(s). (%d MB)" % (retrieval_delta, (deep_getsizeof(trace, set()) / 1024) / 1024))
        block = format_block(settings.W3.eth.getBlock(transaction["blockNumber"]))
        step = extract_facts_from_trace(facts_folder, trace, step, block, transaction, taint_runner)

def compile_datalog_file(datalog_file):
    if os.path.isdir("analyzer/executable"):
        shutil.rmtree("analyzer/executable")
        os.mkdir("analyzer/executable")
    else:
        os.mkdir("analyzer/executable")
    print("Compiling datalog rules and queries into a parallel C++ executable...")
    compilation_begin = time.time()
    p = subprocess.Popen(shlex.split("souffle -o analyzer/executable/analyzer "+datalog_file), stdout=subprocess.PIPE)
    p.communicate()
    compilation_end = time.time()
    print("Compilation took %.2f second(s).\n" % (compilation_end - compilation_begin))

def analyze_facts(facts_folder, results_folder, datalog_file):
    # Create parallel C++ executable if not available or is out-dated
    if not os.path.isdir("analyzer/executable"):
        compile_datalog_file(datalog_file)
    elif os.stat(datalog_file)[8] > os.stat("analyzer/executable/analyzer")[8]:
        compile_datalog_file(datalog_file)
    # Run datalog analysis through executable
    analysis_begin = time.time()
    p = subprocess.Popen(shlex.split("./analyzer/executable/analyzer -D "+results_folder+" -F "+facts_folder), stdout=subprocess.PIPE)
    p.communicate()
    analysis_end = time.time()
    return analysis_end - analysis_begin

def main():
    execution_begin = time.time()
    connection = None

    try:
        global args

        print("")
        print("@@@  @@@   @@@@@@   @@@@@@@   @@@  @@@   @@@@@@ ")
        print("@@@  @@@  @@@@@@@@  @@@@@@@@  @@@  @@@  @@@@@@@ ")
        print("@@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@  !@@     ")
        print("!@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@  !@!     ")
        print("@!@!@!@!  @!@  !@!  @!@!!@!   @!@  !@!  !!@@!!  ")
        print("!!!@!!!!  !@!  !!!  !!@!@!    !@!  !!!   !!@!!! ")
        print("!!:  !!!  !!:  !!!  !!: :!!   !!:  !!!       !:!")
        print(":!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!      !:! ")
        print("::   :::  ::::: ::  ::   :::  ::::: ::  :::: :: ")
        print(":   : :   : :  :    :   : :   : :  :   :: : :   ")
        print("")

        parser = argparse.ArgumentParser()

        group1 = parser.add_mutually_exclusive_group(required=True)
        group1.add_argument(
            "-e", "--extract", action="store_true", help="extract datalog facts for a transaction, block or contract")
        group1.add_argument(
            "-a", "--analyze", action="store_true", help="analyze datalog facts")

        group2 = parser.add_mutually_exclusive_group()
        group2.add_argument(
            "-t", "--transaction-hash", type=str, help="transaction hash to be extracted")
        group2.add_argument(
            "-b", "--block-number", type=int, help="block number to be extracted")
        group2.add_argument(
            "-c", "--contract-address", type=str, help="contract address to be extracted")

        parser.add_argument(
            "-f", "--facts-folder", type=str, help="folder where datalog facts should be extracted/analyzed (default: '"+settings.FACTS_FOLDER+"')")
        parser.add_argument(
            "-r", "--results-folder", type=str, help="folder where results should be saved (default: '"+settings.RESULTS_FOLDER+"')")
        parser.add_argument(
            "-d", "--datalog-file", type=str, help="file with datalog rules and queries to be analyzed (default: '"+settings.DATALOG_FILE+"')")

        parser.add_argument(
            "--debug", action="store_true", help="print debug information to the console")
        parser.add_argument(
            "--host", type=str, help="client HTTP-RPC listening interface (default: '"+settings.RPC_HOST+"')")
        parser.add_argument(
            "--port", type=int, help="client HTTP-RPC listening port (default: '"+str(settings.RPC_PORT)+"')")
        parser.add_argument(
            "-v", "--version", action="version", version="Horus version 0.0.1 - 'Ramses II'")

        args = parser.parse_args()

        if args.extract and not args.transaction_hash and not args.block_number and not args.contract_address:
            parser.error("--extract requires --transaction, --block or --contract")
        if args.analyze and (args.transaction_hash or args.block_number or args.contract_address):
            parser.error("--analyze does not work in conjunction with --transaction, --block or --contract")
        if args.facts_folder:
            settings.FACTS_FOLDER = args.facts_folder
        if args.results_folder:
            settings.RESULTS_FOLDER = args.results_folder
        if args.datalog_file:
            settings.DATALOG_FILE = args.datalog_file
        if args.debug:
            settings.DEBUG_MODE = args.debug
        if args.host:
            settings.RPC_HOST = args.host
        if args.port:
            settings.RPC_PORT = args.port

        if args.extract and (args.transaction_hash or args.block_number or args.contract_address):
            tries = 0
            network = ""
            while not settings.W3 and tries < settings.CONNECTION_RETRIES:
                try:
                    tries += 1
                    settings.W3 = Web3(Web3.HTTPProvider("http://"+settings.RPC_HOST+":"+str(settings.RPC_PORT)))
                    if settings.W3.isConnected():
                        network = ""
                        if settings.W3.version.network   == "1":
                            network = "mainnet"
                        elif settings.W3.version.network == "2":
                            network = "morden"
                        elif settings.W3.version.network == "3":
                            network = "ropsten"
                        else:
                            network = "unknown"
                        print("Connected to "+str(settings.W3.version.node)+" ("+network+")")
                    else:
                        print("Error: Could not connect to Ethereum client. Please make sure the client is running and settings are correct.")
                    if not settings.W3.eth.syncing:
                        print("Blockchain is in sync.")
                        print("Latest block: "+str(settings.W3.eth.blockNumber))
                        print("")
                    else:
                        print("Blockchain is syncing... (synced at %.2f%%)" % (settings.W3.eth.syncing.currentBlock/settings.W3.eth.syncing.highestBlock*100.0))
                        print("Latest block: "+str(settings.W3.eth.syncing.currentBlock))
                        print("")
                    connection = http.client.HTTPConnection(settings.RPC_HOST, settings.RPC_PORT)
                except Exception as e:
                    if tries < settings.CONNECTION_RETRIES:
                        print("Retrying to connect to http://"+settings.RPC_HOST+":"+str(settings.RPC_PORT))
                        time.sleep(settings.CONNECTION_RETRY_INTERVAL)
                    else:
                        print(e)
                        return

        if args.extract and args.transaction_hash:
            transactions = []
            try:
                transaction = format_transaction(settings.W3.eth.getTransaction(args.transaction_hash))
                if transaction["to"] and transaction["gas"] > 21000:
                    transactions.append(transaction)
            except Exception as e:
                print(e)
                print("Error: Blockchain is not in sync with transaction: "+args.transaction_hash)
            extract_facts_from_transactions(connection, transactions, settings.FACTS_FOLDER)

        if args.extract and args.block_number:
            transactions = []
            try:
                block = settings.W3.eth.getBlock(args.block_number)
                for i in block["transactions"]:
                    transaction = format_transaction(settings.W3.eth.getTransaction(i))
                    if transaction["to"] and transaction["gas"] > 21000:
                        transactions.append(transaction)
            except:
                print("Error: Blockchain is not in sync with block number: "+args.block_number[0])
            print("Retrieving "+str(len(transactions))+" transaction(s).\n")
            extract_facts_from_transactions(connection, transactions, settings.FACTS_FOLDER)

        if args.extract and args.contract_address:
            transactions = []
            api_network = "api" if network == "mainnet" else "api-"+network
            # Get the list of "normal" transactions for the given contract address
            page = 1
            while True:
                api_response = requests.get("https://"+api_network+".etherscan.io/api?module=account&action=txlist&address="+args.contract_address+"&startblock=0&endblock="+str(settings.MAX_BLOCK_HEIGHT)+"&page="+str(page)+"&offset=10000&sort=asc&apikey="+settings.ETHERSCAN_API_TOKEN).json()
                if not api_response or "error" in api_response:
                    if "error" in api_response:
                        print("An error occured in retrieving the list of transactions: "+str(api_response["error"]))
                    else:
                        print("An unknown error ocurred in retrieving the list of transactions!")
                elif "result" in api_response:
                    if not api_response["result"] or len(api_response["result"]) == 0:
                        break
                    else:
                        page += 1
                        for result in api_response["result"]:
                            transaction = format_transaction(settings.W3.eth.getTransaction(result["hash"]))
                            if transaction["to"] and transaction["gas"] > 21000:
                                if not is_block_within_ranges(transaction["blockNumber"], settings.DOS_ATTACK_BLOCK_RANGES):
                                    if not transaction in transactions:
                                        transactions.append(transaction)
                else:
                    break
            """# Get the list of "internal" transactions for the given contract address
            page = 1
            while True:
                api_response = requests.get("https://"+api_network+".etherscan.io/api?module=account&action=txlistinternal&address="+args.contract_address+"&startblock=0&endblock="+str(settings.MAX_BLOCK_HEIGHT)+"&page="+str(page)+"&offset=10000&sort=asc&apikey="+settings.ETHERSCAN_API_TOKEN).json()
                if not api_response or "error" in api_response:
                    if "error" in api_response:
                        print("An error occured in retrieving the list of transactions: "+str(api_response["error"]))
                    else:
                        print("An unknown error ocurred in retrieving the list of transactions!")
                elif "result" in api_response:
                    if len(api_response["result"]) == 0:
                        break
                    else:
                        page += 1
                        for result in api_response["result"]:
                            transaction = format_transaction(settings.W3.eth.getTransaction(result["hash"]))
                            if transaction["to"] and transaction["gas"] > 21000:
                                if not is_block_within_ranges(transaction["blockNumber"], settings.DOS_ATTACK_BLOCK_RANGES):
                                    if not transaction in transactions:
                                        transactions.append(transaction)
                else:
                    break
            # Sort the list of transactions
            transactions = sorted(transactions, key=itemgetter('blockNumber', 'transactionIndex'))"""
            #transactions = []
            #transactions.append(format_transaction(settings.W3.eth.getTransaction("0x9dbf0326a03a2a3719c27be4fa69aacc9857fd231a8d9dcaede4bb083def75ec")))
            #transactions.append(format_transaction(settings.W3.eth.getTransaction("0xeef10fc5170f669b86c4cd0444882a96087221325f8bf2f55d6188633aa7be7c")))
            #transactions.append(format_transaction(settings.W3.eth.getTransaction("0x05f71e1b2cb4f03e547739db15d080fd30c989eda04d37ce6264c5686e0722c9")))
            #transactions.append(format_transaction(settings.W3.eth.getTransaction("0x47f7cff7a5e671884629c93b368cb18f58a993f4b19c2a53a8662e3f1482f690")))
            print("Retrieving "+str(len(transactions))+" transaction(s).\n")
            extract_facts_from_transactions(connection, transactions, settings.FACTS_FOLDER)

        if args.analyze:
            if os.path.isdir(settings.RESULTS_FOLDER):
                shutil.rmtree(settings.RESULTS_FOLDER)
            if not os.path.isdir(settings.RESULTS_FOLDER):
                os.mkdir(settings.RESULTS_FOLDER)
            analysis_time = analyze_facts(settings.FACTS_FOLDER, settings.RESULTS_FOLDER, settings.DATALOG_FILE)
            print("Analyzing facts took %.2f second(s)." % (analysis_time))

        print("")
    except argparse.ArgumentTypeError as e:
        print(e)
    except Exception:
        traceback.print_exc()
        print(args)
    finally:
        if connection:
            connection.close()
            print("Connection closed.")

    execution_end = time.time()
    execution_delta = execution_end - execution_begin
    print("Overall execution took %.2f second(s)." % execution_delta)

if __name__ == '__main__':
    main()
