#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from utils.utils import normalize_32_byte_hex_address

class CallFlowAnalysis:
    def __init__(self, transaction):
        self.call_stack = []
        self.call_id = -1
        self.call_branch = -1
        self.call_stack.append(transaction["to"])

    def get_caller(self):
        return self.call_stack[-1]

    def get_call_id(self):
        return self.call_id

    def get_call_branch(self):
        return self.call_branch

    def analyze_call_flow(self, step, max_step, trace):
        if step < len(trace)-1:
            # Handle call braches
            if len(self.call_stack) - trace[step]["depth"] > 1:
                self.call_branch += 1
            elif trace[step]["depth"] == 1:
                self.call_branch += 1

            # Handle call stack
            if trace[step]["depth"] < trace[step+1]["depth"]:
                if trace[step]["op"] in ["CREATE", "CREATE2"]:
                    i = step + 1
                    while i < max_step and trace[step]["depth"] < trace[i]["depth"]:
                        i += 1
                    self.call_stack.append(normalize_32_byte_hex_address(hex(int(trace[i]["stack"][-1], 16))))
                elif trace[step]["op"] in ["CALL", "CALLCODE", "DELEGATECALL", "STATICCALL"]:
                    self.call_stack.append(normalize_32_byte_hex_address(hex(int(trace[step]["stack"][-2], 16))))
            while trace[step]["depth"] < len(self.call_stack):
                self.call_stack.pop()

            # Handle call ids
            if len(self.call_stack) == 1:
                self.call_id += 1
