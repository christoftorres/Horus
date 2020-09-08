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
    data = {'Timestamp': [], 'Deployments': []}
    for d in pd.date_range(start=date_min, end=date_max):
        t = d.strftime('%Y-%m-%d')
        for i in range(len(series)):
            if t == series['Timestamp'][i]:
                data['Timestamp'].append(t)
                #data['Deployments'].append(series['Deployments'][i])
                if len(data['Deployments']) > 0:
                    data['Deployments'].append(data['Deployments'][-1] + series['Deployments'][i])
                else:
                    data['Deployments'].append(series['Deployments'][i])
            else:
                data['Timestamp'].append(t)
                #data['Deployments'].append(0)
                if len(data['Deployments']) > 0:
                    data['Deployments'].append(data['Deployments'][-1])
                else:
                    data['Deployments'].append(0)
    data['Timestamp'] = [datetime.strptime(d, "%Y-%m-%d") for d in data['Timestamp']]
    return data

matplotlib.use('Agg')

plt.figure(figsize=(14, 6))

#seaborn.set(font_scale=2.0)
seaborn.set_style("whitegrid", {'axes.grid': False})

series1 = load_data('deployments/reentrancy.csv')

fig, ax = plt.subplots()
ax.plot('Timestamp', 'Deployments', data=series1, linewidth=1)
#ax.stackplot('Timestamp', 'Deployments', data=series1)

# format xaxis with 4 month intervals
ax.get_xaxis().set_major_locator(mdates.MonthLocator(interval=4))
ax.get_xaxis().set_major_formatter(mdates.DateFormatter("%b %Y"))
#plt.setp(ax.get_xticklabels(), rotation=30, ha="right")
plt.setp(ax.get_xticklabels(), rotation=45)

#ax.set_yscale('log')

plt.ylabel("Deployments")
plt.xlabel("Date")

plt.legend([
    'Reentrancy',
])

plt.tight_layout()
plt.savefig("deployments.pdf", dpi=1000, bbox_inches='tight')
