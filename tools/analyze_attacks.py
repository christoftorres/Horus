#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import csv
import decimal

from web3 import Web3
from datetime import datetime
from collections import OrderedDict
from pyetherchain.pyetherchain import EtherChainApi

FOLDER = "results"

etherchain_api = EtherChainApi()

prices = etherchain_api.get_stats_price_usd()

def get_one_eth_to_usd(timestamp):
    one_eth_to_usd = prices[-1]["value"]
    for index, price in enumerate(prices):
        if index < len(prices)-1:
            if prices[index]["time"] <= timestamp and timestamp <= prices[index+1]["time"]:
                one_eth_to_usd = prices[index]["value"]
                break
    return one_eth_to_usd

ether = {
    "reentrancy": [],
    "erc777_reentrancy": [],
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
    "block_stuffing": [],
    "insufficient_gas": []
}

timeline = {
    "reentrancy": {},
    "erc777_reentrancy": {},
    "cross_function_reentrancy": {},
    "delegated_reentrancy": {},
    "create_based_reentrancy": {},
    "unhandled_exception": {},
    "transaction_order_dependence": {},
    "block_state_dependence": {},
    "timestamp_dependence": {},
    "transaction_state_dependence": {},
    "call_stack_depth": {},
    "integer_overflow_addition": {},
    "integer_overflow_multiplication": {},
    "integer_underflow": {},
    "dos_with_unexpected_throw": {},
    "dos_with_block_gas_limit": {},
    "short_address": {},
    "unchecked_delegatecall": {},
    "unchecked_suicide": {},
    "parity_wallet_hack_1": {},
    "parity_wallet_hack_2": {},
    "block_stuffing": {},
    "insufficient_gas": {}
}

ether_total = 0

