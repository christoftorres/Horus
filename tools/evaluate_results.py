#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import math
import csv
import sys
import shutil
import zipfile
import requests

from web3 import Web3

import traceback

FOLDER = "/Users/Christof/Downloads/"

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

#transactions = []
execution_times = []
retrieval_times = []

#reentrancy_transactions = []
transactions = {
    "reentrancy" : set(),
    "unhandled_exception": set(),
    "timestamp_dependence": set(),
    "transaction_order_dependence": set(),
    "transaction_state_dependence": set(),
    "block_state_dependence": set(),
    "unchecked_suicide": set(),
    "parity_wallet_hack_2": set(),
    "insufficient_gas": set()
}

contracts = {
    "reentrancy" : set(),
    "unhandled_exception": set(),
    "timestamp_dependence": set(),
    "transaction_order_dependence": set(),
    "transaction_state_dependence": set(),
    "block_state_dependence": set(),
    "unchecked_suicide": set(),
    "parity_wallet_hack_2": set(),
    "insufficient_gas": set()
}

ether = {
    "reentrancy": [],
    "unhandled_exception": [],
    "timestamp_dependence": [],
    "transaction_order_dependence": [],
    "transaction_state_dependence": [],
    "block_state_dependence": [],
    "unchecked_suicide": [],
    "parity_wallet_hack_2": [],
    "insufficient_gas": []
}

cross_function_reentrancy = []
delegated_reentrancy = []
create_based_reentrancy = []
call_stack_depth = []
integer_overflow_addition = []
integer_overflow_multiplication = []
integer_underflow = []
dos_with_unexpected_throw = []
dos_with_block_gas_limit = []
short_address = []
unchecked_delegatecall = []
parity_wallet_hack_1 = []
unchecked_signature = []
balance_invariant = []

total = set()

