
import csv
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

c = 0
count = 3362876
deployments = dict()
header_skipped = False
with open('deployment_timestamps.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    for row in csv_reader:
        if not header_skipped:
            header_skipped = True
            continue
        timestamp = datetime.utcfromtimestamp(int(row[0])).date()
        #print(timestamp)
        if timestamp not in deployments:
            deployments[timestamp] = 0
        deployments[timestamp] += 1
        c += 1
        if c % 10000 == 0:
            print(c/count*100)

attacks = dict()

processed_transactions = dict()
with open('reentrancy_results.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    for row in csv_reader:
        transaction = row[0]
        if transaction in processed_transactions:
            continue
        timestamp = datetime.utcfromtimestamp(int(row[1])).date()
        if timestamp not in attacks:
            attacks[timestamp] = 0
        attacks[timestamp] += 1
        if not timestamp in deployments:
            deployments[timestamp] = 0
        processed_transactions[transaction] = True
print("Reentrancy: "+str(len(processed_transactions)))

processed_transactions = dict()
with open('parity_wallet_hack_1_results.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    for row in csv_reader:
        transaction = row[1]
        if transaction in processed_transactions:
            continue
        timestamp = datetime.utcfromtimestamp(int(row[3])).date()
        if timestamp not in attacks:
            attacks[timestamp] = 0
        attacks[timestamp] += 1
        if not timestamp in deployments:
            deployments[timestamp] = 0
        processed_transactions[transaction] = True
print("Parity wallet hack 1: "+str(len(processed_transactions)))

processed_transactions = dict()
with open('parity_wallet_hack_2_results.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    for row in csv_reader:
        transaction = row[1]
        if transaction in processed_transactions:
            continue
        timestamp = datetime.utcfromtimestamp(int(row[3])).date()
        if timestamp not in attacks:
            attacks[timestamp] = 0
        attacks[timestamp] += 1
        if not timestamp in deployments:
            deployments[timestamp] = 0
        processed_transactions[transaction] = True
print("Parity wallet hack 2: "+str(len(processed_transactions)))

from web3 import Web3
w3 = Web3(Web3.HTTPProvider("http://"+"pf.uni.lux"+":"+str(8545)))
blocks = []
blocks_file = open("blocks.txt", "w")
processed_transactions = dict()
with open('integer_overflow_results.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    for row in csv_reader:
        transaction = row[0]
        if transaction in processed_transactions:
            continue
        timestamp = datetime.utcfromtimestamp(int(row[1])).date()
        amount = int(row[-1])
        if timestamp not in attacks:
            attacks[timestamp] = 0
        attacks[timestamp] += 1
        if not timestamp in deployments:
            deployments[timestamp] = 0
        print(transaction)
        block = w3.eth.getTransaction(transaction)["blockNumber"]
        if block not in blocks:
            blocks.append(block)
            blocks_file.write(str(block)+"\n")
        processed_transactions[transaction] = True
print("Integer overflow: "+str(len(processed_transactions)))
print(len(blocks))
blocks_file.close()

processed_transactions = dict()
with open('unhandled_exception_results.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    for row in csv_reader:
        transaction = row[0]
        if transaction in processed_transactions:
            continue
        timestamp = datetime.utcfromtimestamp(int(row[1])).date()
        if timestamp not in attacks:
            attacks[timestamp] = 0
        attacks[timestamp] += 1
        if not timestamp in deployments:
            deployments[timestamp] = 0
        processed_transactions[transaction] = True
print("Unhandled exception: "+str(len(processed_transactions)))

processed_transactions = dict()
with open('short_address_results.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file)
    for row in csv_reader:
        transaction = row[0]
        if transaction in processed_transactions:
            continue
        timestamp = datetime.utcfromtimestamp(int(row[1])).date()
        if timestamp not in attacks:
            attacks[timestamp] = 0
        attacks[timestamp] += 1
        if not timestamp in deployments:
            deployments[timestamp] = 0
        processed_transactions[transaction] = True
print("Short address: "+str(len(processed_transactions)))

for timestamp in deployments:
    if not timestamp in attacks:
        attacks[timestamp] = 0

print(len(attacks))
print(len(deployments))

deployments = collections.OrderedDict(sorted(deployments.items()))
timestamps = list(deployments.keys())
daily_deployments = list(deployments.values())

attacks = collections.OrderedDict(sorted(attacks.items()))
assert(timestamps == list(attacks.keys()))
daily_attacks = list(attacks.values())

fig, ax1 = plt.subplots(figsize=(8, 3))

ax1.plot(timestamps, daily_deployments, label='Deployments', linewidth=1, color='#1f77b4')
ax1.fill_between(timestamps, daily_deployments, color='#1f77b4', alpha=0.30)
ax1.tick_params(axis='y', labelcolor='#1f77b4')

ax2 = ax1.twinx()
ax2.plot(timestamps, daily_attacks, label='Attacks', linewidth=1, color='#ff7f0e')
ax2.fill_between(timestamps, daily_attacks, color='#ff7f0e', alpha=0.30)
ax2.tick_params(axis='y', labelcolor='#ff7f0e')
leg = ax2.legend(frameon=False)
leg.set_bbox_to_anchor([0.172, 0.9])

ax1.xaxis_date()
locator = mdates.AutoDateLocator()
formatter = mdates.ConciseDateFormatter(locator, offset_formats=['', '%Y', '%Y-%b', '%Y-%b-%d', '%d %B %Y', '%Y-%b-%d %H:%M'])
ax1.xaxis.set_major_locator(locator)
ax1.xaxis.set_major_formatter(formatter)
#ax.set_ylabel("")
#ax.set_xlabel("Time (UTC)")
ax1.grid(True)
ax1.legend(frameon=False, loc='upper left')
#plt.yscale('log')
plt.gcf().autofmt_xdate()
plt.xticks(rotation=0, ha="center")

fig.tight_layout()

plt.savefig("deployments.pdf", dpi=1000, bbox_inches='tight')
