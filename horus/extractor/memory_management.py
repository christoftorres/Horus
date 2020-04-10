#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from eth.vm.memory import Memory
from eth.validation import validate_uint256
from eth._utils.address import force_bytes_to_address

from utils.utils import *
from utils import settings

class MemoryManager:
    def __init__(self, transaction):
        self.call_stack = []
        self.call_stack.append({"memory": Memory(), "data": bytes.fromhex(transaction["input"].replace('0x', '')), "code": b'', "output": b''})

    def manage_memory(self, trace, step, transaction):
        if len(self.call_stack) > int(trace[step]["depth"]):
            self.call_stack.pop()

        if trace[step]["op"] == "CALLDATACOPY":
            mem_start_position = int(trace[step]["stack"][-1], 16)
            calldata_start_position = int(trace[step]["stack"][-2], 16)
            size = int(trace[step]["stack"][-3], 16)
            self.extend_memory(mem_start_position, size)
            value = self.call_stack[-1]["data"][
                calldata_start_position: calldata_start_position + size
            ]
            padded_value = value.ljust(size, b'\x00')
            self.memory_write(mem_start_position, size, padded_value)

        elif trace[step]["op"] == "CODECOPY":
            mem_start_position = int(trace[step]["stack"][-1], 16)
            code_start_position = int(trace[step]["stack"][-2], 16)
            size = int(trace[step]["stack"][-3], 16)
            self.extend_memory(mem_start_position, size)
            code = self.call_stack[-1]["code"]
            code_bytes = code[code_start_position:code_start_position + size]
            padded_code_bytes = code_bytes.ljust(size, b'\x00')
            self.memory_write(mem_start_position, size, padded_code_bytes)

        elif trace[step]["op"] == "EXTCODECOPY":
            account = force_bytes_to_address(bytes.fromhex(trace[step]["stack"][-1]))
            mem_start_position = int(trace[step]["stack"][-2], 16)
            code_start_position = int(trace[step]["stack"][-3], 16)
            size = int(trace[step]["stack"][-4], 16)
            self.extend_memory(mem_start_position, size)
            code = settings.W3.eth.getCode(settings.W3.toChecksumAddress(account), transaction["blockNumber"]-1)
            code_bytes = code[code_start_position:code_start_position + size]
            padded_code_bytes = code_bytes.ljust(size, b'\x00')
            self.memory_write(mem_start_position, size, padded_code_bytes)

        elif trace[step]["op"] == "RETURNDATACOPY":
            mem_start_position = int(trace[step]["stack"][-1], 16)
            returndata_start_position = int(trace[step]["stack"][-2], 16)
            size = int(trace[step]["stack"][-3], 16)
            self.extend_memory(mem_start_position, size)
            value = self.call_stack[-1]["output"][returndata_start_position: returndata_start_position + size]
            self.memory_write(mem_start_position, size, value)
            
        elif trace[step]["op"] == "MSTORE":
            start_position = int(trace[step]["stack"][-1], 16)
            value = bytes.fromhex(trace[step]["stack"][-2])
            padded_value = value.rjust(32, b'\x00')
            normalized_value = padded_value[-32:]
            self.extend_memory(start_position, 32)
            self.memory_write(start_position, 32, normalized_value)

        elif trace[step]["op"] == "MSTORE8":
            start_position = int(trace[step]["stack"][-1], 16)
            value = bytes.fromhex(trace[step]["stack"][-2])
            padded_value = value.rjust(1, b'\x00')
            normalized_value = padded_value[-1:]
            self.extend_memory(start_position, 1)
            self.memory_write(start_position, 1, normalized_value)

        elif trace[step]["op"] == "RETURN":
            start_position = int(trace[step]["stack"][-1], 16)
            size = int(trace[step]["stack"][-2], 16)
            self.extend_memory(start_position, size)
            output = self.memory_read_bytes(start_position, size)
            if len(self.call_stack) > 1:
                self.call_stack[-2]["output"] = output

        elif trace[step]["op"] == "CREATE":
            offset = int(trace[step]["stack"][-2], 16)
            size = int(trace[step]["stack"][-3], 16)
            call_data = self.memory_read_bytes(offset, size)
            code = call_data
            self.call_stack.append({"memory": Memory(), "data": call_data, "code": code, "output": b''})

        elif trace[step]["op"] in ["CALL", "CALLCODE"]:
            to = normalize_32_byte_hex_address(trace[step]["stack"][-2])
            offset = int(trace[step]["stack"][-4], 16)
            size = int(trace[step]["stack"][-5], 16)
            call_data = self.memory_read_bytes(offset, size)
            code = settings.W3.eth.getCode(settings.W3.toChecksumAddress(to), transaction["blockNumber"]-1)
            self.call_stack.append({"memory": Memory(), "data": call_data, "code": code, "output": b''})

        elif trace[step]["op"] in ["DELEGATECALL", "STATICCALL"]:
            to = normalize_32_byte_hex_address(trace[step]["stack"][-2])
            offset = int(trace[step]["stack"][-3], 16)
            size = int(trace[step]["stack"][-4], 16)
            call_data = self.memory_read_bytes(offset, size)
            code = settings.W3.eth.getCode(settings.W3.toChecksumAddress(to), transaction["blockNumber"]-1)
            self.call_stack.append({"memory": Memory(), "data": call_data, "code": code, "output": b''})

    #
    # Memory Management
    #
    def extend_memory(self, start_position: int, size: int) -> None:
        validate_uint256(start_position, title="Memory start position")
        validate_uint256(size, title="Memory size")
        if size:
            self.call_stack[-1]["memory"].extend(start_position, size)

    def memory_write(self, start_position: int, size: int, value: bytes) -> None:
        return self.call_stack[-1]["memory"].write(start_position, size, value)

    def memory_read_bytes(self, start_position: int, size: int) -> bytes:
        return self.call_stack[-1]["memory"].read_bytes(start_position, size)
