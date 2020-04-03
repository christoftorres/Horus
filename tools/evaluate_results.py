#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import math
import json
import shutil
import zipfile
import traceback

from pymongo import MongoClient

FOLDER = "/Users/christof.torres/Git/Horus/evaluation/blockchain/4500000/"

def mean(x):
    return sum(x) / len(x)

def median(x):
    sorted_x = sorted(x)
    length_n = len(x)
    middle = length_n // 2
    if length_n % 2 == 0:
        median_even = (sorted_x[middle - 1] + sorted_x[middle]) / 2
        return(median_even)
    else:
        return(sorted_x[middle])

def variance(x):
     n = len(x)
     x_bar = mean(x)
     return(round(sum((x_i - x_bar)**2 for x_i in x) / (n - 1), 2))

def standard_deviation(x):
     return(math.sqrt(variance(x)))

print("Evaluating results...")

contracts = 0
transactions = []
execution_times = []
retrieval_times = []
patterns = {}

reentrancy_contracts = []
reentrancy_transactions = []

cross_function_reentrancy = []
delegated_reentrancy = []
create_based_reentrancy = []
unchecked_send = []
transaction_order_dependence = []
block_state_dependence = []
timestamp_dependence = []
transaction_state_dependence = []
call_stack_depth = []
integer_overflow_addition = []
integer_overflow_multiplication = []
integer_underflow = []
dos_with_unexpected_throw = []
dos_with_block_gas_limit = []
short_address = []
unchecked_suicide = []
unchecked_delegatecall = []

total = set()

client = MongoClient('mongodb://localhost:27017/')

