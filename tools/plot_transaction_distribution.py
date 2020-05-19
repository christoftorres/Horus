import matplotlib
import seaborn

import numpy as np

import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter

matplotlib.use('Agg')

seaborn.set(font_scale=1.1)
seaborn.set_style('whitegrid', {'axes.grid' : False})

plt.rcParams['text.latex.preamble']=[r"\usepackage{lmodern}"]
params = {'text.usetex' : True,
          'font.size' : 10,
          'font.family' : 'lmodern',
          }
plt.rcParams.update(params)

fig, ax = plt.subplots()

contracts = [461235, 463494, 107521, 31277, 9087, 2968, 427, 24, 2]
transactions = ['(0, 1]', '(1, 10]', '(10, 100]', '(100, 1K]', '(1K, 10K]', '(10K, 100K]', '(100K, 1M]', '(1M, 10M]', '(10M, 100M]']

rects = ax.bar(transactions, contracts)
plt.ylabel("Number of Contracts")
plt.xlabel("Transaction Ranges")
plt.xticks(rotation=30)

def human_format(x, pos):
    magnitude = 0
    while abs(x) >= 1000:
        magnitude += 1
        x /= 1000.0
    # add more suffixes if you need them
    return '%.0f%s' % (x, ['', 'K', 'M', 'G', 'T', 'P'][magnitude])

ax.get_yaxis().set_major_formatter(plt.FuncFormatter(lambda x, loc: "{:,}".format(int(x))))
ax.yaxis.set_major_formatter(FuncFormatter(human_format))
ax.get_yaxis().set_ticks([])

def autolabel(rects):
    """Attach a text label above each bar in *rects*, displaying its height."""
    for rect in rects:
        height = rect.get_height()
        ax.annotate('{:,}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')

autolabel(rects)

for i in range(len(rects)):
    if i > 2:
        rects[i].set_alpha(0.5)

ax.spines['left'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)

plt.tight_layout()
fig.set_size_inches(6, 3)
plt.savefig("transaction-chart.pdf", dpi=100, bbox_inches='tight')
