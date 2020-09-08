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
            if not attack.startswith("reentrancy"):
                continue
            with open(os.path.join(FOLDER, filename)) as file:
                reader = csv.reader(file)
                row_count = sum(1 for row in reader)
                file.seek(0)
                reader = csv.reader(file)
                contracts = {}
                with tqdm(total=row_count, unit=" contract", leave=False, smoothing=0.1) as pbar:
                    for row in reader:
                        contract = row[0]
                        if contract not in contracts:
                            try:
                                print(contract)
                                d = datetime.fromtimestamp(get_deployment_timestamp(contract))
                                if not d.strftime("%Y-%m-%d") in vulnerable_deployments[attack]:
                                    vulnerable_deployments[attack][d.strftime("%Y-%m-%d")] = 1
                                else:
                                    vulnerable_deployments[attack][d.strftime("%Y-%m-%d")] += 1
                                contracts[contract] = True
                            except Exception as e:
                                print(e)
                                pass
                        pbar.update(1)

    if os.path.isdir('deployments'):
        shutil.rmtree('deployments')
    os.mkdir('deployments')

    for attack in vulnerable_deployments:
        with open('deployments/'+attack+'.csv', 'w', newline='') as csvfile:
            writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
            writer.writerow(['Timestamp', 'Deployments'])
            vulnerable_deployments[attack] = OrderedDict(sorted(vulnerable_deployments[attack].items(), key=lambda t: t[0]))
            for date in vulnerable_deployments[attack]:
                writer.writerow([date, vulnerable_deployments[attack][date]])
