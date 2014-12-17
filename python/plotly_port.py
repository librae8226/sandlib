#!/usr/bin/env python

import plotly.plotly as py
from plotly.graph_objs import *
from datetime import datetime
from dateutil import parser
import json
import sys


# FIXME get from raw data server (json)
json_data = open('public.json')
raw = json.load(json_data)

n = len(raw)
x = range(0, n)
y = range(0, n)


# port-stat

capital = range(0, n)
total = range(0, n)
datestr = range(0, n)
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
data_tot = Data([cap, tot])


# growth-stat

growth = range(0, n)
growth_rate = range(0, n)

for i in range(0, n):
	if (i == 0):
		growth[i] = total[i] - capital[i]
		growth_rate[i] = growth[i]/capital[i]
	else:
		growth[i] = total[i] - (capital[i] + (total[i-1] - capital[i-1]))
		growth_rate[i] = growth[i]/(capital[i] + (total[i-1] - capital[i-1]))

x_gr = x
y_gr = [val * 100 for val in growth_rate]
for i in range(0, n):
	y_gr[i] = round(y_gr[i], 2)

gr = Scatter(x = x_gr, y = y_gr, name = u'growth rate')
data_gr = Data([gr])

if len(sys.argv) == 2 and sys.argv[1] == 'upload':
	unique_url = py.plot(data_tot, filename = 'port-stat', auto_open=False)
	print 'port-stat:', unique_url
	unique_url = py.plot(data_gr, filename = 'growth-stat', auto_open=False)
	print 'growth-stat:', unique_url
else:
	print data_tot
	print data_gr
