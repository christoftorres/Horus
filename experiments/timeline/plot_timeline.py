#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import matplotlib
import seaborn

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

import matplotlib.dates as mdates
from matplotlib.dates import DateFormatter
from datetime import datetime


from collections import OrderedDict

import math
import os
import csv

plt.rcParams['text.latex.preamble']=[r"\usepackage{lmodern}"]
params = {'text.usetex' : True,
          'font.size' : 9,
          'font.family' : 'lmodern',
          }
plt.rcParams.update(params)


timeline = {
    "reentrancy": {},
    "parity_wallet_hacks": {},
    "unhandled_exception": {},
    "short_address": {},
    "integer_overflow": {}
}


from web3 import Web3
from datetime import datetime
import requests

import decimal

cache = {}

prices = requests.get("https://api.coingecko.com/api/v3/coins/ethereum/market_chart/range?vs_currency=usd&from=1392577232&to=1600908660").json()["prices"]

def get_one_eth_to_usd(timestamp):
    timestamp *= 1000
    one_eth_to_usd = prices[-1][1]
    for index, _ in enumerate(prices):
        if index < len(prices)-1:
            if prices[index][0] <= timestamp and timestamp <= prices[index+1][0]:
                one_eth_to_usd = prices[index][1]
                break
    return one_eth_to_usd

def round_up(n, decimals=0):
    multiplier = 10 ** decimals
    return math.ceil(n * multiplier) / multiplier

def magnitude(value):
    if (value == 0): return 0
    return int(math.floor(math.log10(round_up(abs(value)))))

def load_data(filename, row):
    series = pd.read_csv(filename)
    date_min = series['Timestamp'][0] if len(series['Timestamp']) > 0 else 0
    date_max = series['Timestamp'][len(series)-1] if len(series['Timestamp']) > 0 else 0
    data = {'Timestamp': [], 'Transactions': [], 'USD': []}
    for d in pd.date_range(start=date_min, end=date_max):
        t = d.strftime('%Y-%m-%d')
        for i in range(len(series)):
            if t == series['Timestamp'][i]:
                data['Timestamp'].append(t)
                data['Transactions'].append(row)
                data['USD'].append(np.pi*8*magnitude(series['USD'][i]))
    data['Timestamp'] = [datetime.strptime(d, "%Y-%m-%d") for d in data['Timestamp']]
    return data

matplotlib.use('Agg')

seaborn.set_style("whitegrid", {'axes.grid': False})
flatui = ["#3498db"]
seaborn.set_palette(flatui)

series1 = load_data('reentrancy_timelime.csv', 4)
series2 = load_data('parity_wallet_hacks_timelime.csv', 3)
series3 = load_data('integer_overflow_timelime.csv', 1)
series4 = load_data('unhandled_exception_timelime.csv', 0)
series5 = load_data('short_address_timelime.csv', 2)

fig, ax = plt.subplots()

ax.scatter('Timestamp', 'Transactions', data=series1, marker='.', s=5, linewidths=1)
ax.scatter('Timestamp', 'Transactions', data=series1, linewidths=1, s=series1['USD'], alpha=0.3)

ax.scatter('Timestamp', 'Transactions', data=series2, marker='.', s=5, linewidths=1)
scatter = ax.scatter('Timestamp', 'Transactions', data=series2, linewidths=1, s=series2['USD'], alpha=0.3)

ax.scatter('Timestamp', 'Transactions', data=series3, marker='.', s=5, linewidths=1)
ax.scatter('Timestamp', 'Transactions', data=series3, linewidths=1, s=series3['USD'], alpha=0.3)

ax.scatter('Timestamp', 'Transactions', data=series4, marker='.', s=5, linewidths=1)
ax.scatter('Timestamp', 'Transactions', data=series4, linewidths=1, s=series4['USD'], alpha=0.3)

ax.scatter('Timestamp', 'Transactions', data=series5, marker='.', s=5, linewidths=1)
ax.scatter('Timestamp', 'Transactions', data=series5, linewidths=1, s=series5['USD'], alpha=0.3)


ax.get_xaxis().set_major_formatter(mdates.DateFormatter("%Y"))

