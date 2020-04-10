#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import copy
import json
import traceback
import collections

def print_stack(stack):
    string = "["
    for element in stack:
        if element != False:
            string += " " + str(element) + " "
        else:
            string += " False "
    string += "]"
    print(string)

def print_memory(memory):
    sorted_memory = collections.OrderedDict(sorted(memory.items()))
    for address in sorted_memory:
        print(str(address) + ": " + str(sorted_memory[address]))

def print_storage(storage):
    for address in storage:
        print(str(address) + ": {")
        for index in storage[address].keys():
            print("\t" + str(index) + ": " + str(storage[address][index]))
        print("}")

class TaintRecord:
    def __init__(self, input={}, value=False, output=None, address=None):
        """ Builds a taint record """
        # Execution environment
        self.input = input
        self.value = value
        self.output = output
        self.address = address
        # Machine state
        self.stack = []
        self.memory = {}

    def __str__(self):
        return json.dumps(self.__dict__)

    def input_tainted(self):
        """ Returns taint value of input data"""
        return self.input

    def value_tainted(self):
        """ Returns taint value of message value"""
        return self.value

    def stack_tainted(self, index):
        """ Returns taint value of stack element at index"""
        if index < len(self.stack):
            return self.stack[index]
        return False

    def memory_tainted(self, index):
        """ Returns taint value of memory element at index"""
        if index in self.memory.keys():
            return self.memory[index]
        return False

    def clone(self):
        """ Clones this record"""
        clone = TaintRecord()
        clone.input   = self.input
        clone.value   = self.value
        clone.output  = self.output
        clone.address = self.address
        clone.stack   = self.stack
        clone.memory  = self.memory
        return clone

