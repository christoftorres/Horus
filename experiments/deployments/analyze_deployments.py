#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import csv
import json
import collections
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.dates as mdates

from web3 import Web3
from datetime import datetime
from matplotlib.dates import DateFormatter
from pandas.plotting import register_matplotlib_converters

register_matplotlib_converters()

w3 = Web3(Web3.HTTPProvider("http://"+"localhost"+":"+str(8545)))

deployments = dict()
attacks = dict()

with open('deployment_timestamps.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    for row in csv_reader:
        timestamp = datetime.utcfromtimestamp(int(row[0])).date()
        if timestamp not in deployments:
            deployments[timestamp] = 0
        deployments[timestamp] += 1

if os.path.exists('reentrancy_attack_timestamps.csv'):
    with open('reentrancy_attack_timestamps.csv', 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        for row in csv_reader:
            timestamp = datetime.utcfromtimestamp(int(row[0])).date()
            if timestamp not in attacks:
                attacks[timestamp] = 0
            attacks[timestamp] += 1
else:
    with open('../results/reentrancy.json', 'r') as json_file:
        timestamps = []
        processed_transactions = dict()
        results = json.load(json_file)
        for contract in results:
            for transaction in list(results[contract]):
                if transaction in processed_transactions:
                    continue
                block_number = w3.eth.getTransaction(transaction)["blockNumber"]
                timestamp = w3.eth.getBlock(block_number, False)["timestamp"]
                timestamps.append(timestamp)
                timestamp = datetime.utcfromtimestamp(int(timestamp)).date()
                if timestamp not in attacks:
                    attacks[timestamp] = 0
                attacks[timestamp] += 1
                if not timestamp in deployments:
                    deployments[timestamp] = 0
                processed_transactions[transaction] = True
        with open('reentrancy_attack_timestamps.csv', 'w') as csv_file:
            writer = csv.writer(csv_file)
            for timestamp in timestamps:
                writer.writerow([timestamp])

if os.path.exists('parity_wallet_hack_1_attack_timestamps.csv'):
    with open('parity_wallet_hack_1_attack_timestamps.csv', 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        for row in csv_reader:
            timestamp = datetime.utcfromtimestamp(int(row[0])).date()
            if timestamp not in attacks:
                attacks[timestamp] = 0
            attacks[timestamp] += 1
else:
    with open('../results/parity_wallet_hack_1.json', 'r') as json_file:
        timestamps = []
        processed_transactions = dict()
        results = json.load(json_file)
        for contract in results:
            for transaction in list(results[contract]):
                if transaction in processed_transactions:
                    continue
                block_number = w3.eth.getTransaction(transaction)["blockNumber"]
                timestamp = w3.eth.getBlock(block_number, False)["timestamp"]
                timestamps.append(timestamp)
                timestamp = datetime.utcfromtimestamp(int(timestamp)).date()
                if timestamp not in attacks:
                    attacks[timestamp] = 0
                attacks[timestamp] += 1
                if not timestamp in deployments:
                    deployments[timestamp] = 0
                processed_transactions[transaction] = True
        with open('parity_wallet_hack_1_attack_timestamps.csv', 'w') as csv_file:
            writer = csv.writer(csv_file)
            for timestamp in timestamps:
                writer.writerow([timestamp])

if os.path.exists('parity_wallet_hack_2_attack_timestamps.csv'):
    with open('parity_wallet_hack_2_attack_timestamps.csv', 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        for row in csv_reader:
            timestamp = datetime.utcfromtimestamp(int(row[0])).date()
            if timestamp not in attacks:
                attacks[timestamp] = 0
            attacks[timestamp] += 1
else:
    with open('../results/parity_wallet_hack_2.json', 'r') as json_file:
        timestamps = []
        processed_transactions = dict()
        results = json.load(json_file)
        for contract in results:
            for transaction in list(results[contract]):
                if transaction in processed_transactions:
                    continue
                block_number = w3.eth.getTransaction(transaction)["blockNumber"]
                timestamp = w3.eth.getBlock(block_number, False)["timestamp"]
                timestamps.append(timestamp)
                timestamp = datetime.utcfromtimestamp(int(timestamp)).date()
                if timestamp not in attacks:
                    attacks[timestamp] = 0
                attacks[timestamp] += 1
                if not timestamp in deployments:
                    deployments[timestamp] = 0
                processed_transactions[transaction] = True
        with open('parity_wallet_hack_2_attack_timestamps.csv', 'w') as csv_file:
            writer = csv.writer(csv_file)
            for timestamp in timestamps:
                writer.writerow([timestamp])

if os.path.exists('integer_overflow_attack_timestamps.csv'):
    with open('integer_overflow_attack_timestamps.csv', 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        for row in csv_reader:
            timestamp = datetime.utcfromtimestamp(int(row[0])).date()
            if timestamp not in attacks:
                attacks[timestamp] = 0
            attacks[timestamp] += 1
else:
    with open('../results/integer_overflow.json', 'r') as json_file:
        timestamps = []
        processed_transactions = dict()
        results = json.load(json_file)
        for contract in results:
            for transaction in list(results[contract]):
                if transaction in processed_transactions:
                    continue
                block_number = w3.eth.getTransaction(transaction)["blockNumber"]
                timestamp = w3.eth.getBlock(block_number, False)["timestamp"]
                timestamps.append(timestamp)
                timestamp = datetime.utcfromtimestamp(int(timestamp)).date()
                if timestamp not in attacks:
                    attacks[timestamp] = 0
                attacks[timestamp] += 1
                if not timestamp in deployments:
                    deployments[timestamp] = 0
                processed_transactions[transaction] = True
        with open('integer_overflow_attack_timestamps.csv', 'w') as csv_file:
            writer = csv.writer(csv_file)
            for timestamp in timestamps:
                writer.writerow([timestamp])

if os.path.exists('unhandled_exception_attack_timestamps.csv'):
    with open('unhandled_exception_attack_timestamps.csv', 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        for row in csv_reader:
            timestamp = datetime.utcfromtimestamp(int(row[0])).date()
            if timestamp not in attacks:
                attacks[timestamp] = 0
            attacks[timestamp] += 1
else:
    with open('../results/unhandled_exception.json', 'r') as json_file:
        timestamps = []
        processed_transactions = dict()
        results = json.load(json_file)
        for contract in results:
            for transaction in list(results[contract]):
                if transaction in processed_transactions:
                    continue
                block_number = w3.eth.getTransaction(transaction)["blockNumber"]
                timestamp = w3.eth.getBlock(block_number, False)["timestamp"]
                timestamps.append(timestamp)
                timestamp = datetime.utcfromtimestamp(int(timestamp)).date()
                if timestamp not in attacks:
                    attacks[timestamp] = 0
                attacks[timestamp] += 1
                if not timestamp in deployments:
                    deployments[timestamp] = 0
                processed_transactions[transaction] = True
        with open('unhandled_exception_attack_timestamps.csv', 'w') as csv_file:
            writer = csv.writer(csv_file)
            for timestamp in timestamps:
                writer.writerow([timestamp])

if os.path.exists('short_address_attack_timestamps.csv'):
    with open('short_address_attack_timestamps.csv', 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        for row in csv_reader:
            timestamp = datetime.utcfromtimestamp(int(row[0])).date()
            if timestamp not in attacks:
                attacks[timestamp] = 0
            attacks[timestamp] += 1
else:
    with open('../results/short_address.json', 'r') as json_file:
        timestamps = []
        processed_transactions = dict()
        results = json.load(json_file)
        for contract in results:
            for transaction in list(results[contract]):
                if transaction in processed_transactions:
                    continue
                block_number = w3.eth.getTransaction(transaction)["blockNumber"]
                timestamp = w3.eth.getBlock(block_number, False)["timestamp"]
                timestamps.append(timestamp)
                timestamp = datetime.utcfromtimestamp(int(timestamp)).date()
                if timestamp not in attacks:
                    attacks[timestamp] = 0
                attacks[timestamp] += 1
                if not timestamp in deployments:
                    deployments[timestamp] = 0
                processed_transactions[transaction] = True
        with open('short_address_attack_timestamps.csv', 'w') as csv_file:
            writer = csv.writer(csv_file)
            for timestamp in timestamps:
                writer.writerow([timestamp])

for timestamp in deployments:
    if not timestamp in attacks:
        attacks[timestamp] = 0

deployments = collections.OrderedDict(sorted(deployments.items()))
timestamps = list(deployments.keys())
daily_deployments = list(deployments.values())

attacks = collections.OrderedDict(sorted(attacks.items()))
assert(timestamps == list(attacks.keys()))
daily_attacks = list(attacks.values())

daily_attacks = list()
d = collections.deque(maxlen=7)
for timestamp in attacks:
    d.append(attacks[timestamp])
    print(np.mean(d))
    daily_attacks.append(np.mean(d))

daily_deployments = list()
d = collections.deque(maxlen=7)
for timestamp in deployments:
    d.append(deployments[timestamp])
    print(np.mean(d))
    daily_deployments.append(np.mean(d))

fig, ax1 = plt.subplots(figsize=(8, 2.5))

ax1.plot(timestamps, daily_deployments, label='Deployments', linewidth=1, color='#1f77b4')
ax1.fill_between(timestamps, daily_deployments, color='#1f77b4', alpha=0.30)
ax1.tick_params(axis='y', labelcolor='#1f77b4')

ax2 = ax1.twinx()
ax2.plot(timestamps, daily_attacks, label='Attacks', linewidth=1, color='#ff7f0e')
ax2.fill_between(timestamps, daily_attacks, color='#ff7f0e', alpha=0.30)
ax2.tick_params(axis='y', labelcolor='#ff7f0e')
ax2.set_ylabel("Attacks", color='#ff7f0e')

ax1.xaxis_date()
locator = mdates.AutoDateLocator()
formatter = mdates.ConciseDateFormatter(locator, offset_formats=['', '%Y', '%Y-%b', '%Y-%b-%d', '%d %B %Y', '%Y-%b-%d %H:%M'])
ax1.xaxis.set_major_locator(locator)
ax1.xaxis.set_major_formatter(formatter)
ax1.set_ylabel("Deployments", color='#1f77b4')
ax1.grid(True)
plt.gcf().autofmt_xdate()
ax1.xaxis.set_tick_params(rotation=0)

fig.tight_layout()

plt.savefig("deployments_vs_attacks_weekly_average.pdf", dpi=1000, bbox_inches='tight')
