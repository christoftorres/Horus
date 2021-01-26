#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import csv
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.dates as mdates

from web3 import Web3
from datetime import datetime
from matplotlib.dates import DateFormatter
from pandas.plotting import register_matplotlib_converters
register_matplotlib_converters()

with open('results/UniswapHack.csv') as csvfile:
    reader = csv.reader(csvfile, delimiter='\t')

    txs = []
    amount = []
    profit = []
    timestamps = []

    for row in reader:
        if row[3] == '0x3212b29e33587a00fb1c83346f5dbfa69a458923':
            txs.append(row[0])
            amount.append(int(row[6]))
            profit.append(int(row[7]))
            timestamps.append(datetime.utcfromtimestamp(int(row[2])))
    print("Found "+str(len(txs))+" transactions")
    print("Total amount of ether: "+str(Web3.fromWei(sum(profit), 'ether'))+" ("+str(float(Web3.fromWei(sum(profit), 'ether'))*181.61)+" USD)")
    print("Start of the attacks: "+str(timestamps[0]))
    print("End of the attacks: "+str(timestamps[-1]))
    print("Minimum invested: "+str(Web3.fromWei(min(amount), 'ether'))+" ("+str(float(Web3.fromWei(min(amount), 'ether'))*181.61)+" USD)")
    print("Maximum invested: "+str(Web3.fromWei(max(amount), 'ether'))+" ("+str(float(Web3.fromWei(max(amount), 'ether'))*181.61)+" USD)")
    print("Minimum profit: "+str(Web3.fromWei(min(profit), 'ether'))+" ("+str(float(Web3.fromWei(min(profit), 'ether'))*181.61)+" USD)")
    print("Maximum profit: "+str(Web3.fromWei(max(profit), 'ether'))+" ("+str(float(Web3.fromWei(max(profit), 'ether'))*181.61)+" USD)")

    amount = [Web3.fromWei(e, 'ether') for e in amount]
    profit = [Web3.fromWei(e, 'ether') for e in profit]

    fig, ax = plt.subplots(figsize=(8, 3))
    ax.plot(timestamps, amount, label='Investment', marker='.', linewidth=1)
    ax.plot(timestamps, profit, label='Net Profit', marker='.', linewidth=1)
    ax.xaxis_date()
    locator = mdates.AutoDateLocator()
    formatter = mdates.ConciseDateFormatter(locator, offset_formats=['', '%Y', '%Y-%b', '%Y-%b-%d', '%d %B %Y', '%Y-%b-%d %H:%M'])
    ax.xaxis.set_major_locator(locator)
    ax.xaxis.set_major_formatter(formatter)
    ax.set_ylabel("ETH [log]")
    ax.set_xlabel("Time (UTC)")
    ax.grid(True)
    ax.legend(frameon=False)
    plt.yscale('log')
    plt.gcf().autofmt_xdate()
    plt.xticks(rotation=0, ha="center")

    fig.tight_layout()

    plt.savefig("uniswap_profit.pdf", dpi=1000, bbox_inches='tight')
