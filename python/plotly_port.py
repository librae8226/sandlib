#!/usr/bin/env python

import plotly.plotly as py
from plotly.graph_objs import *
from datetime import datetime
from dateutil import parser
import json
import sys

# get from raw data server (json)
json_data=open('public.json')
raw = json.load(json_data)

n = len(raw)

x = range(0, n)
capital = range(0, n)
total = range(0, n)
datestr = range(0, n)
y = range(0, n)
m = range(0, n)
d = range(0, n)

for i in range(0, n):
	capital[i] = float(raw[n - i - 1]["capital"])
	total[i] = float(raw[n - i - 1]["total"])
	datestr[i] = str(raw[n - i - 1]["timestamp"])
	y[i] = parser.parse(datestr[i]).year
	m[i] = parser.parse(datestr[i]).month
	d[i] = parser.parse(datestr[i]).day
	x[i] = datetime(year = y[i], month = m[i], day = d[i])

# FIXME
# HACKS HERE
# we need a better estimating algorithm when the capital become quite
# larger or smaller, it will not make the whole graph look stange
#capital[0] = capital[1]
#total[0] = capital[0]

x_cap = x
y_cap = capital
x_tot = x
y_tot = total

cap = Scatter(x = x_cap, y = y_cap, name = u'capital')
tot = Scatter(x = x_tot, y = y_tot, name = u'total')

data = Data([cap, tot])

if len(sys.argv) == 2 and sys.argv[1] == 'upload':
	unique_url = py.plot(data, filename = 'port-stat', auto_open=False)
	print unique_url
else:
	print data