if __name__ == '__main__':
    with zipfile.ZipFile(FOLDER+"results.zip") as z:
        for filename in z.namelist():
            #print(filename)
            if filename.endswith(".csv"):
                with z.open(filename) as f:
                    contract = filename.split('/')[-2]
                    csv.field_size_limit(sys.maxsize)
                    from io import StringIO
                    s = StringIO(f.read().decode("utf-8"))
                    reader = csv.reader(s, delimiter='\t')
                    for row in reader:
                        #print(row)
                        attack = os.path.splitext(os.path.basename(filename))[0]
                        #print(attack)
                        if   attack == "CallStackDepth":
                            call_stack_depth.append(contract)
                            total.add(contract)
                        elif attack == "Reentrancy":
                            contracts["reentrancy"].add(contract)
                            transactions["reentrancy"].add(row[0])
                            total.add(contract)
                        elif attack == "CrossFunctionReentrancy":
                            cross_function_reentrancy.append(contract)
                            total.add(contract)
                        elif attack == "DelegatedReentrancy":
                            delegated_reentrancy.append(contract)
                            total.add(contract)
                        elif attack == "CreateBasedReentrancy":
                            create_based_reentrancy.append(contract)
                            total.add(contract)
                        elif attack == "UnhandledException":
                            if contract not in contracts["unhandled_exception"]:
                                print(contract+" "+str(row))
                            #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                            #    if "result" in response and response['result'][0]['SourceCode']:
                            #        print(contract)
                            contracts["unhandled_exception"].add(contract)
                            transactions["unhandled_exception"].add(row[0])
                            ether["unhandled_exception"].append(int(row[4]))
                            total.add(contract)
                        elif attack == "IntegerOverflow":
                            if   row[2] == "ADD":
                                integer_overflow_addition.append(contract)
                                total.add(contract)
                            elif row[2] == "MUL":
                                integer_overflow_multiplication.append(contract)
                                total.add(contract)
                        elif attack == "IntegerUnderflow":
                            integer_underflow.append(contract)
                            total.add(contract)
                        elif attack == "TransactionOrderDependency":
                            #if contract not in contracts["transaction_order_dependence"]:
                            #    print(contract+" "+str(row))
                            #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                            #    if "result" in response and response['result'][0]['SourceCode']:
                            #        print(contract)
                            contracts["transaction_order_dependence"].add(contract)
                            transactions["transaction_order_dependence"].add(row[0])
                            total.add(contract)
                        elif attack == "UncheckedSuicide":
                            #if contract not in contracts["unchecked_suicide"]:
                            #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                            #    if "result" in response and response['result'][0]['SourceCode']:
                            #        print(contract)
                            #    print(contract+" "+str(row))
                            #        print(response['result'][0]['SourceCode'])
                            contracts["unchecked_suicide"].add(contract)
                            transactions["unchecked_suicide"].add(row[0])
                            total.add(contract)
                        elif attack == "UncheckedDelegatecall":
                            unchecked_delegatecall.append(contract)
                            total.add(contract)
                        elif attack == "ParityWalletHack1":
                            parity_wallet_hack_1.append(contract)
                            total.add(contract)
                        elif attack == "ParityWalletHack2":
                            #if contract not in contracts["parity_wallet_hack_2"]:
                            #    print(contract+" "+str(row))
                            #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                            #    if "result" in response and response['result'][0]['SourceCode']:
                            #        print(contract)
                            contracts["parity_wallet_hack_2"].add(contract)
                            transactions["parity_wallet_hack_2"].add(row[0])
                            total.add(contract)
                        elif attack == "ShortAddress":
                            short_address.append(contract)
                            total.add(contract)
                        elif attack == "DoSWithUnexpectedThrow":
                            dos_with_unexpected_throw.append(contract)
                            total.add(contract)
                        elif attack == "DoSWithBlockGasLimit":
                            dos_with_block_gas_limit.append(contract)
                            total.add(contract)
                        elif attack == "TimestampDependence":
                            #if contract not in contracts["timestamp_dependence"]:
                            #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                            #    if "result" in response and response['result'][0]['SourceCode']:
                            #        print(contract)
                            #        print(contract+" "+row[0]+" "+str(row[4]))
                            contracts["timestamp_dependence"].add(contract)
                            transactions["timestamp_dependence"].add(row[0])
                            ether["timestamp_dependence"].append(int(row[4]))
                            total.add(contract)
                        elif attack == "TransactionStateDependence":
                            #if contract not in contracts["transaction_state_dependence"]:
                            #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                            #    if "result" in response and response['result'][0]['SourceCode']:
                            #        print(contract)
                            #        print(contract+" "+row[0]+" "+str(row[4]))
                            contracts["transaction_state_dependence"].add(contract)
                            transactions["transaction_state_dependence"].add(row[0])
                            ether["transaction_state_dependence"].append(int(row[4]))
                            total.add(contract)
                        elif attack == "BlockStateDependence":
                            #if contract not in contracts["block_state_dependence"]:
                            #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                            #    if "result" in response and response['result'][0]['SourceCode']:
                            #        print(contract)
                            contracts["block_state_dependence"].add(contract)
                            transactions["block_state_dependence"].add(row[0])
                            #print(contract+" "+row[0]+" "+str(row[4]))
                            ether["block_state_dependence"].append(int(row[4]))
                            total.add(contract)
                        elif attack == "UncheckedSignature":
                            unchecked_signature.append(contract)
                            total.add(contract)
                        elif attack == "BalanceInvariant":
                            balance_invariant.append(contract)
                            total.add(contract)
                        elif attack == "InsufficientGas":
                            #if contract not in contracts["insufficient_gas"]:
                            #    print(contract+" "+str(row))
                            #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                            #    if "result" in response and response['result'][0]['SourceCode']:
                            #        print(contract)
                            contracts["insufficient_gas"].add(contract)
                            transactions["insufficient_gas"].add(row[0])
                            total.add(contract)


    """print("")
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
    #print("")"""
    print("-----------------------------------------------------------------------")
    print("Number of reentrancy vulnerable contracts: \t \t \t "+str(len(contracts["reentrancy"]))+" \t "+str(len(transactions["reentrancy"])))
    print("Number of cross-function reentrancy vulnerable contracts: \t "+str(len(cross_function_reentrancy)))
    print("Number of delegated reentrancy vulnerable contracts: \t \t "+str(len(delegated_reentrancy)))
    print("Number of create-based reentrancy vulnerable contracts: \t "+str(len(create_based_reentrancy)))
    print("Number of unhandled exception vulnerable contracts: \t \t "+str(len(contracts["unhandled_exception"]))+" \t "+str(len(transactions["unhandled_exception"]))+" \t "+str(sum(ether["unhandled_exception"]))+" Wei")
    print("Number of transaction order dependence vulnerable contracts: \t "+str(len(contracts["transaction_order_dependence"]))+" \t "+str(len(transactions["transaction_order_dependence"])))
    print("Number of block state dependence vulnerable contracts: \t \t "+str(len(contracts["block_state_dependence"]))+" \t "+str(len(transactions["block_state_dependence"]))+" \t "+str(Web3.fromWei(sum(ether["block_state_dependence"]), 'ether'))+" ETH")
    print("Number of timestamp dependence vulnerable contracts: \t \t "+str(len(contracts["timestamp_dependence"]))+" \t "+str(len(transactions["timestamp_dependence"]))+" \t "+str(Web3.fromWei(sum(ether["timestamp_dependence"]), 'ether'))+" ETH")
    print("Number of transaction state dependence vulnerable contracts: \t "+str(len(contracts["transaction_state_dependence"]))+" \t "+str(len(transactions["transaction_state_dependence"]))+" \t "+str(Web3.fromWei(sum(ether["transaction_state_dependence"]), 'ether'))+" ETH")
    print("Number of call stack depth vulnerable contracts: \t \t "+str(len(call_stack_depth)))
    print("Number of integer overflow addition vulnerable contracts: \t "+str(len(integer_overflow_addition)))
    print("Number of integer overflow multiplication vulnerable contracts:  "+str(len(integer_overflow_multiplication)))
    print("Number of integer underflow vulnerable contracts: \t \t "+str(len(integer_underflow)))
    print("Number of DoS with unexpected throw vulnerable contracts: \t "+str(len(dos_with_unexpected_throw)))
    print("Number of DoS with block gas limit vulnerable contracts: \t "+str(len(dos_with_block_gas_limit)))
    print("Number of short address vulnerable contracts: \t \t \t "+str(len(short_address)))
    print("Number of unchecked delegatecall vulnerable contracts: \t \t "+str(len(unchecked_delegatecall)))
    print("Number of unchecked suicide vulnerable contracts: \t \t "+str(len(contracts["unchecked_suicide"]))+" \t "+str(len(transactions["unchecked_suicide"])))
    print("Number of Parity wallet hack 1 vulnerable contracts: \t \t "+str(len(parity_wallet_hack_1)))
    print("Number of Parity wallet hack 2 vulnerable contracts: \t \t "+str(len(contracts["parity_wallet_hack_2"]))+" \t "+str(len(transactions["parity_wallet_hack_2"])))
    print("Number of unchecked signature vulnerable contracts: \t \t "+str(len(unchecked_signature)))
    print("Number of balance invariant vulnerable contracts: \t \t "+str(len(balance_invariant)))
    print("Number of insufficient gas vulnerable contracts: \t \t "+str(len(contracts["insufficient_gas"]))+" \t "+str(len(transactions["insufficient_gas"])))
    print("-----------------------------------------------------------------------")
    print("Total number of vulnerable contracts: \t \t \t \t "+str(len(total)))
