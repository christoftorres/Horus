import matplotlib
import seaborn

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

import matplotlib.dates as mdates
from matplotlib.dates import DateFormatter
from datetime import datetime

def load_data(filename):
    series = pd.read_csv(filename)
    date_min = series['Timestamp'][0] if len(series['Timestamp']) > 0 else 0
    date_max = series['Timestamp'][len(series)-1] if len(series['Timestamp']) > 0 else 0
    data = {'Timestamp': [], 'Transactions': []}
    for d in pd.date_range(start=date_min, end=date_max):
        t = d.strftime('%Y-%m-%d')
        for i in range(len(series)):
            if t == series['Timestamp'][i]:
                data['Timestamp'].append(t)
                data['Transactions'].append(series['Transactions'][i])
            else:
                data['Timestamp'].append(t)
                data['Transactions'].append(0)
    data['Timestamp'] = [datetime.strptime(d, "%Y-%m-%d") for d in data['Timestamp']]
    return data

matplotlib.use('Agg')

plt.figure(figsize=(14, 6))

#seaborn.set(font_scale=2.0)
seaborn.set_style("whitegrid", {'axes.grid': False})

series1 = load_data('reentrancy_timelime.csv')
series2 = load_data('integer_overflow_timelime.csv')
series3 = load_data('integer_underflow_timelime.csv')
series4 = load_data('parity_wallet_hack_1_timelime.csv')
series5 = load_data('parity_wallet_hack_2_timelime.csv')

names = [
    #'Oyente\nv0.0.1',
    'Manticore\nv0.1.0',
    #'SmartCheck\nv1.0.0',
    'Oyente\nv0.1.0',
    #'Oyente\nv0.2.0',
    #'Oyente\nv0.2.6',
    'ECFChecker\nv1.0.0',
    'Mythril\nv0.3.4',
    #'Oyente\nv0.2.7',
    #'Mythril\nv0.5.2',
    #'Mythril\nv0.8.6',
    'MAIAN\nv1.0.0',
    'Vandal\nv1.0.0',
    #'Mythril\nv0.15.9',
    #'Mythril\nv0.16.5',
    #'Mythril\nv0.17.0',
    #'Mythril\nv0.18.0',
    'ContractFuzzer\nv1.0.0',
    #'Manticore\nv0.2.0',
    'Osiris\nv0.0.1',
    'MadMax\nv1.0.0',
    #'Mythril\nv0.19.0',
    'SmartCheck\nv2.0.0',
    'Securify\nv1.0.0',
    #'Mythril\nv0.20.0',
    #'Manticore\nv0.3.0',
    #'Mythril\nv0.21.2',
    #'Securify\nv2.0.0',
    #'Mythril\nv0.22.0',

]
dates = [
    #'2016-01-08',
    '2017-04-26',
    #'2017-05-19',
    '2017-06-19',
    #'2017-07-25',
    #'2017-08-22',
    '2017-09-30',
    '2017-10-04',
    #'2017-10-09',
    #'2017-10-18',
    #'2017-11-09',
    '2018-03-12',
    '2018-03-18',
    #'2018-04-09',
    #'2018-04-23',
    #'2018-05-08',
    #'2018-06-12',
    '2018-08-08',
    #'2018-08-10',
    '2018-09-11',
    '2018-10-24',
    #'2018-10-31',
    '2019-01-10',
    '2019-01-22',
    #'2019-01-30',
    #'2019-06-06',
    #'2019-06-19',
    #'2020-01-22',
    #'2020-03-16',
]

# Convert date strings (e.g. 2014-10-18) to datetime
dates = [datetime.strptime(d, "%Y-%m-%d") for d in dates]
# Choose some nice levels
levels = np.tile([500, 100, 300],
                 int(np.ceil(len(dates)/3)))[:len(dates)]

hacks = [
    'DAO Hack',
    '1st Parity\nWallet Hack',
    '2nd Parity\nWallet Hack',
]
hack_dates = [
    '2016-06-17',
    '2017-07-19',
    '2017-11-06',
]
# Convert date strings (e.g. 2014-10-18) to datetime
hack_dates = [datetime.strptime(d, "%Y-%m-%d") for d in hack_dates]
# Choose some nice levels
hack_levels = np.tile([10000, 10000, 10000],
                 int(np.ceil(len(hack_dates)/3)))[:len(hack_dates)]

fig, ax = plt.subplots()
ax.plot('Timestamp', 'Transactions', data=series1, linewidth=1)
ax.plot('Timestamp', 'Transactions', data=series2, linewidth=1)
ax.plot('Timestamp', 'Transactions', data=series3, linewidth=1)
ax.plot('Timestamp', 'Transactions', data=series4, linewidth=1)
ax.plot('Timestamp', 'Transactions', data=series5, linewidth=1)

markerline, stemlines, baseline = ax.stem(dates, levels,
                                         linefmt="C1-", basefmt="k-", markerfmt='o',
                                         use_line_collection=True)
plt.setp(markerline, mec="k", mfc="w", zorder=3)
plt.setp(stemlines, 'color', 'black')
plt.setp(stemlines, 'linewidth', 1)
plt.setp(baseline, 'linewidth', 1)
plt.setp(markerline, 'markersize', 2)
markerline.set_markerfacecolor('black')
# annotate lines
vert = np.array(['top', 'bottom'])[(levels > 0).astype(int)]
for d, l, r, va in zip(dates, levels, names, vert):
    ax.annotate(r, xy=(d, l), xytext=(0, np.sign(l)*3),
                textcoords="offset points", va=va, ha="center", size=5, weight='bold')

hack_markerline, hack_stemlines, hack_baseline = ax.stem(hack_dates, hack_levels,
                                         linefmt="C1--", basefmt="k-", markerfmt='bo',
                                         use_line_collection=True)
#plt.setp(hack_markerline, mec="k", mfc="w", zorder=3)
plt.setp(hack_stemlines, 'color', 'black')
plt.setp(hack_stemlines, 'linewidth', 1)
plt.setp(hack_baseline, 'linewidth', 1)
plt.setp(hack_markerline, 'markersize', 2)
plt.setp(hack_markerline, 'color', 'black')
hack_markerline.set_markerfacecolor('black')

# annotate lines
vert = np.array(['top', 'bottom'])[(hack_levels > 0).astype(int)]
for d, l, r, va in zip(hack_dates, hack_levels, hacks, vert):
    ax.annotate(r, xy=(d, l), xytext=(0, np.sign(l)*3),
                textcoords="offset points", va=va, ha="center", size=5, weight='bold', color='black')


# format xaxis with 4 month intervals
ax.get_xaxis().set_major_locator(mdates.MonthLocator(interval=4))
ax.get_xaxis().set_major_formatter(mdates.DateFormatter("%b %Y"))
plt.setp(ax.get_xticklabels(), rotation=30, ha="right")
#plt.setp(ax.get_xticklabels(), rotation=45)

ax.set_yscale('log')

plt.ylabel("Transactions")
plt.xlabel("Date")

#plt.legend([
#    'Reentrancy',
#    'Integer Overflow',
#    'Integer Underflow',
#    'Parity Wallet Hack 1',
#    'Parity Wallet Hack 2',
#])

plt.tight_layout()
plt.savefig("timeline.pdf", dpi=1000, bbox_inches='tight')
