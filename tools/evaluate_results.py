#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import csv
import sys
import math
import json
import shutil
import zipfile
import requests
import traceback

import decimal

from io import StringIO
from pathlib import Path
from web3 import Web3
from tqdm import tqdm
from datetime import datetime
from collections import OrderedDict
from pyetherchain.pyetherchain import EtherChainApi

FOLDER = "/Users/Christof/Downloads/results"

etherchain_api = EtherChainApi()

prices = etherchain_api.get_stats_price_usd()

def variance(x):
     n = len(x)
     x_bar = mean(x)
     return(round(sum((x_i - x_bar)**2 for x_i in x) / (n - 1), 2))

def standard_deviation(x):
     return(math.sqrt(variance(x)))

def get_one_eth_to_usd(timestamp):
    one_eth_to_usd = prices[-1]["value"]
    for index, price in enumerate(prices):
        if index < len(prices)-1:
            if prices[index]["time"] <= timestamp and timestamp <= prices[index+1]["time"]:
                one_eth_to_usd = prices[index]["value"]
                break
    return one_eth_to_usd

print("Evaluating results...")

#transactions = []
#execution_times = []
#retrieval_times = []

transactions = {
    "reentrancy": set(),
    "erc777_reentrancy": set(),
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
    "erc777_reentrancy": set(),
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

tokens = {
    "integer_overflow_addition": [],
    "integer_overflow_multiplication": [],
    "integer_underflow": []
}

erc20_tokens = {}

usd = {
    "reentrancy": [],
    "cross_function_reentrancy": [],
    "delegated_reentrancy": [],
    "create_based_reentrancy": [],
    "integer_overflow_addition": [],
    "integer_overflow_multiplication": [],
    "integer_underflow": [],
    "parity_wallet_hack_1": [],
    "parity_wallet_hack_2": []
}

timeline = {
    "reentrancy": {},
    "integer_overflow": {},
    "integer_underflow": {},
    "parity_wallet_hack_1": {},
    "parity_wallet_hack_2": {}
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

vulnerable_deployments = {
    "reentrancy": {},
    "integer_overflow": {},
    "integer_underflow": {},
    "parity_wallet_hack_1": {},
    "parity_wallet_hack_2": {}
}

attackers = {
    "reentrancy": set(),
    "erc777_reentrancy": set(),
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

results = []

def add_new_token(contract):
    w3 = Web3(Web3.HTTPProvider("http://pf.uni.lux:8545"))
    with open('erc20abi.json') as json_file:
        abi = json.load(json_file)
        token = w3.eth.contract(Web3.toChecksumAddress(contract), abi=abi)
        name = "",
        symbol = ""
        decimals = 0
        try:
            name = token.functions.name().call()
        except:
            pass
        try:
            symbol = token.functions.symbol().call()
        except:
            pass
        try:
            decimals = token.functions.decimals().call()
        except:
            pass
        erc20_tokens[contract] = {"name": name, "symbol": symbol, "decimals": decimals, "amount": 0}

def get_sender(transaction_hash):
    w3 = Web3(Web3.HTTPProvider("http://pf.uni.lux:8545"))
    return str(w3.eth.getTransaction(transaction_hash)["from"]).lower()

def get_deployment_timestamp(contract):
    return int(requests.get('http://api.etherscan.io/api?module=account&action=txlist&address='+contract+'&startblock=0&endblock=99999999&page=1&offset=1&sort=asc&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()["result"][0]["timeStamp"])

if __name__ == '__main__':
    os.mkdir('results')
    call_stack_depth_results_file = open('results/call_stack_depth.csv', 'w')
    call_stack_depth_results_writer = csv.writer(call_stack_depth_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    reentrancy_results_file = open('results/reentrancy.csv', 'w')
    reentrancy_results_writer = csv.writer(reentrancy_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    delegated_reentrancy_results_file = open('results/delegated_reentrancy.csv', 'w')
    delegated_reentrancy_results_writer = csv.writer(delegated_reentrancy_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    integer_overflow_addition_results_file = open('results/integer_overflow_addition.csv', 'w')
    integer_overflow_addition_results_writer = csv.writer(integer_overflow_addition_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    integer_underflow_results_file = open('results/integer_underflow.csv', 'w')
    integer_underflow_results_writer = csv.writer(integer_underflow_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    parity_wallet_hack_1_results_file = open('results/parity_wallet_hack_1.csv', 'w')
    parity_wallet_hack_1_results_writer = csv.writer(parity_wallet_hack_1_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    parity_wallet_hack_2_results_file = open('results/parity_wallet_hack_2.csv', 'w')
    parity_wallet_hack_2_results_writer = csv.writer(parity_wallet_hack_2_results_file, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)

    pathlist = Path(FOLDER).glob('**/*.zip')
    with tqdm(total=len(list(Path(FOLDER).glob('**/*.zip'))), unit=" contract", leave=False, smoothing=0.1) as pbar:
        for path in pathlist:
            contract = str(path).split('/')[-1].split('.')[0]
            try:
                with zipfile.ZipFile(path) as z:
                    for filename in z.namelist():
                        if filename.endswith(".csv"):
                            with z.open(filename) as f:
                                csv.field_size_limit(sys.maxsize)
                                s = StringIO(f.read().decode("utf-8"))
                                reader = csv.reader(s, delimiter='\t')
                                for row in reader:
                                    attack = os.path.splitext(os.path.basename(filename))[0]
                                    if   attack == "CallStackDepth":
                                        contract = row[3]
                                        attackers["call_stack_depth"].add(get_sender(row[0]))
                                        contracts["call_stack_depth"].add(contract)
                                        transactions["call_stack_depth"].add(row[0])
                                        ether["call_stack_depth"].append(int(row[5]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        ether_total += int(row[5])
                                        d = datetime.fromtimestamp(int(row[1]))
                                        one_eth_to_usd = get_one_eth_to_usd(int(row[1]))
                                        if not d.strftime("%Y-%m-%d") in timeline["reentrancy"]:
                                            timeline["call_stack_depth"][d.strftime("%Y-%m-%d")] = {
                                                "transactions": 1,
                                                "usd": Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                            }
                                        else:
                                            timeline["call_stack_depth"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                            timeline["call_stack_depth"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                        row.insert(0, get_sender(row[0]))
                                        row.insert(0, contract)
                                        call_stack_depth_results_writer.writerow(row)

                                    elif attack == "Reentrancy":
                                        contract = row[2]
                                        if contract not in contracts["reentrancy"]:
                                            d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                            if not d.strftime("%Y-%m-%d") in vulnerable_deployments["reentrancy"]:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] = 1
                                            else:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] += 1
                                        attackers["reentrancy"].add(get_sender(row[0]))
                                        contracts["reentrancy"].add(row[2])
                                        transactions["reentrancy"].add(row[0])
                                        ether["reentrancy"].append(int(row[5]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        ether_total += int(row[5])
                                        d = datetime.fromtimestamp(int(row[1]))
                                        one_eth_to_usd = get_one_eth_to_usd(int(row[1]))
                                        if not d.strftime("%Y-%m-%d") in timeline["reentrancy"]:
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")] = {
                                                "transactions": 1,
                                                "usd": Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                            }
                                        else:
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                        row.insert(0, get_sender(row[0]))
                                        row.insert(0, contract)
                                        reentrancy_results_writer.writerow(row)

                                    elif attack == "ERC777Reentrancy":
                                        contract = row[2]
                                        if contract not in contracts["erc777_reentrancy"]:
                                            d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                            if not d.strftime("%Y-%m-%d") in vulnerable_deployments["reentrancy"]:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] = 1
                                            else:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] += 1
                                        attackers["erc777_reentrancy"].add(get_sender(row[0]))
                                        contracts["erc777_reentrancy"].add(contract)
                                        transactions["erc777_reentrancy"].add(row[0])
                                        if row[4] == "Ether":
                                            ether["erc777_reentrancy"].append(int(row[4]))
                                        else:
                                            tokens["erc777_reentrancy"].append(int(row[4]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                    elif attack == "CrossFunctionReentrancy":
                                        if row[2] not in contracts["cross_function_reentrancy"]:
                                            d = datetime.fromtimestamp(get_deployment_timestamp(row[2]))
                                            if not d.strftime("%Y-%m-%d") in vulnerable_deployments["reentrancy"]:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] = 1
                                            else:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] += 1
                                        #if contract not in contracts["cross_function_reentrancy"]:
                                        #    print("cross_function_reentrancy: "+contract+" "+str(row))
                                        attackers["cross_function_reentrancy"].add(get_sender(row[0]))
                                        contracts["cross_function_reentrancy"].add(row[2])
                                        transactions["cross_function_reentrancy"].add(row[0])
                                        ether["cross_function_reentrancy"].append(int(row[5]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        ether_total += int(row[5])
                                        d = datetime.fromtimestamp(int(row[1]))
                                        one_eth_to_usd = get_one_eth_to_usd(int(row[1]))
                                        if not d.strftime("%Y-%m-%d") in timeline["reentrancy"]:
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")] = {
                                                "transactions": 1,
                                                "usd": Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                            }
                                        else:
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                    elif attack == "DelegatedReentrancy":
                                        contract = row[2]
                                        if contract not in contracts["delegated_reentrancy"]:
                                            d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                            if not d.strftime("%Y-%m-%d") in vulnerable_deployments["reentrancy"]:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] = 1
                                            else:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] += 1
                                        attackers["delegated_reentrancy"].add(get_sender(row[0]))
                                        contracts["delegated_reentrancy"].add(contract)
                                        transactions["delegated_reentrancy"].add(row[0])
                                        ether["delegated_reentrancy"].append(int(row[5]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        ether_total += int(row[5])
                                        d = datetime.fromtimestamp(int(row[1]))
                                        one_eth_to_usd = get_one_eth_to_usd(int(row[1]))
                                        if not d.strftime("%Y-%m-%d") in timeline["reentrancy"]:
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")] = {
                                                "transactions": 1,
                                                "usd": Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                            }
                                        else:
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                        row.insert(0, get_sender(row[0]))
                                        row.insert(0, contract)
                                        delegated_reentrancy_results_writer.writerow(row)

                                    elif attack == "CreateBasedReentrancy":
                                        if row[2] not in contracts["create_based_reentrancy"]:
                                            d = datetime.fromtimestamp(get_deployment_timestamp(row[2]))
                                            if not d.strftime("%Y-%m-%d") in vulnerable_deployments["reentrancy"]:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] = 1
                                            else:
                                                vulnerable_deployments["reentrancy"][d.strftime("%Y-%m-%d")] += 1
                                        #if contract not in contracts["create_based_reentrancy"]:
                                        #    print("create_based_reentrancy: "+contract+" "+str(row))
                                        attackers["create_based_reentrancy"].add(get_sender(row[0]))
                                        contracts["create_based_reentrancy"].add(row[2])
                                        transactions["create_based_reentrancy"].add(row[0])
                                        ether["create_based_reentrancy"].append(int(row[5]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        ether_total += int(row[5])
                                        d = datetime.fromtimestamp(int(row[1]))
                                        one_eth_to_usd = get_one_eth_to_usd(int(row[1]))
                                        if not d.strftime("%Y-%m-%d") in timeline["reentrancy"]:
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")] = {
                                                "transactions": 1,
                                                "usd": Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                            }
                                        else:
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                            timeline["reentrancy"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[5]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
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
                                        if row[3] == "ADD":
                                            if contract not in contracts["integer_overflow_addition"]:
                                                d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                                if not d.strftime("%Y-%m-%d") in vulnerable_deployments["integer_overflow"]:
                                                    vulnerable_deployments["integer_overflow"][d.strftime("%Y-%m-%d")] = 1
                                                else:
                                                    vulnerable_deployments["integer_overflow"][d.strftime("%Y-%m-%d")] += 1
                                            attackers["integer_overflow_addition"].add(get_sender(row[0]))
                                            contracts["integer_overflow_addition"].add(contract)
                                            transactions["integer_overflow_addition"].add(row[0])
                                            contracts_total.add(contract)
                                            transactions_total.add(row[0])
                                            if row[11] == "Ether":
                                                ether["integer_overflow_addition"].append(int(row[10]))
                                                d = datetime.fromtimestamp(int(row[1]))
                                                one_eth_to_usd = get_one_eth_to_usd(int(row[1]))
                                                if not d.strftime("%Y-%m-%d") in timeline["integer_overflow"]:
                                                    timeline["integer_overflow"][d.strftime("%Y-%m-%d")] = {
                                                        "transactions": 1,
                                                        "usd": Web3.fromWei(int(row[10]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                                    }
                                                else:
                                                    timeline["integer_overflow"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                                    timeline["integer_overflow"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[10]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                            else:
                                                if contract not in erc20_tokens:
                                                    add_new_token(contract)
                                                erc20_tokens[contract]["amount"] += int(row[10])
                                                tokens["integer_overflow_addition"].append(int(row[10]))
                                            row.insert(0, get_sender(row[0]))
                                            row.insert(0, contract)
                                            integer_overflow_addition_results_writer.writerow(row)

                                        elif row[3] != "MUL":
                                            if contract not in contracts["integer_overflow_multiplication"]:
                                                d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                                if not d.strftime("%Y-%m-%d") in vulnerable_deployments["integer_overflow"]:
                                                    vulnerable_deployments["integer_overflow"][d.strftime("%Y-%m-%d")] = 1
                                                else:
                                                    vulnerable_deployments["integer_overflow"][d.strftime("%Y-%m-%d")] += 1
                                            #if contract not in contracts["integer_overflow_multiplication"]:
                                            if row[11] == "Ether":
                                            #    print("integer_overflow_multiplication "+contract+" "+str(row))
                                                if contract not in erc20_tokens:
                                                    add_new_token(contract)
                                                erc20_tokens[contract]["amount"] += int(row[10])
                                            attackers["integer_overflow_multiplication"].add(get_sender(row[0]))
                                            contracts["integer_overflow_multiplication"].add(contract)
                                            transactions["integer_overflow_multiplication"].add(row[0])
                                            contracts_total.add(contract)
                                            transactions_total.add(row[0])
                                            if row[11] == "Ether":
                                                ether["integer_overflow_multiplication"].append(int(row[10]))
                                                d = datetime.fromtimestamp(int(row[1]))
                                                one_eth_to_usd = get_one_eth_to_usd(int(row[1]))
                                                if not d.strftime("%Y-%m-%d") in timeline["integer_overflow"]:
                                                    timeline["integer_overflow"][d.strftime("%Y-%m-%d")] = {
                                                        "transactions": 1,
                                                        "usd": Web3.fromWei(int(row[10]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                                    }
                                                else:
                                                    timeline["integer_overflow"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                                    timeline["integer_overflow"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[10]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                            else:
                                                tokens["integer_overflow_multiplication"].append(int(row[10]))

                                    elif attack == "IntegerUnderflow":
                                        if contract not in contracts["integer_underflow"]:
                                            d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                            if not d.strftime("%Y-%m-%d") in vulnerable_deployments["integer_underflow"]:
                                                vulnerable_deployments["integer_underflow"][d.strftime("%Y-%m-%d")] = 1
                                            else:
                                                vulnerable_deployments["integer_underflow"][d.strftime("%Y-%m-%d")] += 1
                                        attackers["integer_underflow"].add(get_sender(row[0]))
                                        contracts["integer_underflow"].add(contract)
                                        transactions["integer_underflow"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        if row[10] == "Ether":
                                            ether["integer_underflow"].append(int(row[9]))
                                            d = datetime.fromtimestamp(int(row[1]))
                                            one_eth_to_usd = get_one_eth_to_usd(int(row[1]))
                                            if not d.strftime("%Y-%m-%d") in timeline["integer_underflow"]:
                                                timeline["integer_underflow"][d.strftime("%Y-%m-%d")] = {
                                                    "transactions": 1,
                                                    "usd": Web3.fromWei(int(row[9]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                                }
                                            else:
                                                timeline["integer_underflow"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                                timeline["integer_underflow"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[9]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                        else:
                                            if contract not in erc20_tokens:
                                                add_new_token(contract)
                                            erc20_tokens[contract]["amount"] += int(row[9])
                                            tokens["integer_underflow"].append(int(row[9]))
                                        row.insert(0, get_sender(row[0]))
                                        row.insert(0, contract)
                                        integer_underflow_results_writer.writerow(row)

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
                                        #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                        #    if "result" in response and response['result'][0]['SourceCode']:
                                        #        print("unchecked_suicide: "+contract+" "+str(row))
                                        contracts["unchecked_suicide"].add(contract)
                                        transactions["unchecked_suicide"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                    elif attack == "UncheckedDelegatecall":
                                        #if contract not in contracts["unchecked_delegatecall"]:
                                        #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                        #    if "result" in response and response['result'][0]['SourceCode']:
                                        #        print("unchecked_delegatecall: "+contract+" "+str(row))
                                        contracts["unchecked_delegatecall"].add(contract)
                                        transactions["unchecked_delegatecall"].add(row[0])
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])

                                    elif attack == "ParityWalletHack1":
                                        if contract not in contracts["parity_wallet_hack_1"]:
                                            d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                            if not d.strftime("%Y-%m-%d") in vulnerable_deployments["parity_wallet_hack_1"]:
                                                vulnerable_deployments["parity_wallet_hack_1"][d.strftime("%Y-%m-%d")] = 1
                                            else:
                                                vulnerable_deployments["parity_wallet_hack_1"][d.strftime("%Y-%m-%d")] += 1
                                            response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                            if "result" in response and response['result'][0]['SourceCode']:
                                                if "function initWallet(" in response['result'][0]['SourceCode'] and \
                                                   "function execute(" in response['result'][0]['SourceCode']:
                                                    automated_validation["parity_wallet_hack_1"]["true_positivies"].append(contract)
                                                else:
                                                    automated_validation["parity_wallet_hack_1"]["false_positives"].append(contract)
                                            else:
                                                automated_validation["parity_wallet_hack_1"]["unknown"].append(contract)
                                        attackers["parity_wallet_hack_1"].add(get_sender(row[1]))
                                        contracts["parity_wallet_hack_1"].add(contract)
                                        transactions["parity_wallet_hack_1"].add(row[1])
                                        ether["parity_wallet_hack_1"].append(int(row[6]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[1])
                                        d = datetime.fromtimestamp(int(row[4]))
                                        one_eth_to_usd = get_one_eth_to_usd(int(row[4]))
                                        if not d.strftime("%Y-%m-%d") in timeline["parity_wallet_hack_1"]:
                                            timeline["parity_wallet_hack_1"][d.strftime("%Y-%m-%d")] = {
                                                "transactions": 1,
                                                "usd": Web3.fromWei(int(row[6]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                            }
                                        else:
                                            timeline["parity_wallet_hack_1"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                            timeline["parity_wallet_hack_1"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[6]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                        row.insert(0, get_sender(row[1]))
                                        row.insert(0, contract)
                                        parity_wallet_hack_1_results_writer.writerow(row)

                                    elif attack == "ParityWalletHack2":
                                        contract = row[5]
                                        if contract not in contracts["parity_wallet_hack_2"]:
                                            d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                            if not d.strftime("%Y-%m-%d") in vulnerable_deployments["parity_wallet_hack_2"]:
                                                vulnerable_deployments["parity_wallet_hack_2"][d.strftime("%Y-%m-%d")] = 1
                                            else:
                                                vulnerable_deployments["parity_wallet_hack_2"][d.strftime("%Y-%m-%d")] += 1
                                            response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                            if "result" in response and response['result'][0]['SourceCode']:
                                                if "function initWallet(" in response['result'][0]['SourceCode'] and \
                                                   "function kill(" in response['result'][0]['SourceCode']:
                                                    automated_validation["parity_wallet_hack_2"]["true_positivies"].append(contract)
                                                else:
                                                    automated_validation["parity_wallet_hack_2"]["false_positives"].append(contract)
                                            else:
                                                automated_validation["parity_wallet_hack_2"]["unknown"].append(contract)
                                        attackers["parity_wallet_hack_2"].add(get_sender(row[1]))
                                        contracts["parity_wallet_hack_2"].add(contract)
                                        transactions["parity_wallet_hack_2"].add(row[1])
                                        ether["parity_wallet_hack_2"].append(int(row[7]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[1])
                                        d = datetime.fromtimestamp(int(row[4]))
                                        one_eth_to_usd = get_one_eth_to_usd(int(row[4]))
                                        if not d.strftime("%Y-%m-%d") in timeline["parity_wallet_hack_2"]:
                                            timeline["parity_wallet_hack_2"][d.strftime("%Y-%m-%d")] = {
                                                "transactions": 1,
                                                "usd": Web3.fromWei(int(row[7]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                            }
                                        else:
                                            timeline["parity_wallet_hack_2"][d.strftime("%Y-%m-%d")]["transactions"] += 1
                                            timeline["parity_wallet_hack_2"][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(int(row[7]), 'ether') * decimal.Decimal(float(one_eth_to_usd))
                                        row.insert(0, get_sender(row[1]))
                                        row.insert(0, contract)
                                        parity_wallet_hack_2_results_writer.writerow(row)

                                    elif attack == "ShortAddress":
                                        contracts["short_address"].add(contract)
                                        transactions["short_address"].add(row[0])
                                        ether["short_address"].append(int(row[5]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        ether_total += int(row[5])
                                    elif attack == "DoSWithUnexpectedThrow":
                                        #if contract not in contracts["dos_with_unexpected_throw"]:
                                        #    response = requests.get('https://api.etherscan.io/api?module=contract&action=getsourcecode&address='+contract+'&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
                                        #    if "result" in response and response['result'][0]['SourceCode']:
                                        #        print(contract+" "+str(row))
                                        contracts["dos_with_unexpected_throw"].add(contract)
                                        transactions["dos_with_unexpected_throw"].add(row[0])
                                        ether["dos_with_unexpected_throw"].append(int(row[5]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        ether_total += int(row[5])
                                    elif attack == "DoSWithBlockGasLimit":
                                        contracts["dos_with_block_gas_limit"].add(contract)
                                        transactions["dos_with_block_gas_limit"].add(row[0])
                                        ether["dos_with_block_gas_limit"].append(int(row[6]))
                                        contracts_total.add(contract)
                                        transactions_total.add(row[0])
                                        ether_total += int(row[6])
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
                                        #        print(contract+" "+str(row))
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
            except Exception as e:
                print(e)
                print(path)
                traceback.print_exc(file=sys.stdout)
                pass
            pbar.update(1)

    call_stack_depth_results_file.close()
    integer_overflow_addition_results_file.close()

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
    print(" \t \t \t \t \t \t \t \t Contracts \t Transactions \t Leaked Ether \t Locked Ether \t Leaked Tokens")
    print("------------------------------------------------------------------------------------------------------------")
    print("Number of reentrancy vulnerable contracts: \t \t \t "+str(len(contracts["reentrancy"]))+" \t \t "+str(len(transactions["reentrancy"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["reentrancy"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of ERC-777 reentrancy vulnerable contracts: \t \t "+str(len(contracts["erc777_reentrancy"]))+" \t \t "+str(len(transactions["erc777_reentrancy"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of cross-function reentrancy vulnerable contracts: \t "+str(len(contracts["cross_function_reentrancy"]))+" \t \t "+str(len(transactions["cross_function_reentrancy"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["cross_function_reentrancy"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of delegated reentrancy vulnerable contracts: \t \t "+str(len(contracts["delegated_reentrancy"]))+" \t \t "+str(len(transactions["delegated_reentrancy"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["delegated_reentrancy"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of create-based reentrancy vulnerable contracts: \t "+str(len(contracts["create_based_reentrancy"]))+" \t \t "+str(len(transactions["create_based_reentrancy"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["create_based_reentrancy"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of unhandled exception vulnerable contracts: \t \t "+str(len(contracts["unhandled_exception"]))+" \t \t "+str(len(transactions["unhandled_exception"]))+" \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["unhandled_exception"]), 'ether')))+" \t \t 0")
    print("Number of transaction order dependence vulnerable contracts: \t "+str(len(contracts["transaction_order_dependence"]))+" \t \t "+str(len(transactions["transaction_order_dependence"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of block state dependence vulnerable contracts: \t \t "+str(len(contracts["block_state_dependence"]))+" \t \t "+str(len(transactions["block_state_dependence"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of timestamp dependence vulnerable contracts: \t \t "+str(len(contracts["timestamp_dependence"]))+" \t \t "+str(len(transactions["timestamp_dependence"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of transaction state dependence vulnerable contracts: \t "+str(len(contracts["transaction_state_dependence"]))+" \t \t "+str(len(transactions["transaction_state_dependence"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of call stack depth vulnerable contracts: \t \t "+str(len(contracts["call_stack_depth"]))+" \t \t "+str(len(transactions["call_stack_depth"]))+" \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["call_stack_depth"]), 'ether')))+" \t \t 0")
    print("Number of integer overflow addition vulnerable contracts: \t "+str(len(contracts["integer_overflow_addition"]))+" \t \t "+str(len(transactions["integer_overflow_addition"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["integer_overflow_addition"]), 'ether')))+" \t \t 0 \t \t "+str(sum(tokens["integer_overflow_addition"])))
    print("Number of integer overflow multiplication vulnerable contracts:  "+str(len(contracts["integer_overflow_multiplication"]))+" \t \t "+str(len(transactions["integer_overflow_multiplication"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["integer_overflow_multiplication"]), 'ether')))+" \t \t 0 \t \t "+str(sum(tokens["integer_overflow_multiplication"])))
    print("Number of integer underflow vulnerable contracts: \t \t "+str(len(contracts["integer_underflow"]))+" \t \t "+str(len(transactions["integer_underflow"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["integer_underflow"]), 'ether')))+" \t \t 0 \t \t "+str(sum(tokens["integer_underflow"])))
    print("Number of DoS with unexpected throw vulnerable contracts: \t "+str(len(contracts["dos_with_unexpected_throw"]))+" \t \t "+str(len(transactions["dos_with_unexpected_throw"]))+" \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["dos_with_unexpected_throw"]), 'ether'))))
    print("Number of DoS with block gas limit vulnerable contracts: \t "+str(len(contracts["dos_with_block_gas_limit"]))+" \t \t "+str(len(transactions["dos_with_block_gas_limit"]))+" \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["dos_with_block_gas_limit"]), 'ether'))))
    print("Number of short address vulnerable contracts: \t \t \t "+str(len(contracts["short_address"]))+" \t \t "+str(len(transactions["short_address"]))+" \t \t 0 \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["short_address"]), 'ether'))))
    print("Number of unchecked delegatecall vulnerable contracts: \t \t "+str(len(contracts["unchecked_delegatecall"]))+" \t \t "+str(len(transactions["unchecked_delegatecall"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of unchecked suicide vulnerable contracts: \t \t "+str(len(contracts["unchecked_suicide"]))+" \t \t "+str(len(transactions["unchecked_suicide"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of Parity wallet hack 1 vulnerable contracts: \t \t "+str(len(contracts["parity_wallet_hack_1"]))+" \t \t "+str(len(transactions["parity_wallet_hack_1"]))+" \t \t "+str(round(Web3.fromWei(sum(ether["parity_wallet_hack_1"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of Parity wallet hack 2 vulnerable contracts: \t \t "+str(len(contracts["parity_wallet_hack_2"]))+" \t \t "+str(len(transactions["parity_wallet_hack_2"]))+" \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["parity_wallet_hack_2"]), 'ether')))+" \t \t 0")
    print("Number of unchecked signature vulnerable contracts: \t \t "+str(len(contracts["unchecked_signature"]))+" \t \t "+str(len(transactions["unchecked_signature"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of balance invariant vulnerable contracts: \t \t "+str(len(contracts["balance_invariant"]))+" \t \t "+str(len(transactions["balance_invariant"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of insufficient gas vulnerable contracts: \t \t "+str(len(contracts["insufficient_gas"]))+" \t \t "+str(len(transactions["insufficient_gas"]))+" \t \t 0 \t \t 0 \t \t 0")
    print("------------------------------------------------------------------------------------------------------------")
    print("Total number of vulnerable contracts: \t \t \t \t "+str(len(contracts_total))+"/"+str(len(list(Path(FOLDER).glob('**/*.zip'))))+" \t "+str(len(transactions_total))+" \t \t "+str(round(Web3.fromWei(ether_total, 'ether'))))

    with open('reentrancy_timelime.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Transactions', 'USD'])
        timeline["reentrancy"] = OrderedDict(sorted(timeline["reentrancy"].items(), key=lambda t: t[0]))
        for date in timeline["reentrancy"]:
            writer.writerow([date, timeline["reentrancy"][date]["transactions"], round(timeline["reentrancy"][date]["usd"])])
    with open('integer_overflow_timelime.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Transactions', 'USD'])
        timeline["integer_overflow"] = OrderedDict(sorted(timeline["integer_overflow"].items(), key=lambda t: t[0]))
        for date in timeline["integer_overflow"]:
            writer.writerow([date, timeline["integer_overflow"][date]["transactions"], round(timeline["integer_overflow"][date]["usd"])])
    with open('integer_underflow_timelime.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Transactions', 'USD'])
        timeline["integer_underflow"] = OrderedDict(sorted(timeline["integer_underflow"].items(), key=lambda t: t[0]))
        for date in timeline["integer_underflow"]:
            writer.writerow([date, timeline["integer_underflow"][date]["transactions"], round(timeline["integer_underflow"][date]["usd"])])
    with open('parity_wallet_hack_1_timelime.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Transactions', 'USD'])
        timeline["parity_wallet_hack_1"] = OrderedDict(sorted(timeline["parity_wallet_hack_1"].items(), key=lambda t: t[0]))
        for date in timeline["parity_wallet_hack_1"]:
            writer.writerow([date, timeline["parity_wallet_hack_1"][date]["transactions"], round(timeline["parity_wallet_hack_1"][date]["usd"])])
    with open('parity_wallet_hack_2_timelime.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Transactions', 'USD'])
        timeline["parity_wallet_hack_2"] = OrderedDict(sorted(timeline["parity_wallet_hack_2"].items(), key=lambda t: t[0]))
        for date in timeline["parity_wallet_hack_2"]:
            writer.writerow([date, timeline["parity_wallet_hack_2"][date]["transactions"], round(timeline["parity_wallet_hack_2"][date]["usd"])])

    with open('reentrancy_deployments.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["reentrancy"] = OrderedDict(sorted(vulnerable_deployments["reentrancy"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["reentrancy"]:
            writer.writerow([date, vulnerable_deployments["reentrancy"][date]])
    with open('integer_overflow_deployments.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["integer_overflow"] = OrderedDict(sorted(vulnerable_deployments["integer_overflow"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["integer_overflow"]:
            writer.writerow([date, vulnerable_deployments["integer_overflow"][date]])
    with open('integer_underflow_deployments.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["integer_underflow"] = OrderedDict(sorted(vulnerable_deployments["integer_underflow"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["integer_underflow"]:
            writer.writerow([date, vulnerable_deployments["integer_underflow"][date]])
    with open('parity_wallet_hack_1_deployments.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["parity_wallet_hack_1"] = OrderedDict(sorted(vulnerable_deployments["parity_wallet_hack_1"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["parity_wallet_hack_1"]:
            writer.writerow([date, vulnerable_deployments["parity_wallet_hack_1"][date]])
    with open('parity_wallet_hack_2_deployments.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["parity_wallet_hack_2"] = OrderedDict(sorted(vulnerable_deployments["parity_wallet_hack_2"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["parity_wallet_hack_2"]:
            writer.writerow([date, vulnerable_deployments["parity_wallet_hack_2"][date]])

    #print(automated_validation)
    #print(erc20_tokens)
