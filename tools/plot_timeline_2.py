import matplotlib
import seaborn

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

import matplotlib.dates as mdates
from matplotlib.dates import DateFormatter
from datetime import datetime

import math

plt.rcParams['text.latex.preamble']=[r"\usepackage{lmodern}"]
params = {'text.usetex' : True,
          'font.size' : 9,
          'font.family' : 'lmodern',
          }
plt.rcParams.update(params)

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
                #data['USD'].append(series['USD'][i])
                data['USD'].append(np.pi*8*magnitude(series['USD'][i]))
    data['Timestamp'] = [datetime.strptime(d, "%Y-%m-%d") for d in data['Timestamp']]
    return data

matplotlib.use('Agg')

#plt.figure(figsize=(10, 2))

#seaborn.set(font_scale=2.0)
seaborn.set_style("whitegrid", {'axes.grid': False})
flatui = ["#3498db"]
seaborn.set_palette(flatui)

series1 = load_data('reentrancy_timelime.csv', 0)
series2 = load_data('integer_overflow_timelime.csv', 1)
#series3 = load_data('integer_underflow_timelime.csv', 2)
series4 = load_data('parity_wallet_hack_1_timelime.csv', 2)
series5 = load_data('parity_wallet_hack_2_timelime.csv', 3)

fig, ax = plt.subplots()
ax.scatter('Timestamp', 'Transactions', data=series1, marker='.', s=5, linewidths=1)
scatter = ax.scatter('Timestamp', 'Transactions', data=series1, linewidths=1, s=series1['USD'], alpha=0.3)
ax.scatter('Timestamp', 'Transactions', data=series2, marker='.', s=5, linewidths=1)
ax.scatter('Timestamp', 'Transactions', data=series2, linewidths=1, s=series2['USD'], alpha=0.3)
#ax.scatter('Timestamp', 'Transactions', data=series3, marker='.', s=5, linewidths=1)
#ax.scatter('Timestamp', 'Transactions', data=series3, linewidths=1, s=series3['USD'], alpha=0.3)
ax.scatter('Timestamp', 'Transactions', data=series4, marker='.', s=5, linewidths=1)
scatter = ax.scatter('Timestamp', 'Transactions', data=series4, linewidths=1, s=series4['USD'], alpha=0.3)
ax.scatter('Timestamp', 'Transactions', data=series5, marker='.', s=5, linewidths=1)
ax.scatter('Timestamp', 'Transactions', data=series5, linewidths=1, s=series5['USD'], alpha=0.3)

# format xaxis with 4 month intervals
ax.get_xaxis().set_major_locator(mdates.MonthLocator(interval=4))
ax.get_xaxis().set_major_formatter(mdates.DateFormatter("%b %Y"))
#plt.setp(ax.get_xticklabels(), rotation=30, ha="right")
plt.setp(ax.get_xticklabels(), rotation=45)

#ax.set_ylim(0, 3)

#ax.set_yscale('log')
plt.yticks([0, 1, 2, 3], [
    r'Reentrancy'+'\n'+r'{\tiny Min: \$'+"{:,.0f}".format(min(pd.read_csv('reentrancy_timelime.csv')['USD']))+r'; Mean: \$'+"{:,.0f}".format(int(np.mean(pd.read_csv('reentrancy_timelime.csv')['USD'])))+r'; Max: \$'+"{:,.0f}".format(np.max(pd.read_csv('reentrancy_timelime.csv')['USD']))+r'}',
    r'Integer Overflow'+'\n'+r'{\tiny Min: \$'+"{:,.0f}".format(min(pd.read_csv('integer_overflow_timelime.csv')['USD']))+r'; Mean: \$'+"{:,.0f}".format(int(np.mean(pd.read_csv('integer_overflow_timelime.csv')['USD'])))+r'; Max: \$'+"{:,.0f}".format(np.max(pd.read_csv('integer_overflow_timelime.csv')['USD']))+r'}',
    #r'Integer Underflow'+'\n'+r'{\tiny Min: \$'+str(min(pd.read_csv('integer_underflow_timelime.csv')['USD']))+r', Mean: \$'+str(int(np.mean(pd.read_csv('integer_underflow_timelime.csv')['USD'])))+r', Max: \$'+str(np.max(pd.read_csv('integer_underflow_timelime.csv')['USD']))+r'}',
    r'Parity Wallet Hack 1'+'\n'+r'{\tiny Min: \$'+"{:,.0f}".format(min(pd.read_csv('parity_wallet_hack_1_timelime.csv')['USD']))+r'; Mean: \$'+"{:,.0f}".format(int(np.mean(pd.read_csv('parity_wallet_hack_1_timelime.csv')['USD'])))+r'; Max: \$'+"{:,.0f}".format(np.max(pd.read_csv('parity_wallet_hack_1_timelime.csv')['USD']))+r'}',
    r'Parity Wallet Hack 2'+'\n'+r'{\tiny Min: \$'+"{:,.0f}".format(min(pd.read_csv('parity_wallet_hack_2_timelime.csv')['USD']))+r'; Mean: \$'+"{:,.0f}".format(int(np.mean(pd.read_csv('parity_wallet_hack_2_timelime.csv')['USD'])))+r'; Max: \$'+"{:,.0f}".format(np.max(pd.read_csv('parity_wallet_hack_2_timelime.csv')['USD']))+r'}'])

kw = dict(prop="sizes", color="#3498db", fmt=r"\${x:,.0f}",
          func=lambda s: 10**(s/np.pi/8))
ax.legend(*scatter.legend_elements(**kw),
                    loc="upper left", title="")

ratio = 0.3
xleft, xright = ax.get_xlim()
ybottom, ytop = ax.get_ylim()
# the abs method is used to make sure that all numbers are positive
# because x and y axis of an axes maybe inversed.
ax.set_aspect(abs((xright-xleft)/(ybottom-ytop))*ratio)

# or we can utilise the get_data_ratio method which is more concise
# ax.set_aspect(1.0/ax.get_data_ratio()*ratio)

plt.tight_layout()
plt.savefig("timeline_2.pdf", dpi=1000, bbox_inches='tight')
