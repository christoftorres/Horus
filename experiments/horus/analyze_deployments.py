
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
with open('deployment_timestamps.csv') as csv_file:
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


deployments = collections.OrderedDict(sorted(deployments.items()))
timestamps = list(deployments.keys())
daily_deployments = list(deployments.values())

fig, ax = plt.subplots(figsize=(8, 3))
ax.plot(timestamps, daily_deployments, label='Deployments', linewidth=1)
ax.xaxis_date()
locator = mdates.AutoDateLocator()
formatter = mdates.ConciseDateFormatter(locator, offset_formats=['', '%Y', '%Y-%b', '%Y-%b-%d', '%d %B %Y', '%Y-%b-%d %H:%M'])
ax.xaxis.set_major_locator(locator)
ax.xaxis.set_major_formatter(formatter)
#ax.set_ylabel("")
#ax.set_xlabel("Time (UTC)")
ax.grid(True)
ax.legend(frameon=False)
#plt.yscale('log')
plt.gcf().autofmt_xdate()
plt.xticks(rotation=0, ha="center")

fig.tight_layout()

plt.savefig("deployments.pdf", dpi=1000, bbox_inches='tight')