if __name__ == '__main__':
    with zipfile.ZipFile(FOLDER+"results_new.zip") as z:
    #with zipfile.ZipFile(FOLDER+"results_old.zip") as z:
        for filename in z.namelist():
            if filename.endswith(".json"):
                with z.open(filename) as f:
                    try:
                        data = json.loads(f.read().decode("utf-8"))
                        transactions.append(len(data))
                        contracts += 1
                        for result in data:
                            execution_times.append(result["execution_time"])
                            #retrieval_times.append(result["retrieval_time"])
                            for pattern in result["patterns"]:
                                if pattern["contract"]:
                                    if pattern["description"] == "Reentrancy":
                                        if not pattern["contract"] in reentrancy_contracts:
                                            reentrancy_contracts.append(pattern["contract"])
                                            total.add(pattern["contract"])
                                        if not result["transaction"] in reentrancy_transactions:
                                            reentrancy_transactions.append(result["transaction"])
                                    if pattern["description"] == "Cross-Function Reentrancy" and not pattern["contract"] in cross_function_reentrancy:
                                        cross_function_reentrancy.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Delegated Reentrancy" and not pattern["contract"] in delegated_reentrancy:
                                        delegated_reentrancy.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Create-Based Reentrancy" and not pattern["contract"] in create_based_reentrancy:
                                        create_based_reentrancy.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Unchecked Send" and not pattern["contract"] in unchecked_send:
                                        unchecked_send.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Transaction Order Dependence" and not pattern["contract"] in transaction_order_dependence:
                                        transaction_order_dependence.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                        #collection = client["horus"]["source_contracts"]
                                        #document = collection.find_one({'ContractAddress': pattern["contract"]})
                                        #if document and document["SourceCode"]:
                                        #if True:
                                        #    print(result["transaction"])
                                        #    print(pattern["contract"])
                                        #    print(pattern)
                                        #    print("")
                                        #if not os.path.isfile(FOLDER+filename):
                                        #    z.extract(filename, FOLDER)
                                    if pattern["description"] == "Block State Dependence" and not pattern["contract"] in block_state_dependence:
                                        block_state_dependence.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Timestamp Dependence" and not pattern["contract"] in timestamp_dependence:
                                        timestamp_dependence.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    #    collection = client["horus"]["source_contracts"]
                                    #    document = collection.find_one({'ContractAddress': pattern["contract"]})
                                    #    if document and document["SourceCode"]:
                                    #        print(pattern["contract"])
                                    #        print(result["transaction"])
                                    #        print("")
                                    if pattern["description"] == "Transaction State Dependence" and not pattern["contract"] in transaction_state_dependence:
                                        transaction_state_dependence.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                        collection = client["horus"]["source_contracts"]
                                        document = collection.find_one({'ContractAddress': pattern["contract"]})
                                        #if document and document["SourceCode"]:
                                        if True:
                                            print(pattern["contract"])
                                            print(result["transaction"])
                                            print("")
                                    if pattern["description"] == "Call Stack Depth" and not pattern["contract"] in call_stack_depth:
                                        call_stack_depth.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Integer Overflow (Addition)" and not pattern["contract"] in integer_overflow_addition:
                                        integer_overflow_addition.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Integer Overflow (Multiplication)" and not pattern["contract"] in integer_overflow_multiplication:
                                        integer_overflow_multiplication.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Integer Underflow" and not pattern["contract"] in integer_underflow:
                                        integer_underflow.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "DoS with Unexpected Throw" and not pattern["contract"] in dos_with_unexpected_throw:
                                        dos_with_unexpected_throw.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "DoS with Block Gas Limit" and not pattern["contract"] in dos_with_block_gas_limit:
                                        dos_with_block_gas_limit.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Short Address" and not pattern["contract"] in short_address:
                                        short_address.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Parity Wallet Hack 1" and not pattern["contract"] in unchecked_delegatecall:
                                        unchecked_delegatecall.append(pattern["contract"])
                                        total.add(pattern["contract"])
                                    if pattern["description"] == "Parity Wallet Hack 2" and not pattern["contract"] in unchecked_delegatecall:
                                        unchecked_suicide.append(pattern["contract"])
                                        total.add(pattern["contract"])
                    except Exception as e:
                        print(" --> Exception in: "+filename)
                        print("Reason: "+str(e))
                        traceback.print_exc()
                        pass

    print("")
    print("Number of analyzed contracts: "+str(contracts))
    print("")
    print("Total number of transactions per contract: "+str(sum(transactions)))
    print("Min number of transactions per contract: "+str(min(transactions)))
    print("Mean number of transactions per contract: "+str(mean(transactions)))
    print("Median number of transactions per contract: "+str(median(transactions)))
    print("Max number of transactions per contract: "+str(max(transactions)))
    print("")
    print("Min number of execution time per transaction: "+str(min(execution_times)))
    print("Mean number of execution time per transaction: "+str(mean(execution_times)))
    print("Median number of execution time per transaction: "+str(median(execution_times)))
    print("Max number of execution time per transaction: "+str(max(execution_times)))
    print("")
    #print("Min number of retrieval time per transaction: "+str(min(retrieval_times)))
    #print("Mean number of retrieval time per transaction: "+str(mean(retrieval_times)))
    #print("Median number of retrieval time per transaction: "+str(median(retrieval_times)))
    #print("Max number of retrieval time per transaction: "+str(max(retrieval_times)))
    #print("")
    print("Number of reentrancy vulnerable contracts (transactions): \t "+str(len(reentrancy_contracts))+" ("+str(len(reentrancy_transactions))+")")
    print("Number of cross-function reentrancy vulnerable contracts: \t "+str(len(cross_function_reentrancy)))
    print("Number of delegated reentrancy vulnerable contracts: \t \t "+str(len(delegated_reentrancy)))
    print("Number of create-based reentrancy vulnerable contracts: \t "+str(len(create_based_reentrancy)))
    print("Number of unchecked send vulnerable contracts: \t \t \t "+str(len(unchecked_send)))
    print("Number of transaction order dependence vulnerable contracts: \t "+str(len(transaction_order_dependence)))
    print("Number of block state dependence vulnerable contracts: \t \t "+str(len(block_state_dependence)))
    print("Number of timestamp dependence vulnerable contracts: \t \t "+str(len(timestamp_dependence)))
    print("Number of transaction state dependence vulnerable contracts: \t "+str(len(transaction_state_dependence)))
    print("Number of call stack depth vulnerable contracts: \t \t "+str(len(call_stack_depth)))
    print("Number of integer overflow addition vulnerable contracts: \t "+str(len(integer_overflow_addition)))
    print("Number of integer overflow multiplication vulnerable contracts:  "+str(len(integer_overflow_multiplication)))
    print("Number of integer underflow vulnerable contracts: \t \t "+str(len(integer_underflow)))
    print("Number of DoS with unexpected throw vulnerable contracts: \t "+str(len(dos_with_unexpected_throw)))
    print("Number of DoS with block gas limit vulnerable contracts: \t "+str(len(dos_with_block_gas_limit)))
    print("Number of short address vulnerable contracts: \t \t \t "+str(len(short_address)))
    print("Number of unchecked delegatecall vulnerable contracts: \t \t "+str(len(unchecked_delegatecall)))
    print("Number of unchecked suicide vulnerable contracts: \t \t "+str(len(unchecked_suicide)))
    print("-----------------------------------------------------------------------")
    print("Total number of vulnerable contracts: \t \t \t \t "+str(len(total)))


    """file = open(FOLDER+"results/reentrancy_contracts.txt", "w")
    for address in reentrancy_contracts:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/reentrancy_transactions.txt", "w")
    for transaction in reentrancy_transactions:
        file.write(transaction+"\n")
    file.close()

    file = open(FOLDER+"results/cross_function_reentrancy.txt", "w")
    for address in cross_function_reentrancy:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/delegated_reentrancy.txt", "w")
    for address in delegated_reentrancy:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/create_based_reentrancy.txt", "w")
    for address in create_based_reentrancy:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/unchecked_send.txt", "w")
    for address in unchecked_send:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/transaction_order_dependence.txt", "w")
    for address in transaction_order_dependence:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/block_state_dependence.txt", "w")
    for address in block_state_dependence:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/timestamp_dependence.txt", "w")
    for address in timestamp_dependence:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/transaction_state_dependence.txt", "w")
    for address in transaction_state_dependence:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/call_stack_depth.txt", "w")
    for address in call_stack_depth:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/integer_overflow_addition.txt", "w")
    for address in integer_overflow_addition:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/integer_overflow_multiplication.txt", "w")
    for address in integer_overflow_multiplication:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/integer_underflow.txt", "w")
    for address in integer_underflow:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/dos_with_unexpected_throw.txt", "w")
    for address in dos_with_unexpected_throw:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/dos_with_block_gas_limit.txt", "w")
    for address in dos_with_block_gas_limit:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/short_address.txt", "w")
    for address in short_address:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/unchecked_suicide.txt", "w")
    for address in unchecked_suicide:
        file.write(address+"\n")
    file.close()
    file = open(FOLDER+"results/unchecked_delegatecall.txt", "w")
    for address in unchecked_delegatecall:
        file.write(address+"\n")
    file.close()"""
