import matplotlib
import seaborn

import pandas as pd
import matplotlib.pyplot as plt

import matplotlib.dates as mdates
from matplotlib.dates import DateFormatter


matplotlib.use('Agg')

plt.figure(figsize=(12,6))

#seaborn.set(font_scale=2.0)
seaborn.set_style("whitegrid", {'axes.grid': True})

series1 = pd.read_csv('reentrancy_timelime.csv', parse_dates=['Timestamp'], index_col=['Timestamp'])
series2 = pd.read_csv('cross_function_reentrancy_timelime.csv', parse_dates=['Timestamp'], index_col=['Timestamp'])
series3 = pd.read_csv('delegated_reentrancy_timelime.csv', parse_dates=['Timestamp'], index_col=['Timestamp'])
series4 = pd.read_csv('create_based_reentrancy_timelime.csv', parse_dates=['Timestamp'], index_col=['Timestamp'])

fig, ax = plt.subplots()
ax.plot(series1.index.values, 'Transactions', data=series1)
ax.plot(series2.index.values, 'Transactions', data=series2)
ax.plot(series3.index.values, 'Transactions', data=series3)
ax.plot(series4.index.values, 'Transactions', data=series4)

plt.setp(ax.get_xticklabels(), rotation=45)

plt.ylabel("Number of Attacks")

plt.legend([
    'Reentrancy',
    'Cross-Function Reentrancy',
    'Delegated Reentrancy',
    'Create-Based Reentrancy',
])

plt.tight_layout()
plt.savefig("timeline.pdf", dpi=1000, bbox_inches='tight')
