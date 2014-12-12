#!/usr/bin/env python

import plotly.plotly as py
from plotly.graph_objs import *
from datetime import datetime

'''
need to set credentials first
'''

# get from data server (json)
x = [datetime(year=2014, month=12, day=8), datetime(year=2014, month=12, day=9), datetime(year=2014, month=12, day=10), datetime(year=2014, month=12, day=11), datetime(year=2014, month=12, day=12)]
x_cap = x
x_tot = x
y_cap = [10000, 10000, 10000, 10000, 10000]
y_tot = [10116.88, 9736.28, 9962.49, 10089.92, 10107.74]

cap = Scatter(x = x_cap, y = y_cap)
tot = Scatter(x = x_tot, y = y_tot)

data = Data([cap, tot])

unique_url = py.plot(data, filename = 'basic-line', auto_open=False);