class TaintRunner:
    def __init__(self):
        # Machine state
        self.call_stack = []
        # World state
        self.storage = {}

    def propagate_taint(self, instruction, contract):
        try:
            if not "error" in instruction:
                if len(self.call_stack) < instruction["depth"]:
                    self.call_stack.append([])

                records = self.call_stack[instruction["depth"]-1]

                if len(records) == 0:
                    previous_records = self.call_stack[instruction["depth"]-2]
                    if len(previous_records) > 0:
                        previous_record = previous_records[-1]
                        records.append(TaintRecord(input=previous_record.input, value=previous_record.value, output=previous_record.output, address=contract))
                    else:
                        records.append(TaintRecord(address=contract))

                new_record = TaintRunner.execute_trace(records[-1], self.storage, instruction)
                #print_stack(new_record.stack)
                records.append(new_record)

                if len(self.call_stack) > instruction["depth"]:
                    del self.call_stack[-1]
        except:
            traceback.print_exc()

    def introduce_taint(self, taint, instruction):
        try:
            if not "error" in instruction:
                records = self.call_stack[instruction["depth"] - 1]

                mutator = TaintRunner.stack_taint_table[instruction["op"]]
                for i in range(1, mutator[1] + 1):
                    if not records[-1].stack[-i]:
                        records[-1].stack[-i] = [taint]
                    else:
                        record = copy.deepcopy(records[-1].stack[-i])
                        record = [taint]
                        records[-1].stack[-i] = record
                if instruction["op"] == "CALL":
                    if not records[-1].output:
                        records[-1].output = []
                    records[-1].output += [taint]
                elif instruction["op"] == "CALLDATACOPY":
                    records[-1].memory[instruction["stack"][-1]] = []
                    records[-1].memory[instruction["stack"][-1]].append(taint)
        except:
            traceback.print_exc()

    def check_taint(self, instruction):
        values = []
        try:
            if not "error" in instruction:
                records = self.call_stack[instruction["depth"]-1]
                mutator = TaintRunner.stack_taint_table[instruction["op"]]
                if instruction["op"].startswith("DUP") or instruction["op"].startswith("SWAP"):
                    stack = records[-2].stack[-mutator[0]]
                    if stack:
                        values += stack
                else:
                    if instruction["op"].startswith("LOG") or instruction["op"] == "SHA3":
                        memory = TaintRunner.extract_taint_from_memory(records[-2].memory, int(instruction["stack"][-1], 16), int(instruction["stack"][-2], 16))
                        if memory:
                            values += memory
                    if instruction["op"] == "CALL":
                        memory = TaintRunner.extract_taint_from_memory(records[-2].memory, int(instruction["stack"][-4], 16), int(instruction["stack"][-5], 16))
                        if memory:
                            values += memory
                    for i in range(0, mutator[0]):
                        stack = records[-2].stack[-(i+1)]
                        if stack:
                            values += stack
        except:
            traceback.print_exc()
        return values

    def clear_machine_state(self):
        self.call_stack = []

    @staticmethod
    def execute_trace(record, storage, instruction):
        assert len(record.stack) == len(instruction["stack"])

        new_record = record.clone()
        # Apply Change
        op = instruction["op"]

        if op.startswith("PUSH"):
            TaintRunner.mutate_push(new_record)
        elif op.startswith("DUP"):
            TaintRunner.mutate_dup(new_record, op)
        elif op.startswith("SWAP"):
            TaintRunner.mutate_swap(new_record, op)
        elif op == "MLOAD":
            TaintRunner.mutate_mload(new_record, instruction)
        elif op.startswith("MSTORE"):
            TaintRunner.mutate_mstore(new_record, instruction)
        elif op == "SLOAD":
            TaintRunner.mutate_sload(new_record, storage, instruction)
        elif op == "SSTORE":
            TaintRunner.mutate_sstore(new_record, storage, instruction)
        elif op.startswith("LOG"):
            TaintRunner.mutate_log(new_record, op)
        elif op == "SHA3":
            TaintRunner.mutate_sha3(new_record, instruction)
        elif op == "CALLVALUE":
            TaintRunner.mutate_call_value(new_record, instruction)
        elif op in ("CALLDATACOPY", "CODECOPY", "RETURNDATACOPY", "EXTCODECOPY"):
            TaintRunner.mutate_copy(new_record, op, instruction)
        elif op in ("CALL", "CALLCODE", "DELEGATECALL", "STATICCALL"):
            TaintRunner.mutate_call(new_record, op, instruction)
        elif op == "RETURNDATASIZE":
            TaintRunner.mutate_return_data_size(new_record, op, instruction)
        elif op in TaintRunner.stack_taint_table.keys():
            mutator = TaintRunner.stack_taint_table[op]
            TaintRunner.mutate_stack(new_record, mutator)
        else:
            if settings.DEBUG_MODE:
                print("Unknown operation encountered: {}".format(op))

        return new_record

    @staticmethod
    def mutate_stack(record, mutator):
        taint = False
        for i in range(mutator[0]):
            values = record.stack.pop()
            if values:
                if taint == False:
                    taint = []
                for j in range(len(values)):
                    if not values[j] in taint:
                        taint.append(values[j])
        for i in range(mutator[1]):
            record.stack.append(taint)

    @staticmethod
    def mutate_push(record):
        TaintRunner.mutate_stack(record, (0, 1))

    @staticmethod
    def mutate_dup(record, op):
        depth = int(op[3:])
        index = len(record.stack) - depth
        record.stack.append(record.stack[index])

    @staticmethod
    def mutate_swap(record, op):
        depth = int(op[4:])
        l = len(record.stack) - 1
        i = l - depth
        record.stack[l], record.stack[i] = record.stack[i], record.stack[l]

    @staticmethod
    def mutate_mload(record, instruction):
        record.stack.pop()
        index = instruction["stack"][-1]
        record.stack.append(record.memory_tainted(index))

    @staticmethod
    def mutate_mstore(record, instruction):
        record.stack.pop()
        index, value = instruction["stack"][-1], record.stack.pop()
        record.memory[index] = value

    @staticmethod
    def mutate_sload(record, storage, instruction):
        record.stack.pop()
        taint = False
        index = instruction["stack"][-1]
        if record.address in storage and index in storage[record.address].keys() and storage[record.address][index]:
            taint = storage[record.address][index]
        record.stack.append(taint)

    @staticmethod
    def mutate_sstore(record, storage, instruction):
        record.stack.pop()
        index, taint = instruction["stack"][-1], record.stack.pop()
        if not record.address in storage:
            storage[record.address] = {}
        if taint:
            taint = list(dict.fromkeys(taint))
        storage[record.address][index] = taint

    @staticmethod
    def mutate_log(record, op):
        depth = int(op[3:])
        for _ in range(depth + 2):
            record.stack.pop()

    @staticmethod
    def mutate_sha3(record, instruction):
        record.stack.pop()
        offset = int(instruction["stack"][-1], 16)
        record.stack.pop()
        size = int(instruction["stack"][-2], 16)
        value = TaintRunner.extract_taint_from_memory(record.memory, offset, size)
        record.stack.append(value)

    @staticmethod
    def mutate_call_data_load(record, instruction):
        record.stack.pop()
        taint = False
        if record.input:
            if instruction["stack"][-1] in record.input:
                taint = record.input[instruction["stack"][-1]]
        record.stack.append(taint)

    @staticmethod
    def mutate_call_value(record, instruction):
        record.stack.append(record.value)

    @staticmethod
    def mutate_copy(record, op, instruction):
        if op == "EXTCODECOPY":
            record.stack.pop()
            index = instruction["stack"][-2]
        else:
            index = instruction["stack"][-1]
        record.stack.pop()
        record.stack.pop()
        record.memory[index] = record.stack.pop()

    @staticmethod
    def mutate_create(record, instruction):
        value = record.stack.pop()
        offset = int(instruction["stack"][-1], 16)
        record.stack.pop()
        size = int(instruction["stack"][-2], 16)
        record.stack.pop()
        taint = TaintRunner.extract_taint_from_memory(record.memory, offset, size)
        if value and not taint:
            taint = []
        if value:
            taint += value
        record.stack.append(taint)

    @staticmethod
    def mutate_call(record, op, instruction):
        taint = False
        record.stack.pop()
        record.stack.pop()
        if op in ["CALL", "CALLCODE"]:
            record.stack.pop()
        record.stack.pop()
        record.stack.pop()
        record.stack.pop()
        record.stack.pop()
        record.stack.append(taint)

    @staticmethod
    def mutate_return_data_size(record, op, instruction):
        record.stack.append(record.output)

    @staticmethod
    def extract_taint_from_memory(memory, offset, size):
        taint = []
        length = int(size / 32)
        for i in range(length):
            index = hex(offset + i * 32).replace("0x", "").zfill(64)
            if index in memory:
                if memory[index]:
                    for k in memory[index]:
                        if not k in taint:
                            taint.append(k)
            keys = list(memory.keys())
            for j in range(len(keys)):
                if offset < int(keys[j], 16) and int(keys[j], 16) < offset + 32:
                    if memory[keys[j]]:
                        for k in memory[keys[j]]:
                            if not k in taint:
                                taint.append(k)
        if not taint:
            taint = False
        return taint

    stack_taint_table = {
        # instruction: (taint source, taint target)
        # 0s: Stop and Arithmetic Operations
        'STOP': (0, 0),
        'ADD': (2, 1),
        'MUL': (2, 1),
        'SUB': (2, 1),
        'DIV': (2, 1),
        'SDIV': (2, 1),
        'MOD': (2, 1),
        'SMOD': (2, 1),
        'ADDMOD': (3, 1),
        'MULMOD': (3, 1),
        'EXP': (2, 1),
        'SIGNEXTEND': (2, 1),
        # 10s: Comparison & Bitwise Logic Operations
        'LT': (2, 1),
        'GT': (2, 1),
        'SLT': (2, 1),
        'SGT': (2, 1),
        'EQ': (2, 1),
        'ISZERO': (1, 1),
        'AND': (2, 1),
        'OR': (2, 1),
        'XOR': (2, 1),
        'NOT': (1, 1),
        'BYTE': (2, 1),
        'SHL': (2, 1),
        'SHR': (2, 1),
        'SAR': (2, 1),
        # 20s: SHA3
        'SHA3': (2, 1),
        # 30s: Environmental Information
        'ADDRESS': (0, 1),
        'BALANCE': (1, 1),
        'ORIGIN': (0, 1),
        'CALLER': (0, 1),
        'CALLVALUE': (0, 1),
        'CALLDATALOAD': (1, 1),
        'CALLDATASIZE': (0, 1),
        'CALLDATACOPY': (3, 0),
        'CODESIZE': (0, 1),
        'CODECOPY': (3, 0),
        'GASPRICE': (0, 1),
        'EXTCODESIZE': (1, 1),
        'EXTCODECOPY': (4, 0),
        'RETURNDATASIZE': (0, 1),
        'RETURNDATACOPY': (3, 0),
        'EXTCODEHASH': (1, 1),
        # 40s: Block Information
        'BLOCKHASH': (1, 1),
        'COINBASE': (0, 1),
        'TIMESTAMP': (0, 1),
        'NUMBER': (0, 1),
        'DIFFICULTY': (0, 1),
        'GASLIMIT': (0, 1),
        # 50s: Stack, Memory, Storage and Flow Operations
        'POP': (1, 0),
        'MLOAD': (1, 1),
        'MSTORE': (2, 0),
        'MSTORE8': (2, 0),
        'SLOAD': (1, 1),
        'SSTORE': (2, 0),
        'JUMP': (1, 0),
        'JUMPI': (2, 0),
        'PC': (0, 1),
        'MSIZE': (0, 1),
        'GAS': (0, 1),
        'JUMPDEST': (0, 0),
        # 60s & 70s: Push Operations
        'PUSH1': (0, 1),
        'PUSH2': (0, 1),
        'PUSH3': (0, 1),
        'PUSH4': (0, 1),
        'PUSH5': (0, 1),
        'PUSH6': (0, 1),
        'PUSH7': (0, 1),
        'PUSH8': (0, 1),
        'PUSH9': (0, 1),
        'PUSH10': (0, 1),
        'PUSH11': (0, 1),
        'PUSH12': (0, 1),
        'PUSH13': (0, 1),
        'PUSH14': (0, 1),
        'PUSH15': (0, 1),
        'PUSH16': (0, 1),
        'PUSH17': (0, 1),
        'PUSH18': (0, 1),
        'PUSH19': (0, 1),
        'PUSH20': (0, 1),
        'PUSH21': (0, 1),
        'PUSH22': (0, 1),
        'PUSH23': (0, 1),
        'PUSH24': (0, 1),
        'PUSH25': (0, 1),
        'PUSH26': (0, 1),
        'PUSH27': (0, 1),
        'PUSH28': (0, 1),
        'PUSH29': (0, 1),
        'PUSH30': (0, 1),
        'PUSH31': (0, 1),
        'PUSH32': (0, 1),
        # 80s: Duplication Operations
        'DUP1': (1, 2),
        'DUP2': (2, 3),
        'DUP3': (3, 4),
        'DUP4': (4, 5),
        'DUP5': (5, 6),
        'DUP6': (6, 7),
        'DUP7': (7, 8),
        'DUP8': (8, 9),
        'DUP9': (9, 10),
        'DUP10': (10, 11),
        'DUP11': (11, 12),
        'DUP12': (12, 13),
        'DUP13': (13, 14),
        'DUP14': (14, 15),
        'DUP15': (15, 16),
        'DUP16': (16, 17),
        # 90s: Exchange Operations
        'SWAP1': (2, 2),
        'SWAP2': (3, 3),
        'SWAP3': (4, 4),
        'SWAP4': (5, 5),
        'SWAP5': (6, 6),
        'SWAP6': (7, 7),
        'SWAP7': (8, 8),
        'SWAP8': (9, 9),
        'SWAP9': (10, 10),
        'SWAP10': (11, 11),
        'SWAP11': (12, 12),
        'SWAP12': (13, 13),
        'SWAP13': (14, 14),
        'SWAP14': (15, 15),
        'SWAP15': (16, 16),
        'SWAP16': (17, 17),
        # a0s: Logging Operations
        'LOG0': (2, 0),
        'LOG1': (3, 0),
        'LOG2': (4, 0),
        'LOG3': (5, 0),
        'LOG4': (6, 0),
        # f0s: System Operations
        'CREATE': (3, 1),
        'CREATE2': (3, 1),
        'CALL': (7, 1),
        'CALLCODE': (7, 1),
        'RETURN': (2, 0),
        'DELEGATECALL': (6, 1),
        'STATICCALL': (6, 1),
        'REVERT': (2, 0),
        'INVALID': (0, 0),
        'SELFDESTRUCT': (1, 0)
    }
