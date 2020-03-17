#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class CallFlowAnalysis:
    def __init__(self, transaction):
        self.call_stack = []
        self.call_stack.append(transaction["to"])

    def analyze_call_flow(self, step, trace):
        if step < len(trace)-1:
            if trace[step]["depth"] < trace[step+1]["depth"]:
                if trace[step]["op"] in ["CALL", "STATICCALL", "DELEGATECALL", "CREATE"]:
                    self.call_stack.append(hex(int(trace[step]["stack"][-2], 16)))
            if trace[step]["depth"] > trace[step+1]["depth"]:
                self.call_stack.pop()