if __name__ == '__main__':
    for filename in os.listdir(FOLDER):
        if filename.endswith(".csv"):
            attack = filename.split(".")[0]
            if not filename.startswith("timestamp_dependence") and not filename.startswith("block_state_dependence"):
                with open(os.path.join(FOLDER, filename)) as file:
                    reader = csv.reader(file)
                    for row in reader:
                        if attack == "call_stack_depth":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        elif attack == "reentrancy":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        elif attack == "erc777_reentrancy":
                            if row[6] == "Ether":
                                funds = int(row[4])
                                timestamp = int(row[2])

                        elif attack == "cross_function_reentrancy":
                            funds = int(row[9])
                            timestamp = int(row[2])

                        elif attack == "delegated_reentrancy":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        elif attack == "create_based_reentrancy":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        elif attack == "unhandled_exception":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        elif attack == "integer_overflow_addition":
                            if row[12] == "Ether":
                                funds = int(row[11])
                                timestamp = int(row[2])

                        elif attack == "integer_overflow_multiplication":
                            if row[12] == "Ether":
                                funds = int(row[11])
                                timestamp = int(row[2])

                        elif attack == "integer_underflow":
                            if row[11] == "Ether":
                                funds = int(row[10])
                                timestamp = int(row[2])

                        elif attack == "transaction_order_dependence":
                            break

                        elif attack == "unchecked_suicide":
                            funds = int(row[7])
                            if funds < 0:
                                funds = 0
                            timestamp = int(row[2])

                        elif attack == "unchecked_delegatecall":
                            break

                        elif attack == "parity_wallet_hack_1":
                            funds = int(row[7])
                            timestamp = int(row[4])

                        elif attack == "parity_wallet_hack_2":
                            funds = int(row[8])
                            if funds < 0:
                                funds = 0
                            timestamp = int(row[4])

                        elif attack == "short_address":
                            break

                        elif attack == "dos_with_unexpected_throw":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        elif attack == "dos_with_block_gas_limit":
                            funds = int(row[7])
                            timestamp = int(row[2])

                        elif attack == "timestamp_dependence":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        elif attack == "transaction_state_dependence":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        elif attack == "block_state_dependence":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        elif attack == "block_stuffing":
                            break

                        elif attack == "insufficient_gas":
                            funds = int(row[6])
                            timestamp = int(row[2])

                        ether[attack].append(funds)
                        ether_total += funds
                        d = datetime.fromtimestamp(timestamp)
                        one_eth_to_usd = get_one_eth_to_usd(timestamp)
                        if not d.strftime("%Y-%m-%d") in timeline[attack]:
                            timeline[attack][d.strftime("%Y-%m-%d")] = {
                                "transactions": 1,
                                "usd": Web3.fromWei(funds, 'ether') * decimal.Decimal(float(one_eth_to_usd))
                            }
                        else:
                            timeline[attack][d.strftime("%Y-%m-%d")]["transactions"] += 1
                            timeline[attack][d.strftime("%Y-%m-%d")]["usd"] += Web3.fromWei(funds, 'ether') * decimal.Decimal(float(one_eth_to_usd))

    """print(" \t \t \t \t \t \t \t \t Leaked Ether \t Locked Ether \t Leaked Tokens")
    print("------------------------------------------------------------------------------------------------------------")
    print("Number of reentrancy vulnerable contracts: \t \t \t "+str(round(Web3.fromWei(sum(ether["reentrancy"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of cross-function reentrancy vulnerable contracts: \t "+str(round(Web3.fromWei(sum(ether["cross_function_reentrancy"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of delegated reentrancy vulnerable contracts: \t \t "+str(round(Web3.fromWei(sum(ether["delegated_reentrancy"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of create-based reentrancy vulnerable contracts: \t "+str(round(Web3.fromWei(sum(ether["create_based_reentrancy"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of ERC-777 reentrancy vulnerable contracts: \t \t "+str(round(Web3.fromWei(sum(ether["erc777_reentrancy"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of unhandled exception vulnerable contracts: \t \t \t \t 0 \t \t "+str(round(sum(ether["unhandled_exception"])))+" \t \t 0")
    print("Number of transaction order dependence vulnerable contracts: \t "+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of block state dependence vulnerable contracts: \t \t "+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of timestamp dependence vulnerable contracts: \t \t "+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of transaction state dependence vulnerable contracts: \t "+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of call stack depth vulnerable contracts: \t \t "+" \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["call_stack_depth"]), 'ether')))+" \t \t 0")
    print("Number of integer overflow addition vulnerable contracts: \t "+" \t \t "+str(round(Web3.fromWei(sum(ether["integer_overflow_addition"]), 'ether')))+" \t \t 0 \t \t ")
    print("Number of integer overflow multiplication vulnerable contracts:  "+" \t \t "+str(round(Web3.fromWei(sum(ether["integer_overflow_multiplication"]), 'ether')))+" \t \t 0 \t \t ")
    print("Number of integer underflow vulnerable contracts: \t \t "+" \t \t "+str(round(Web3.fromWei(sum(ether["integer_underflow"]), 'ether')))+" \t \t 0 \t \t ")
    print("Number of DoS with unexpected throw vulnerable contracts: \t "+" \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["dos_with_unexpected_throw"]), 'ether'))))
    print("Number of DoS with block gas limit vulnerable contracts: \t "+" \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["dos_with_block_gas_limit"]), 'ether'))))
    print("Number of short address vulnerable contracts: \t \t \t "+" \t \t 0 \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["short_address"]), 'ether'))))
    print("Number of unchecked delegatecall vulnerable contracts: \t \t "+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of unchecked suicide vulnerable contracts: \t \t "+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of Parity wallet hack 1 vulnerable contracts: \t \t "+" \t \t "+str(round(Web3.fromWei(sum(ether["parity_wallet_hack_1"]), 'ether')))+" \t \t 0 \t \t 0")
    print("Number of Parity wallet hack 2 vulnerable contracts: \t \t "+" \t \t 0 \t \t "+str(round(Web3.fromWei(sum(ether["parity_wallet_hack_2"]), 'ether')))+" \t \t 0")
    print("Number of block stuffing contracts: \t \t "+" \t \t 0 \t \t 0 \t \t 0")
    print("Number of insufficient gas vulnerable contracts: \t \t "+" \t \t 0 \t \t 0 \t \t 0")
    print("------------------------------------------------------------------------------------------------------------")
    print("Total number of vulnerable contracts: \t \t \t \t "+str(round(Web3.fromWei(ether_total, 'ether'))))"""

    if os.path.isdir('timeline'):
        shutil.rmtree('timeline')
    os.mkdir('timeline')

    for attack in timeline:
        with open('timeline/'+attack+'_timelime.csv', 'w', newline='') as csvfile:
            writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
            writer.writerow(['Timestamp', 'Transactions', 'USD'])
            timeline[attack] = OrderedDict(sorted(timeline[attack].items(), key=lambda t: t[0]))
            for date in timeline[attack]:
                writer.writerow([date, timeline[attack][date][attack], round(timeline[attack][date]["usd"])])
