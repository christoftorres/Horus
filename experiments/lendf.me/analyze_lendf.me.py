#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import csv
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.dates as mdates
from matplotlib.ticker import FuncFormatter

from web3 import Web3
from datetime import datetime
from matplotlib.dates import DateFormatter
from pandas.plotting import register_matplotlib_converters
register_matplotlib_converters()

txs = []
amount = []
timestamps = []

borrow_txs = []
borrow_usd = []
borrow_amount = []
borrow_timestamps = []

with open('results/ERC777Reentrancy.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter='\t')
    for row in reader:
        txs.append(row[0])
        amount.append(int(row[4]) / 100000000)
        timestamps.append(datetime.utcfromtimestamp(int(row[1])))
    print("Found "+str(len(txs))+" transactions")
    print("Total amount of imBTC tokens: "+str(sum(amount)))
    print("Start of the attack: "+str(timestamps[0]))
    print("End of the attack: "+str(timestamps[-1]))
    print("Minimum amount: "+str(min(amount)))
    print("Maximum amount: "+str(max(amount)))
    print()

tokens = {}
tokens_usd = {}

with open('results/LendfmeHack.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter='\t')
    for row in reader:
        borrow_txs.append(row[0])

        rate = None
        decimals = None
        if row[3] == "0x06af07097c9eeb7fd685c692751d5c66db49c215":
            name = "CHAI"
            rate = 1.01480311
            decimals = 1000000000000000000
        if row[3] == "0x0316eb71485b0ab14103307bf65a021042c6d380":
            name = "HBTC"
            rate = 7261.73051
            decimals = 1000000000000000000
        if row[3] == "0xdf574c24545e5ffecb9a659c229253d4111d87e1":
            name = "HUSD"
            rate = 0.99899009
            decimals = 100000000
        if row[3] == "0x4fabb145d64652a948d72533023f6e7a623c7c53":
            name = "BUSD"
            rate = 0.99979794
            decimals = 1000000000000000000
        if row[3] == "0x8e870d67f660d95d5be530380d0ec0bd388289e1":
            name = "PAX"
            rate = 0.99933102
            decimals = 1000000000000000000
        if row[3] == "0x0000000000085d4780b73119b644ae5ecd22b376":
            name = "TUSD"
            rate = 0.99811398
            decimals = 1000000000000000000
        if row[3] == "0xa0b86991c6218b36c1d19d4a2e9eb0ce3606eb48":
            name = "USDC"
            rate = 0.99868777
            decimals = 1000000
        if row[3] == "0xdac17f958d2ee523a2206206994597c13d831ec7":
            name = "USDT"
            rate = 0.99979794
            decimals = 1000000
        if row[3] == "0xeb269732ab75a6fd61ea60b06fe994cd32a83549":
            name = "USDx"
            rate = 0.99908362
            decimals = 1000000000000000000
        if row[3] == "0x2260fac5e5542a773aa44fbcfedf7c193bc2c599":
            name = "WBTC"
            rate = 7263.0222
            decimals = 100000000
        if row[3] == "0xc02aaa39b223fe8d0a0e5c4f27ead9083c756cc2":
            name = "WETH"
            rate = 186.962611
            decimals = 1000000000000000000

        price = int(row[4]) / decimals * rate
        print(price)
        print(row[3])
        borrow_usd.append(price)

        if name not in tokens_usd:
            tokens_usd[name] = 0
        tokens_usd[name] += price

        borrow_amount.append(int(row[4]))
        if row[3] not in tokens:
            tokens[row[3]] = 0
        tokens[row[3]] += int(row[4])
        borrow_timestamps.append(datetime.utcfromtimestamp(int(row[2])))
    print("Found "+str(len(borrow_txs))+" transactions")
    print("Total amount of borrowed tokens: "+str(sum(borrow_amount)))
    print("Start of the borrowing: "+str(borrow_timestamps[0]))
    print("End of the borrowing: "+str(borrow_timestamps[-1]))

total = 0
print()
for t in tokens_usd:
    total += tokens_usd[t]
    print(t)
    print(tokens_usd[t])
    print()

print("imBTC")
print(max(amount) * 7261.79542)
total += max(amount) * 7261.79542

print("Total USD: "+str(total))

def millions(x, pos):
    'The two args are the value and tick position'
    return '%1.0fM' % (x * 1e-6)

formatter2 = FuncFormatter(millions)

fig, ax = plt.subplots(figsize=(5, 3))
ax.plot(timestamps, amount, label='Deposit', marker=".", linewidth=1)
ax2 = ax.twinx()
ax2.plot(borrow_timestamps, borrow_usd, label='Borrow', marker=".", color='#ff7f0e', linewidth=1)
ax2.set_ylabel('USD', color='#ff7f0e')
ax2.tick_params(axis='y', labelcolor='#ff7f0e')
ax2.get_yaxis().get_major_formatter().set_useOffset(False)
ax2.get_yaxis().get_major_formatter().set_scientific(False)
ax2.yaxis.set_major_formatter(formatter2)
ax2.set_ylim(ymax=11000000)
leg = ax2.legend(frameon=False)
leg.set_bbox_to_anchor([0.9875, 0.9])
ax.xaxis_date()
locator = mdates.AutoDateLocator()
formatter = mdates.ConciseDateFormatter(locator, offset_formats=['', '%Y', '%Y-%b', '%Y-%b-%d', '%d %B %Y', '%Y-%b-%d %H:%M'])
ax.xaxis.set_major_locator(locator)
ax.xaxis.set_major_formatter(formatter)
ax.set_ylabel("imBTC", color='#1f77b4')
ax.tick_params(axis='y', labelcolor='#1f77b4')
ax.set_xlabel("Time (UTC)")
ax.get_yaxis().get_major_formatter().set_useOffset(False)
ax.get_yaxis().get_major_formatter().set_scientific(False)
ax.grid(True)
ax.legend(frameon=False)
plt.gcf().autofmt_xdate()
plt.xticks(rotation=0, ha="center")

fig.tight_layout()

plt.savefig("lendf.me_timeline.pdf", dpi=1000, bbox_inches='tight')
