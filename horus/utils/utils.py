
import http
import json
import time
import eth_utils

from sys import getsizeof
from collections import Mapping, Container

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
    return eth_utils.to_normalized_address(as_bytes[-20:])

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

def request_debug_trace(connection, request_timeout, request_retry_interval, transaction_hash, disable_stack=False, disable_memory=False, disable_storage=True, retries=0):
    headers = {"Content-Type": "application/json"}
    data = json.dumps({"id": 1, "method": "debug_traceTransaction", "params": [transaction_hash, {"disableStack": disable_stack, "disableMemory": disable_memory, "disableStorage": disable_storage}]})
    tries = 0
    while tries < 3:
        try:
            tries += 1
            connection.request('GET', '/', data, headers)
            connection.sock.settimeout(request_timeout)
            response = connection.getresponse()
            if response.status == 200 and response.reason == "OK":
                data = response.read().decode()
                return json.loads(data)
            return {"error": {"status": response.status, "reason": response.reason, "data": response.read().decode()}}
        except Exception as e:
            if tries < 3:
                print("Retrying retrival of trace "+str(transaction_hash)+" in "+str(request_retry_interval)+" seconds.")
                time.sleep(request_retry_interval)
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
