#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import csv
import requests

from tqdm import tqdm
from datetime import datetime
from collections import OrderedDict

FOLDER = "results"

vulnerable_deployments = {
    "reentrancy": {},
    "unhandled_exception": {},
    "transaction_order_dependence": {},
    "block_state_dependence": {},
    "timestamp_dependence": {},
    "transaction_state_dependence": {},
    "call_stack_depth": {},
    "integer_overflow": {},
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

def get_deployment_timestamp(contract):
    response = requests.get('http://api.etherscan.io/api?module=account&action=txlist&address='+contract+'&startblock=0&endblock=99999999&page=1&offset=1&sort=asc&apikey=VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU').json()
    if response['status'] == '1' and response['message'] == 'OK':
        return int(response["result"][0]["timeStamp"])
    else:
        print(response['result'])
    return None

if __name__ == '__main__':
    for filename in os.listdir(FOLDER):
        if filename.endswith(".csv"):
            attack = filename.split(".")[0]
            with open(os.path.join(FOLDER, filename)) as file:
                reader = csv.reader(file)
                row_count = sum(1 for row in reader)
                file.seek(0)
                reader = csv.reader(file)
                with tqdm(total=row_count, unit=" contract", leave=False, smoothing=0.1) as pbar:
                    contracts = {}
                    for row in reader:
                        contract = row[0]
                        if contract not in contracts:
                            try:
                                d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                if not d.strftime("%Y-%m-%d") in vulnerable_deployments[attack]:
                                    vulnerable_deployments[attack][d.strftime("%Y-%m-%d")] = 1
                                else:
                                    vulnerable_deployments[attack][d.strftime("%Y-%m-%d")] += 1
                            except Exception as e:
                                print(e)
                                pass
                        pbar.update(1)

    if os.path.isdir('deployments'):
        shutil.rmtree('deployments')
    os.mkdir('deployments')

    with open('deployments/reentrancy.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["reentrancy"] = OrderedDict(sorted(vulnerable_deployments["reentrancy"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["reentrancy"]:
            writer.writerow([date, vulnerable_deployments["reentrancy"][date]])
    with open('deployments/unhandled_exception.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["unhandled_exception"] = OrderedDict(sorted(vulnerable_deployments["unhandled_exception"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["unhandled_exception"]:
            writer.writerow([date, vulnerable_deployments["unhandled_exception"][date]])
    with open('deployments/transaction_order_dependence.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["transaction_order_dependence"] = OrderedDict(sorted(vulnerable_deployments["transaction_order_dependence"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["transaction_order_dependence"]:
            writer.writerow([date, vulnerable_deployments["transaction_order_dependence"][date]])
    with open('deployments/block_state_dependence.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["block_state_dependence"] = OrderedDict(sorted(vulnerable_deployments["block_state_dependence"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["block_state_dependence"]:
            writer.writerow([date, vulnerable_deployments["block_state_dependence"][date]])
    with open('deployments/timestamp_dependence.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["timestamp_dependence"] = OrderedDict(sorted(vulnerable_deployments["timestamp_dependence"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["timestamp_dependence"]:
            writer.writerow([date, vulnerable_deployments["timestamp_dependence"][date]])
    with open('deployments/transaction_state_dependence.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["transaction_state_dependence"] = OrderedDict(sorted(vulnerable_deployments["transaction_state_dependence"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["transaction_state_dependence"]:
            writer.writerow([date, vulnerable_deployments["transaction_state_dependence"][date]])
    with open('deployments/call_stack_depth.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["call_stack_depth"] = OrderedDict(sorted(vulnerable_deployments["call_stack_depth"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["call_stack_depth"]:
            writer.writerow([date, vulnerable_deployments["call_stack_depth"][date]])
    with open('deployments/integer_overflow.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["integer_overflow"] = OrderedDict(sorted(vulnerable_deployments["integer_overflow"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["integer_overflow"]:
            writer.writerow([date, vulnerable_deployments["integer_overflow"][date]])
    with open('deployments/integer_underflow.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["integer_underflow"] = OrderedDict(sorted(vulnerable_deployments["integer_underflow"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["integer_underflow"]:
            writer.writerow([date, vulnerable_deployments["integer_underflow"][date]])
    with open('deployments/dos_with_unexpected_throw.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["dos_with_unexpected_throw"] = OrderedDict(sorted(vulnerable_deployments["dos_with_unexpected_throw"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["dos_with_unexpected_throw"]:
            writer.writerow([date, vulnerable_deployments["dos_with_unexpected_throw"][date]])
    with open('deployments/dos_with_block_gas_limit.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["dos_with_block_gas_limit"] = OrderedDict(sorted(vulnerable_deployments["dos_with_block_gas_limit"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["dos_with_block_gas_limit"]:
            writer.writerow([date, vulnerable_deployments["dos_with_block_gas_limit"][date]])
    with open('deployments/short_address.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["short_address"] = OrderedDict(sorted(vulnerable_deployments["short_address"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["short_address"]:
            writer.writerow([date, vulnerable_deployments["short_address"][date]])
    with open('deployments/unchecked_delegatecall.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["unchecked_delegatecall"] = OrderedDict(sorted(vulnerable_deployments["unchecked_delegatecall"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["unchecked_delegatecall"]:
            writer.writerow([date, vulnerable_deployments["unchecked_delegatecall"][date]])
    with open('deployments/unchecked_suicide.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["unchecked_suicide"] = OrderedDict(sorted(vulnerable_deployments["unchecked_suicide"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["unchecked_suicide"]:
            writer.writerow([date, vulnerable_deployments["unchecked_suicide"][date]])
    with open('deployments/parity_wallet_hack_1.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["parity_wallet_hack_1"] = OrderedDict(sorted(vulnerable_deployments["parity_wallet_hack_1"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["parity_wallet_hack_1"]:
            writer.writerow([date, vulnerable_deployments["parity_wallet_hack_1"][date]])
    with open('deployments/parity_wallet_hack_2.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["parity_wallet_hack_2"] = OrderedDict(sorted(vulnerable_deployments["parity_wallet_hack_2"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["parity_wallet_hack_2"]:
            writer.writerow([date, vulnerable_deployments["parity_wallet_hack_2"][date]])
    with open('deployments/block_stuffing.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["block_stuffing"] = OrderedDict(sorted(vulnerable_deployments["block_stuffing"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["block_stuffing"]:
            writer.writerow([date, vulnerable_deployments["unchecked_signature"][date]])
    with open('deployments/insufficient_gas.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Timestamp', 'Deployments'])
        vulnerable_deployments["insufficient_gas"] = OrderedDict(sorted(vulnerable_deployments["insufficient_gas"].items(), key=lambda t: t[0]))
        for date in vulnerable_deployments["insufficient_gas"]:
            writer.writerow([date, vulnerable_deployments["insufficient_gas"][date]])
