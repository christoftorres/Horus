#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import csv
import sys
import math
import shutil
import zipfile
import requests
import traceback

from web3 import Web3
from tqdm import tqdm
from datetime import datetime
from collections import OrderedDict

FOLDER = "/Users/Christof/Downloads/results"

def variance(x):
     n = len(x)
     x_bar = mean(x)
     return(round(sum((x_i - x_bar)**2 for x_i in x) / (n - 1), 2))

def standard_deviation(x):
     return(math.sqrt(variance(x)))

print("Evaluating results...")

#transactions = []
#execution_times = []
#retrieval_times = []

transactions = {
    "reentrancy": set(),
    "cross_function_reentrancy": set(),
    "delegated_reentrancy": set(),
    "create_based_reentrancy": set(),
    "unhandled_exception": set(),
    "transaction_order_dependence": set(),
    "block_state_dependence": set(),
    "timestamp_dependence": set(),
    "transaction_state_dependence": set(),
    "call_stack_depth": set(),
    "integer_overflow_addition": set(),
    "integer_overflow_multiplication": set(),
    "integer_underflow": set(),
    "dos_with_unexpected_throw": set(),
    "dos_with_block_gas_limit": set(),
    "short_address": set(),
    "unchecked_delegatecall": set(),
    "unchecked_suicide": set(),
    "parity_wallet_hack_1": set(),
    "parity_wallet_hack_2": set(),
    "unchecked_signature": set(),
    "balance_invariant": set(),
    "insufficient_gas": set()
}

contracts = {
    "reentrancy": set(),
    "cross_function_reentrancy": set(),
    "delegated_reentrancy": set(),
    "create_based_reentrancy": set(),
    "unhandled_exception": set(),
    "transaction_order_dependence": set(),
    "block_state_dependence": set(),
    "timestamp_dependence": set(),
    "transaction_state_dependence": set(),
    "call_stack_depth": set(),
    "integer_overflow_addition": set(),
    "integer_overflow_multiplication": set(),
    "integer_underflow": set(),
    "dos_with_unexpected_throw": set(),
    "dos_with_block_gas_limit": set(),
    "short_address": set(),
    "unchecked_delegatecall": set(),
    "unchecked_suicide": set(),
    "parity_wallet_hack_1": set(),
    "parity_wallet_hack_2": set(),
    "unchecked_signature": set(),
    "balance_invariant": set(),
    "insufficient_gas": set()
}

ether = {
    "reentrancy": [],
    "cross_function_reentrancy": [],
    "delegated_reentrancy": [],
    "create_based_reentrancy": [],
    "unhandled_exception": [],
    "transaction_order_dependence": [],
    "block_state_dependence": [],
    "timestamp_dependence": [],
    "transaction_state_dependence": [],
    "call_stack_depth": [],
    "integer_overflow_addition": [],
    "integer_overflow_multiplication": [],
    "integer_underflow": [],
    "dos_with_unexpected_throw": [],
    "dos_with_block_gas_limit": [],
    "short_address": [],
    "unchecked_delegatecall": [],
    "unchecked_suicide": [],
    "parity_wallet_hack_1": [],
    "parity_wallet_hack_2": [],
    "unchecked_signature": [],
    "balance_invariant": [],
    "insufficient_gas": []
}

timeline = {
    "reentrancy": {},
    "cross_function_reentrancy": {},
    "delegated_reentrancy": {},
    "create_based_reentrancy": {}
}

contracts_total = set()
transactions_total = set()
ether_total = 0

automated_validation = {
    "parity_wallet_hack_1": {
        "false_positives": [],
        "true_positivies": [],
        "unknown": []
    },
    "parity_wallet_hack_2": {
        "false_positives": [],
        "true_positivies": [],
        "unknown": []
    },
}

