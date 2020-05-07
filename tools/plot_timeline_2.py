import matplotlib
import seaborn

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

import matplotlib.dates as mdates
from matplotlib.dates import DateFormatter
from datetime import datetime

import math

def magnitude(value):
    if (value == 0): return 0
    return int(math.floor(math.log10(abs(value))))

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
                #data['USD'].append(series['USD'][i])
                data['USD'].append(np.pi*20*magnitude(series['USD'][i]))
    data['Timestamp'] = [datetime.strptime(d, "%Y-%m-%d") for d in data['Timestamp']]
    return data

matplotlib.use('Agg')

#plt.figure(figsize=(10, 2))

#seaborn.set(font_scale=2.0)
seaborn.set_style("whitegrid", {'axes.grid': False})

series1 = load_data('reentrancy_timelime.csv', 0)
series2 = load_data('integer_overflow_timelime.csv', 1)
series3 = load_data('integer_underflow_timelime.csv', 2)
series4 = load_data('parity_wallet_hack_1_timelime.csv', 3)
series5 = load_data('parity_wallet_hack_2_timelime.csv', 4)

print(series1['USD'])

fig, ax = plt.subplots()
ax.scatter('Timestamp', 'Transactions', data=series1, marker='.', linewidths=1, color='blue')
scatter = ax.scatter('Timestamp', 'Transactions', data=series1, linewidths=1, color='blue', s=series1['USD'], alpha=0.5)
ax.scatter('Timestamp', 'Transactions', data=series2, marker='.', linewidths=1, color='blue')
ax.scatter('Timestamp', 'Transactions', data=series2, linewidths=1, color='blue', s=series2['USD'], alpha=0.5)
ax.scatter('Timestamp', 'Transactions', data=series3, marker='.', linewidths=1, color='blue')
ax.scatter('Timestamp', 'Transactions', data=series3, linewidths=1, color='blue', s=series3['USD'], alpha=0.5)
ax.scatter('Timestamp', 'Transactions', data=series4, marker='.', linewidths=1, color='blue')
ax.scatter('Timestamp', 'Transactions', data=series4, linewidths=1, color='blue', s=series4['USD'], alpha=0.5)
ax.scatter('Timestamp', 'Transactions', data=series5, marker='.', linewidths=1, color='blue')
ax.scatter('Timestamp', 'Transactions', data=series5, linewidths=1, color='blue', s=series5['USD'], alpha=0.5)

# format xaxis with 4 month intervals
ax.get_xaxis().set_major_locator(mdates.MonthLocator(interval=4))
ax.get_xaxis().set_major_formatter(mdates.DateFormatter("%b %Y"))
#plt.setp(ax.get_xticklabels(), rotation=30, ha="right")
plt.setp(ax.get_xticklabels(), rotation=45)

#ax.set_yscale('log')
plt.yticks([0, 1, 2, 3, 4], ['Reentrancy', 'Integer Overflow', 'Integer Underflow', 'Parity Wallet Hack 1', 'Parity Wallet Hack 2'])

kw = dict(prop="sizes", num=5, color="blue", fmt="$ {x:.0f}",
          func=lambda s: 10**(s/np.pi/20))
ax.legend(*scatter.legend_elements(**kw),
                    loc="upper left", title="")

ratio = 0.4
xleft, xright = ax.get_xlim()
ybottom, ytop = ax.get_ylim()
# the abs method is used to make sure that all numbers are positive
# because x and y axis of an axes maybe inversed.
ax.set_aspect(abs((xright-xleft)/(ybottom-ytop))*ratio)

# or we can utilise the get_data_ratio method which is more concise
# ax.set_aspect(1.0/ax.get_data_ratio()*ratio)

plt.tight_layout()
plt.savefig("timeline_2.pdf", dpi=1000, bbox_inches='tight')
