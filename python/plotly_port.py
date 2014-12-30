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


# growth-stat. growth rate daily: grd. weekly: grw. monthly: grm
# daily
growth_daily = range(0, n)
growth_rate_daily = range(0, n)

for i in range(0, n):
	if (i == 0):
		growth_daily[i] = total[i] - capital[i]
		growth_rate_daily[i] = growth_daily[i]/capital[i]
	else:
		growth_daily[i] = total[i] - (capital[i] + (total[i-1] - capital[i-1]))
		growth_rate_daily[i] = growth_daily[i]/(capital[i] + (total[i-1] - capital[i-1]))

x_grd = x
y_grd = [val * 100 for val in growth_rate_daily]
for i in range(0, n):
	y_grd[i] = round(y_grd[i], 2)

grd = Scatter(x = x_grd, y = y_grd, name = u'daily growth %')

# weekly, monday is 0, friday is 4
growth_weekly = list()
x_grw = [x[0]]
y_grw = [0.00]
last_friday_idx = int()
last_week_base = float()

for i in range(0, n):
	if x[i].weekday() == 4:
		last_friday_idx = i
		x_grw.append(x[i])
		if i == 4:
			last_week_base = capital[i]
			growth_weekly.append(total[i] - last_week_base)
		else:
			last_week_base = total[i-5]
			growth_weekly.append(total[i] - last_week_base - (capital[i] - capital[i-5]))
		y_grw.append(round(100 * growth_weekly[-1]/last_week_base, 2))
		print 'idx:', i, 'last_week_base:', last_week_base, 'growth_weekly:', growth_weekly[-1], 'grw:', y_grw[-1]

if x[-1].weekday() != 4:
	last_week_base = total[last_friday_idx]
	growth_weekly.append(total[-1] - last_week_base - (capital[-1] - capital[last_friday_idx]))
	y_grw.append(round(100 * growth_weekly[-1]/last_week_base, 2))
	x_grw.append(x[-1])
	print '-1:', i, 'last_week_base:', last_week_base, 'growth_weekly:', growth_weekly[-1], 'grw:', y_grw[-1]

grw = Scatter(x = x_grw, y = y_grw, name = u'weekly growth %')

# TODO monthly


data_gr = Data([grd, grw])

# perform request to remote or print out the data
if len(sys.argv) == 2 and sys.argv[1] == 'upload':
	unique_url = py.plot(data_tot, filename = 'port-stat', auto_open=False)
	print 'port-stat:', unique_url
	unique_url = py.plot(data_gr, filename = 'growth-stat', auto_open=False)
	print 'growth-stat:', unique_url
else:
	print data_tot
	print data_gr