if __name__ == '__main__':
    from pathlib import Path
    pathlist = Path(FOLDER).glob('**/*.zip')
    with tqdm(total=len(list(Path(FOLDER).glob('**/*.zip'))), unit=" contract", leave=False, smoothing=0.1) as pbar:
        for path in pathlist:
            #print(path)
            contract = str(path).split('/')[-1].split('.')[0]
            #print(contract)
            with zipfile.ZipFile(path) as z:
                for filename in z.namelist():
                    if filename.endswith(".csv"):
                        with z.open(filename) as f:
                            csv.field_size_limit(sys.maxsize)
                            from io import StringIO
                            s = StringIO(f.read().decode("utf-8"))
                            reader = csv.reader(s, delimiter='\t')
                            for row in reader:
                                #print(row)
                                attack = os.path.splitext(os.path.basename(filename))[0]
                                #print(attack)
                                if   attack == "CallStackDepth":
                                    contracts["call_stack_depth"].add(contract)
                                    transactions["call_stack_depth"].add(row[0])
                                    ether["call_stack_depth"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                elif attack == "Reentrancy":
                                    #if contract not in contracts["reentrancy"]:
                                    #    print(contract+" "+str(row))
                                    contracts["reentrancy"].add(contract)
                                    transactions["reentrancy"].add(row[0])
                                    ether["reentrancy"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                    d = datetime.fromtimestamp(int(row[1]))
                                    if not d.strftime("%Y-%m-%d") in timeline["reentrancy"]:
                                        timeline["reentrancy"][d.strftime("%Y-%m-%d")] = 1
                                    else:
                                        timeline["reentrancy"][d.strftime("%Y-%m-%d")] += 1
                                elif attack == "CrossFunctionReentrancy":
                                    #if contract not in contracts["cross_function_reentrancy"]:
                                    #    print(contract+" "+str(row))
                                    #    print("cross_function_reentrancy")
                                    contracts["cross_function_reentrancy"].add(contract)
                                    transactions["cross_function_reentrancy"].add(row[0])
                                    ether["cross_function_reentrancy"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                    d = datetime.fromtimestamp(int(row[1]))
                                    if not d.strftime("%Y-%m-%d") in timeline["cross_function_reentrancy"]:
                                        timeline["cross_function_reentrancy"][d.strftime("%Y-%m-%d")] = 1
                                    else:
                                        timeline["cross_function_reentrancy"][d.strftime("%Y-%m-%d")] += 1
                                elif attack == "DelegatedReentrancy":
                                    #if contract not in contracts["delegated_reentrancy"]:
                                    #    print(contract+" "+str(row))
                                    #    print("delegated_reentrancy")
                                    contracts["delegated_reentrancy"].add(contract)
                                    transactions["delegated_reentrancy"].add(row[0])
                                    ether["delegated_reentrancy"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                    d = datetime.fromtimestamp(int(row[1]))
                                    if not d.strftime("%Y-%m-%d") in timeline["delegated_reentrancy"]:
                                        timeline["delegated_reentrancy"][d.strftime("%Y-%m-%d")] = 1
                                    else:
                                        timeline["delegated_reentrancy"][d.strftime("%Y-%m-%d")] += 1
                                elif attack == "CreateBasedReentrancy":
                                    #if contract not in contracts["create_based_reentrancy"]:
                                    #    print(contract+" "+str(row))
                                    #    print("create_based_reentrancy")
                                    contracts["create_based_reentrancy"].add(contract)
                                    transactions["create_based_reentrancy"].add(row[0])
                                    ether["create_based_reentrancy"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                    d = datetime.fromtimestamp(int(row[1]))
                                    if not d.strftime("%Y-%m-%d") in timeline["create_based_reentrancy"]:
                                        timeline["create_based_reentrancy"][d.strftime("%Y-%m-%d")] = 1
                                    else:
                                        timeline["create_based_reentrancy"][d.strftime("%Y-%m-%d")] += 1
                                elif attack == "UnhandledException":
                                    #if contract not in contracts["unhandled_exception"]:
                                    #    print(contract+" "+str(row))
                                    #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                    #    if "result" in response and response['result'][0]['SourceCode']:
                                    #        print(contract)
                                    contracts["unhandled_exception"].add(contract)
                                    transactions["unhandled_exception"].add(row[0])
                                    #ether["unhandled_exception"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                elif attack == "IntegerOverflow":
                                    if   row[3] == "ADD":
                                        contracts["integer_overflow_addition"].add(contract)
                                        transactions["integer_overflow_addition"].add(row[0])
                                        #ether["integer_overflow_addition"].append(int(row[5]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                    elif row[3] == "MUL":
                                        #if contract not in contracts["integer_overflow_multiplication"]:
                                        #    print(contract+" "+str(row))
                                        #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                        #    if "result" in response and response['result'][0]['SourceCode']:
                                        #        print(contract)
                                        contracts["integer_overflow_multiplication"].add(contract)
                                        transactions["integer_overflow_multiplication"].add(row[0])
                                        #ether["integer_overflow_multiplication"].append(int(row[5]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                elif attack == "IntegerUnderflow":
                                    #if contract not in contracts["integer_underflow"]:
                                    #    print(contract+" "+str(row))
                                    #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                    #    if "result" in response and response['result'][0]['SourceCode']:
                                    #        print(contract)
                                    contracts["integer_underflow"].add(contract)
                                    transactions["integer_underflow"].add(row[0])
                                    #ether["integer_underflow"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                elif attack == "TransactionOrderDependency":
                                    #if contract not in contracts["transaction_order_dependence"]:
                                    #    print(contract+" "+str(row))
                                    #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                    #    if "result" in response and response['result'][0]['SourceCode']:
                                    #        print(contract)
                                    contracts["transaction_order_dependence"].add(contract)
                                    transactions["transaction_order_dependence"].add(row[0])
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                elif attack == "UncheckedSuicide":
                                    #if contract not in contracts["unchecked_suicide"]:
                                    #    print(contract+" "+str(row))
                                    #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                    #    if "result" in response and response['result'][0]['SourceCode']:
                                    #        if "delegatecall" in response['result'][0]['SourceCode']:
                                    #            print(contract)
                                    contracts["unchecked_suicide"].add(contract)
                                    transactions["unchecked_suicide"].add(row[0])
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                elif attack == "UncheckedDelegatecall":
                                    #if contract not in contracts["unchecked_delegatecall"]:
                                    #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                    #    if "result" in response and response['result'][0]['SourceCode']:
                                    #        if "delegatecall" in response['result'][0]['SourceCode']:
                                    #            print(contract+" "+str(row))
                                    contracts["unchecked_delegatecall"].add(contract)
                                    transactions["unchecked_delegatecall"].add(row[0])
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                elif attack == "ParityWalletHack1":
                                    if contract not in contracts["parity_wallet_hack_1"]:
                                        #print(contract+" "+str(row))
                                        response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                        if "result" in response and response['result'][0]['SourceCode']:
                                            if "function initWallet(" in response['result'][0]['SourceCode'] and \
                                               "function execute(" in response['result'][0]['SourceCode']:
                                                automated_validation["parity_wallet_hack_1"]["true_positivies"].append(contract)
                                            else:
                                                automated_validation["parity_wallet_hack_1"]["false_positives"].append(contract)
                                        else:
                                            automated_validation["parity_wallet_hack_1"]["unknown"].append(contract)
                                    contracts["parity_wallet_hack_1"].add(contract)
                                    transactions["parity_wallet_hack_1"].add(row[0])
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                elif attack == "ParityWalletHack2":
                                    if contract not in contracts["parity_wallet_hack_2"]:
                                        #print(contract+" "+str(row))
                                        response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                        if "result" in response and response['result'][0]['SourceCode']:
                                            if "function initWallet(" in response['result'][0]['SourceCode'] and \
                                               "function kill(" in response['result'][0]['SourceCode']:
                                                automated_validation["parity_wallet_hack_2"]["true_positivies"].append(contract)
                                            else:
                                                automated_validation["parity_wallet_hack_2"]["false_positives"].append(contract)
                                        else:
                                            automated_validation["parity_wallet_hack_2"]["unknown"].append(contract)
                                    contracts["parity_wallet_hack_2"].add(contract)
                                    transactions["parity_wallet_hack_2"].add(row[0])
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                elif attack == "ShortAddress":
                                    contracts["short_address"].add(contract)
                                    transactions["short_address"].add(row[0])
                                    ether["short_address"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                elif attack == "DoSWithUnexpectedThrow":
                                    contracts["dos_with_unexpected_throw"].add(contract)
                                    transactions["dos_with_unexpected_throw"].add(row[0])
                                    ether["dos_with_unexpected_throw"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                elif attack == "DoSWithBlockGasLimit":
                                    contracts["dos_with_block_gas_limit"].add(contract)
                                    transactions["dos_with_block_gas_limit"].add(row[0])
                                    ether["dos_with_block_gas_limit"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                elif attack == "TimestampDependence":
                                    #if contract not in contracts["timestamp_dependence"]:
                                    #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                    #    if "result" in response and response['result'][0]['SourceCode']:
                                    #        print(contract)
                                    #        print(contract+" "+row[0]+" "+str(row[4]))
                                    contracts["timestamp_dependence"].add(contract)
                                    transactions["timestamp_dependence"].add(row[0])
                                    ether["timestamp_dependence"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                elif attack == "TransactionStateDependence":
                                    #if contract not in contracts["transaction_state_dependence"]:
                                    #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                    #    if "result" in response and response['result'][0]['SourceCode']:
                                    #        print(contract)
                                    #        print(contract+" "+row[0]+" "+str(row[4]))
                                    contracts["transaction_state_dependence"].add(contract)
                                    transactions["transaction_state_dependence"].add(row[0])
                                    ether["transaction_state_dependence"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                elif attack == "BlockStateDependence":
                                    #if contract not in contracts["block_state_dependence"]:
                                    #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                    #    if "result" in response and response['result'][0]['SourceCode']:
                                    #        print(contract)
                                    contracts["block_state_dependence"].add(contract)
                                    transactions["block_state_dependence"].add(row[0])
                                    ether["block_state_dependence"].append(int(row[5]))
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                    ether_total += int(row[5])
                                elif attack == "UncheckedSignature":
                                    contracts["unchecked_signature"].add(contract)
                                    transactions["unchecked_signature"].add(row[0])
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                elif attack == "BalanceInvariant":
                                    contracts["balance_invariant"].add(contract)
                                    transactions["balance_invariant"].add(row[0])
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
                                elif attack == "InsufficientGas":
                                    #if contract not in contracts["insufficient_gas"]:
                                    #    print(contract+" "+str(row))
                                    #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                    #    if "result" in response and response['result'][0]['SourceCode']:
                                    #        print(contract)
                                    contracts["insufficient_gas"].add(contract)
                                    transactions["insufficient_gas"].add(row[0])
                                    contracts_total.add(contract)
                                    transactions_total.add(row[0])
            pbar.update(1)

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
    print(" \t \t \t \t \t \t \t \t Contracts \t Transactions \t Ether")
    print("------------------------------------------------------------------------------------------------------------")
    print("Number of reentrancy vulnerable contracts: \t \t \t "+str(len(contracts["reentrancy"]))+" \t \t "+str(len(transactions["reentrancy"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["reentrancy"]), 'ether')))+" ETH")
    print("Number of cross-function reentrancy vulnerable contracts: \t "+str(len(contracts["cross_function_reentrancy"]))+" \t \t "+str(len(transactions["cross_function_reentrancy"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["cross_function_reentrancy"]), 'ether')))+" ETH")
    print("Number of delegated reentrancy vulnerable contracts: \t \t "+str(len(contracts["delegated_reentrancy"]))+" \t \t "+str(len(transactions["delegated_reentrancy"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["delegated_reentrancy"]), 'ether')))+" ETH")
    print("Number of create-based reentrancy vulnerable contracts: \t "+str(len(contracts["create_based_reentrancy"]))+" \t \t "+str(len(transactions["create_based_reentrancy"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["create_based_reentrancy"]), 'ether')))+" ETH")
    print("Number of unhandled exception vulnerable contracts: \t \t "+str(len(contracts["unhandled_exception"]))+" \t \t "+str(len(transactions["unhandled_exception"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["unhandled_exception"]), 'ether')))+" ETH")
    print("Number of transaction order dependence vulnerable contracts: \t "+str(len(contracts["transaction_order_dependence"]))+" \t \t "+str(len(transactions["transaction_order_dependence"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["transaction_order_dependence"]), 'ether')))+" ETH")
    print("Number of block state dependence vulnerable contracts: \t \t "+str(len(contracts["block_state_dependence"]))+" \t \t "+str(len(transactions["block_state_dependence"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["block_state_dependence"]), 'ether')))+" ETH")
    print("Number of timestamp dependence vulnerable contracts: \t \t "+str(len(contracts["timestamp_dependence"]))+" \t \t "+str(len(transactions["timestamp_dependence"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["timestamp_dependence"]), 'ether')))+" ETH")
    print("Number of transaction state dependence vulnerable contracts: \t "+str(len(contracts["transaction_state_dependence"]))+" \t \t "+str(len(transactions["transaction_state_dependence"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["transaction_state_dependence"]), 'ether')))+" ETH")
    print("Number of call stack depth vulnerable contracts: \t \t "+str(len(contracts["call_stack_depth"]))+" \t \t "+str(len(transactions["call_stack_depth"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["call_stack_depth"]), 'ether')))+" ETH")
    print("Number of integer overflow addition vulnerable contracts: \t "+str(len(contracts["integer_overflow_addition"]))+" \t \t "+str(len(transactions["integer_overflow_addition"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["integer_overflow_addition"]), 'ether')))+" ETH")
    print("Number of integer overflow multiplication vulnerable contracts:  "+str(len(contracts["integer_overflow_multiplication"]))+" \t \t "+str(len(transactions["integer_overflow_multiplication"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["integer_overflow_multiplication"]), 'ether')))+" ETH")
    print("Number of integer underflow vulnerable contracts: \t \t "+str(len(contracts["integer_underflow"]))+" \t \t "+str(len(transactions["integer_underflow"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["integer_underflow"]), 'ether')))+" ETH")
    print("Number of DoS with unexpected throw vulnerable contracts: \t "+str(len(contracts["dos_with_unexpected_throw"]))+" \t \t "+str(len(transactions["dos_with_unexpected_throw"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["dos_with_unexpected_throw"]), 'ether')))+" ETH")
    print("Number of DoS with block gas limit vulnerable contracts: \t "+str(len(contracts["dos_with_block_gas_limit"]))+" \t \t "+str(len(transactions["dos_with_block_gas_limit"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["dos_with_block_gas_limit"]), 'ether')))+" ETH")
    print("Number of short address vulnerable contracts: \t \t \t "+str(len(contracts["short_address"]))+" \t \t "+str(len(transactions["short_address"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["short_address"]), 'ether')))+" ETH")
    print("Number of unchecked delegatecall vulnerable contracts: \t \t "+str(len(contracts["unchecked_delegatecall"]))+" \t \t "+str(len(transactions["unchecked_delegatecall"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["unchecked_delegatecall"]), 'ether')))+" ETH")
    print("Number of unchecked suicide vulnerable contracts: \t \t "+str(len(contracts["unchecked_suicide"]))+" \t \t "+str(len(transactions["unchecked_suicide"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["unchecked_suicide"]), 'ether')))+" ETH")
    print("Number of Parity wallet hack 1 vulnerable contracts: \t \t "+str(len(contracts["parity_wallet_hack_1"]))+" \t \t "+str(len(transactions["parity_wallet_hack_1"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["parity_wallet_hack_1"]), 'ether')))+" ETH")
    print("Number of Parity wallet hack 2 vulnerable contracts: \t \t "+str(len(contracts["parity_wallet_hack_2"]))+" \t \t "+str(len(transactions["parity_wallet_hack_2"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["parity_wallet_hack_2"]), 'ether')))+" ETH")
    print("Number of unchecked signature vulnerable contracts: \t \t "+str(len(contracts["unchecked_signature"]))+" \t \t "+str(len(transactions["unchecked_signature"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["unchecked_signature"]), 'ether')))+" ETH")
    print("Number of balance invariant vulnerable contracts: \t \t "+str(len(contracts["balance_invariant"]))+" \t \t "+str(len(transactions["balance_invariant"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["balance_invariant"]), 'ether')))+" ETH")
    print("Number of insufficient gas vulnerable contracts: \t \t "+str(len(contracts["insufficient_gas"]))+" \t \t "+str(len(transactions["insufficient_gas"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["insufficient_gas"]), 'ether')))+" ETH")
    print("------------------------------------------------------------------------------------------------------------")
    print("Total number of vulnerable contracts: \t \t \t \t "+str(len(contracts_total))+"/"+str(len(list(Path(FOLDER).glob('**/*.zip'))))+" \t "+str(len(transactions_total))+" \t \t "+str(round(Web3.fromWei(ether_total, 'ether')))+" ETH")

    with open('reentrancy_timelime.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Transactions'])
        timeline["reentrancy"] = OrderedDict(sorted(timeline["reentrancy"].items(), key=lambda t: t[0]))
        for date in timeline["reentrancy"]:
            writer.writerow([date, timeline["reentrancy"][date]])
    with open('cross_function_reentrancy_timelime.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Transactions'])
        timeline["cross_function_reentrancy"] = OrderedDict(sorted(timeline["cross_function_reentrancy"].items(), key=lambda t: t[0]))
        for date in timeline["cross_function_reentrancy"]:
            writer.writerow([date, timeline["cross_function_reentrancy"][date]])
    with open('delegated_reentrancy_timelime.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Transactions'])
        timeline["delegated_reentrancy"] = OrderedDict(sorted(timeline["delegated_reentrancy"].items(), key=lambda t: t[0]))
        for date in timeline["delegated_reentrancy"]:
            writer.writerow([date, timeline["delegated_reentrancy"][date]])
    with open('create_based_reentrancy_timelime.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Transactions'])
        timeline["create_based_reentrancy"] = OrderedDict(sorted(timeline["create_based_reentrancy"].items(), key=lambda t: t[0]))
        for date in timeline["create_based_reentrancy"]:
            writer.writerow([date, timeline["create_based_reentrancy"][date]])

    #print(automated_validation)
