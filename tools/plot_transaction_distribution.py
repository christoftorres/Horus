import matplotlib
import seaborn

import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter

matplotlib.use('Agg')

plt.figure(figsize=(10,6))

#seaborn.set(font_scale=2.0)
seaborn.set_style('whitegrid', {'axes.grid' : False})

plt.rcParams['text.latex.preamble']=[r"\usepackage{lmodern}"]
params = {'text.usetex' : True,
          'font.size' : 14,
          'font.family' : 'lmodern',
          }
plt.rcParams.update(params)

fig, ax = plt.subplots()

contracts = [461235, 463494, 107521, 31277, 9087, 2968, 427, 24, 2]
#transactions = ['(0, 1]', '(1, 10]', '(10, 100]', '(100, 1K]', '10K', '100K', '1M', '10M', '100M']
transactions = ['1', '10', '100', '1K', '10K', '100K', '1M', '10M', '100M']

ax.bar(transactions, contracts, color="cornflowerblue", edgecolor="blue")

plt.ylabel("Number of Contracts")
plt.xlabel("Number of Transactions")

def human_format(x, pos):
    magnitude = 0
    while abs(x) >= 1000:
        magnitude += 1
        x /= 1000.0
    # add more suffixes if you need them
    return '%.0f%s' % (x, ['', 'K', 'M', 'G', 'T', 'P'][magnitude])

#ax.set_yscale('log')
#ax.get_yaxis().set_major_formatter(plt.FuncFormatter(lambda x, loc: "{:,}".format(int(x))))
ax.yaxis.set_major_formatter(FuncFormatter(human_format))
axes.spines['right'].set_visible(False)
plt.tight_layout()
plt.savefig("transaction_distribution.pdf", dpi=1000, bbox_inches='tight')
