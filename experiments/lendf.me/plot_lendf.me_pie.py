#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

from bokeh.palettes import Category20c

fig, ax = plt.subplots(figsize=(6, 3), subplot_kw=dict(aspect="equal"))

data = [
    10312674.650791774,
    7179074.184668019,
    2325766.2589893304,
    2115704.6203530994,
    697999.2644038666,
    586621.9026432278,
    510400.0113002347,
    480690.739668546,
    458927.20622208127,
    431726.46004666795,
    79084.55452631715,
    65450.890006945716
]

tokens = ["WETH", "USDT", "HBTC", "imBTC", "USDC", "PAX", "USDx", "BUSD", "TUSD", "HUSD", "CHAI", "WBTC"]

def human_format(num):
    magnitude = 0
    while abs(num) >= 1000:
        magnitude += 1
        num /= 1000.0
    # add more suffixes if you need them
    return '%.2f%s' % (num, ['', 'K', 'M', 'G', 'T', 'P'][magnitude])

def func(pct, allvals):
    absolute = int(pct/100.*np.sum(allvals))
    if pct > 8:
        return "{:s}\n({:.1f}%)".format(human_format(absolute), pct)
    else:
        ''

wedges, texts, autotexts = ax.pie(data, autopct=lambda pct: func(pct, data), pctdistance=1, radius=1.3, textprops=dict(color="w"), wedgeprops=dict(width=0.7, edgecolor='w'), colors=plt.cm.tab20.colors)

ax.legend(wedges, tokens,
          loc="center left",
          bbox_to_anchor=(1.2, 0, 1, 1))

plt.setp(autotexts, size=9)

pctdists = [.7, .72, .75, .75]

for t,d in zip(autotexts, pctdists):
    xi,yi = t.get_position()
    ri = np.sqrt(xi**2+yi**2)
    phi = np.arctan2(yi,xi)
    x = d*ri*np.cos(phi)
    y = d*ri*np.sin(phi)
    t.set_position((x,y))

fig.tight_layout()

plt.savefig("lendf.me_pie.pdf", dpi=1000, bbox_inches='tight')
