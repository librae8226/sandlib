#!/usr/bin/env python

import plotly.plotly as py
from plotly.graph_objs import *

'''
need to set credentials first
'''

trace0 = Scatter(
	x = [8, 9, 10, 11, 12],
	y = [10116.88, 9736.28, 9962.49, 10089.92, 10107.74]
)
cap = trace0

trace1 = Scatter(
	x = [8, 9, 10, 11, 12],
	y = [10000, 10000, 10000, 10000, 10000]
)
tot = trace1

data = Data([cap, tot])

unique_url = py.plot(data, filename = 'basic-line', auto_open=False);