plt.setp(ax.get_xticklabels(), rotation=45)

ax.annotate('DAO Hack', (datetime.fromtimestamp(1466121600), 4), xytext=(15, 15),
            textcoords='offset points', size=6, arrowprops=dict(facecolor='black', edgecolor='black', arrowstyle='-|>'))

ax.annotate('Parity Wallet Hack 1', (datetime.fromtimestamp(1499644800), 3), xytext=(10, 10),
            textcoords='offset points', size=6, arrowprops=dict(facecolor='black', edgecolor='black', arrowstyle='-|>'))

ax.annotate('Parity Wallet Hack 2', (datetime.fromtimestamp(1509926400), 3), xytext=(10, -12),
            textcoords='offset points', size=6, arrowprops=dict(facecolor='black', edgecolor='black', arrowstyle='-|>'))

ax.annotate('SpankChain Hack', (datetime.fromtimestamp(1539043200), 4), xytext=(15, 15),
            textcoords='offset points', size=6, arrowprops=dict(facecolor='black', edgecolor='black', arrowstyle='-|>'))

ax.annotate('Uniswap \& Lendf.me Hacks', (datetime.fromtimestamp(1587171499), 4), xytext=(-60, -15),
            textcoords='offset points', size=6, arrowprops=dict(facecolor='black', edgecolor='black', arrowstyle='-|>'))

ax.annotate('King of the Ether Throne', (datetime.fromtimestamp(1454716800), 0), xytext=(5, 10),
            textcoords='offset points', size=6, arrowprops=dict(facecolor='black', edgecolor='black', arrowstyle='-|>'))

ax.annotate('BeautyChain Hack', (datetime.fromtimestamp(1524355200), 1), xytext=(5, 8),
            textcoords='offset points', size=6, arrowprops=dict(facecolor='black', edgecolor='black', arrowstyle='-|>'))

ax.annotate('SMT Token Hack', (datetime.fromtimestamp(1524614400), 1), xytext=(10, -10),
            textcoords='offset points', size=6, arrowprops=dict(facecolor='black', edgecolor='black', arrowstyle='-|>'))



ax.set_ylim(-0.5, 4.5)

plt.yticks([4, 3, 1, 0, 2], [
    r'Reentrancy'+'\n'+r'{\tiny Mean: \$'+"{:,.0f}".format(int(np.mean(pd.read_csv('reentrancy_timelime.csv')['USD'])))+r', Max: \$'+"{:,.0f}".format(np.max(pd.read_csv('reentrancy_timelime.csv')['USD']))+r'}',
    r'Parity Wallet Hacks'+'\n'+r'{\tiny Mean: \$'+"{:,.0f}".format(int(np.mean(pd.read_csv('parity_wallet_hacks_timelime.csv')['USD'])))+r', Max: \$'+"{:,.0f}".format(np.max(pd.read_csv('parity_wallet_hacks_timelime.csv')['USD']))+r'}',
    r'Integer Overflow',
    r'Unhandled Exception'+'\n'+r'{\tiny Mean: \$'+"{:,.0f}".format(int(np.mean(pd.read_csv('unhandled_exception_timelime.csv')['USD'])))+r', Max: \$'+"{:,.0f}".format(np.max(pd.read_csv('unhandled_exception_timelime.csv')['USD']))+r'}',
    r'Short Address',
])

kw = dict(prop="sizes", color="#3498db", fmt=r"\${x:,.0f}",
          func=lambda s: 10**(s/np.pi/8))
ax.legend(*scatter.legend_elements(**kw),
                    loc="upper left", title="", bbox_to_anchor=[0.0, 0.825])

ratio = 0.3
xleft, xright = ax.get_xlim()
ybottom, ytop = ax.get_ylim()
# the abs method is used to make sure that all numbers are positive
# because x and y axis of an axes maybe inversed.
ax.set_aspect(abs((xright-xleft)/(ybottom-ytop))*ratio)

ax.xaxis.set_tick_params(rotation=0)

plt.tight_layout()
plt.savefig("attack_timeline.pdf", dpi=1000, bbox_inches='tight')
