#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re
import sys
import http
import json
import time
import shlex
import eth_utils
import subprocess

from sys import getsizeof
from collections import Mapping, Container

def command_exists(cmd):
    return subprocess.call(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE) == 0

def run_command(cmd):
    FNULL = open(os.devnull, 'w')
    solc_p = subprocess.Popen(shlex.split(cmd), stdout=subprocess.PIPE, stderr=FNULL)
    return solc_p.communicate()[0]

def has_souffle_installed():
    if not command_exists("souffle --version"):
        print("Souffle is missing. Please install souffle and make sure souffle is in the path.")
        return False
    else:
        cmd = "souffle --version"
        out = run_command(cmd).strip()
        version = re.findall(r"Souffle: (\d*.\d*.\d*)", str(out))[0]
        supported_version = '1.7.1'
        if version != supported_version:
            print("You are using souffle version %s. The supported version is %s." % (version, supported_version))
    return True

def serialize_web3_object(object):
    if object.__class__.__name__ == "str":
        return object.lower()
    if object.__class__.__name__ == "HexBytes":
        return object.hex()
    if object.__class__.__name__ == "AttributeDict":
        object = object.__dict__
    if object.__class__.__name__ == "dict":
        dict = {}
        for key in object:
            dict[key] = serialize_web3_object(object[key])
        return dict
    if object.__class__.__name__ == "list":
        list = []
        for element in object:
            list.append(serialize_web3_object(element))
        return list
    return object

def format_transaction(transaction):
    transaction = serialize_web3_object(transaction)
    for key in list(transaction.keys()):
        if key in ["v", "r", "s"]:
            del transaction[key]
    return transaction

def format_block(block):
    block = serialize_web3_object(block)
    for key in list(block.keys()):
        if key in ["logsBloom", "mixHash", "receiptsRoot", "sha3Uncles", "stateRoot", "transactions", "transactionsRoot", "uncles"]:
            del block[key]
    return block

def is_block_within_ranges(block, ranges):
    for range in ranges:
        if range[0] <= block and block <= range[1]:
            return True
    return False

def normalize_32_byte_hex_address(value):
    as_bytes = eth_utils.to_bytes(hexstr=value)
    try:
        return eth_utils.to_normalized_address(as_bytes[-20:])
    except:
        return '0x'+value.replace('0x', '').zfill(40)

def convert_hex_to_int(x):
    if isinstance(x, str) and x.startswith("0x"):
        return int(x, 16)
    if x.__class__.__name__ == "list":
        new_list = []
        for element in x:
            if isinstance(element, str) and element.startswith("0x"):
                new_list.append(int(element, 16))
            else:
                new_list.append(element)
        return new_list
    return x

def request_debug_trace_transaction(connection, connection_retries, rpc_host, rpc_port, request_timeout, request_retry_interval, transaction_hash, disable_stack=False, disable_memory=True, disable_storage=True):
    data, tracer = None, None
    with open(os.path.dirname(os.path.realpath(sys.argv[0]))+'/extractor/evm_tracing.js', 'r') as file:
        tracer = file.read().replace('\n', '')
    if tracer:
        data = json.dumps({"id": 1, "method": "debug_traceTransaction", "params": [transaction_hash, {"tracer": tracer, "timeout": str(request_timeout)+"s"}]})
    else:
        data = json.dumps({"id": 1, "method": "debug_traceTransaction", "params": [transaction_hash, {"disableStack": disable_stack, "disableMemory": disable_memory, "disableStorage": disable_storage}]})
    tries = 0
    headers = {"Content-Type": "application/json"}
    while tries < connection_retries:
        try:
            tries += 1
            connection.request('GET', '/', data, headers)
            response = connection.getresponse()
            if response.status == 200 and response.reason == "OK":
                return json.loads(response.read())
            return {"error": {"status": response.status, "reason": response.reason, "data": response.read().decode()}}
        except Exception as e:
            connection.close()
            print("Exception: "+str(e))
            if tries < connection_retries:
                print("Retrying retrival of transaction trace "+str(transaction_hash)+" in "+str(request_retry_interval)+" seconds.")
                time.sleep(request_retry_interval)
                connection = http.client.HTTPConnection(rpc_host, rpc_port)
            else:
                return {"error": e}

def request_debug_trace_block(connection, connection_retries, rpc_host, rpc_port, request_timeout, request_retry_interval, block_number, disable_stack=False, disable_memory=True, disable_storage=True):
    data, tracer = None, None
    with open(os.path.dirname(os.path.realpath(sys.argv[0]))+'/extractor/evm_tracing.js', 'r') as file:
        tracer = file.read().replace('\n', '')
    if tracer:
        data = json.dumps({"id": 1, "method": "debug_traceBlockByNumber", "params": [hex(block_number), {"tracer": tracer, "timeout": str(request_timeout)+"s"}]})
    else:
        data = json.dumps({"id": 1, "method": "debug_traceBlockByNumber", "params": [hex(block_number), {"disableStack": disable_stack, "disableMemory": disable_memory, "disableStorage": disable_storage}]})
    tries = 0
    headers = {"Content-Type": "application/json"}
    while tries < connection_retries:
        try:
            tries += 1
            connection.request('GET', '/', data, headers)
            response = connection.getresponse()
            if response.status == 200 and response.reason == "OK":
                return json.loads(response.read())
            return {"error": {"status": response.status, "reason": response.reason, "data": response.read().decode()}}
        except Exception as e:
            connection.close()
            print("Exception: "+str(e))
            if tries < connection_retries:
                print("Retrying retrival of block trace "+str(block_number)+" in "+str(request_retry_interval)+" seconds.")
                time.sleep(request_retry_interval)
                connection = http.client.HTTPConnection(rpc_host, rpc_port)
            else:
                return {"error": e}

def deep_getsizeof(o, ids):
    """Find the memory footprint of a Python object
    This is a recursive function that rills down a Python object graph
    like a dictionary holding nested ditionaries with lists of lists
    and tuples and sets.
    The sys.getsizeof function does a shallow size of only. It counts each
    object inside a container as pointer only regardless of how big it
    really is.
    :param o: the object
    :param ids:
    :return:
    """
    d = deep_getsizeof
    if id(o) in ids:
        return 0

    r = getsizeof(o)
    ids.add(id(o))

    if isinstance(o, str):
        return r

    if isinstance(o, Mapping):
        return r + sum(d(k, ids) + d(v, ids) for k, v in o.items())

    if isinstance(o, Container):
        return r + sum(d(x, ids) for x in o)

    return r
