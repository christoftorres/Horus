#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from utils.utils import normalize_32_byte_hex_address

class CallFlowAnalysis:
    def __init__(self, transaction):
        self.call_stack = []
        self.call_stack.append(transaction["to"])

    def analyze_call_flow(self, step, max_step, trace):
        if step < len(trace)-1:
            if trace[step]["depth"] < trace[step+1]["depth"]:
                if trace[step]["op"] == "CREATE":
                    i = step + 1
                    while i < max_step and trace[step]["depth"] < trace[i]["depth"]:
                        i += 1
                    self.call_stack.append(normalize_32_byte_hex_address(hex(int(trace[i]["stack"][-1], 16))))
                elif trace[step]["op"] in ["CALL", "CALLCODE", "DELEGATECALL", "STATICCALL"]:
                    self.call_stack.append(normalize_32_byte_hex_address(hex(int(trace[step]["stack"][-2], 16))))
            if trace[step]["depth"] > trace[step+1]["depth"]:
                self.call_stack.pop()
