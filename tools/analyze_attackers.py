#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import csv

from web3 import Web3
from tqdm import tqdm

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

w3 = Web3(Web3.HTTPProvider("http://pf.uni.lux:8545"))

global cache
cache = {}

def get_sender(transaction_hash):
    global cache
    if transaction_hash in cache:
        return cache[transaction_hash]
    sender = str(w3.eth.getTransaction(transaction_hash)["from"]).lower()
    cache[transaction_hash] = sender
    return sender

if __name__ == '__main__':
    attackers = {}
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
                with tqdm(total=row_count, unit=" transaction", leave=False, smoothing=0.1) as pbar:
                    for row in reader:
                        attacker = get_sender(row[1])
                        if attacker not in attackers:
                            attackers[attacker] = {"timestamp": row[2], "attacks": set()}
                        attackers[attacker]["attacks"].add(row[1])
                        pbar.update(1)

    with open('attackers.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['Attacker', 'Timestamp', 'Attacks'])
        for attacker in attackers:
            writer.writerow([attacker, attackers[attacker]['timestamp'], len(attackers[attacker]['attacks'])])
