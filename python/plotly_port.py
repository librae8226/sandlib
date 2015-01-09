#!/usr/bin/env python

import plotly.plotly as py
from plotly.graph_objs import *
from datetime import datetime
from datetime import timedelta
from dateutil import parser
import calendar
import xml.etree.ElementTree as et
import json
import sys
from subprocess import call

# fetch data
#call('./get_data.sh', shell=True)

# FIXME get from raw data server (xml)
#       and assume we start from 2014.12.8
xml_data = et.parse('csi300.xml')

content = xml_data.findall('content')
n300 = len(content)
index0 = range(0, n300)
index = []
yindex = range(0, n300)
mindex = range(0, n300)
dindex = range(0, n300)
xindex0 = range(0, n300)
xindex = []

for i in range(0, n300):
	index0[i] = float(content[i].get('c'))
	yindex[i] = parser.parse(content[i].get('d')).year
	mindex[i] = parser.parse(content[i].get('d')).month
	dindex[i] = parser.parse(content[i].get('d')).day
	xindex0[i] = datetime(year = yindex[i], month = mindex[i], day = dindex[i])

# interpolation

for i in range(1, n300):
	if xindex0[i] != (xindex0[i-1] + timedelta(days=1)):
		print xindex0[i-1], '~', xindex0[i], '> gap:', xindex0[i] - xindex0[i-1]
		for j in range(0, (xindex0[i] - xindex0[i-1]).days):
			xindex.append(xindex0[i-1] + timedelta(days=j))
			index.append(index0[i-1])
	else:
		xindex.append(xindex0[i-1])
		index.append(index0[i-1])
xindex.append(xindex0[n300-1])
index.append(index0[n300-1])

#for i in range(0, len(xindex)):
#	print i, '>', xindex[i], index[i]

# FIXME get from raw data server (json)
json_data = open('public.json')
raw = json.load(json_data)

n0 = len(raw)
capital0 = range(0, n0)
total0 = range(0, n0)
x0 = range(0, n0)
datestr = range(0, n0)
y = range(0, n0)
m = range(0, n0)
d = range(0, n0)

for i in range(0, n0):
	capital0[i] = float(raw[n0 - i - 1]["capital"])
	total0[i] = float(raw[n0 - i - 1]["total"])
	datestr[i] = str(raw[n0 - i - 1]["timestamp"])
	y[i] = parser.parse(datestr[i]).year
	m[i] = parser.parse(datestr[i]).month
	d[i] = parser.parse(datestr[i]).day
	x0[i] = datetime(year = y[i], month = m[i], day = d[i])

#for i in range(0, n0):
#	print i, '>', x0[i], capital0[i], total0[i]

# interpolation

capital = []
total = []
x = []
y = []

for i in range(1, n0):
	if x0[i] != (x0[i-1] + timedelta(days=1)):
		print x0[i-1], '~', x0[i], '> gap:', x0[i] - x0[i-1]
		for j in range(0, (x0[i] - x0[i-1]).days):
			x.append(x0[i-1] + timedelta(days=j))
			capital.append(capital0[i-1])
			total.append(total0[i-1])
	else:
		x.append(x0[i-1])
		capital.append(capital0[i-1])
		total.append(total0[i-1])
x.append(x0[n0-1])
capital.append(capital0[n0-1])
total.append(total0[n0-1])

n = len(x)
if (n != len(xindex)):
	print 'error!', 'n:', n, '!= xindex len:', len(xindex)
	exit(-1)

for i in range(0, n):
	print i, '>', x[i], capital[i], total[i], index[i]

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
index_growth_daily = range(0, n)
index_growth_rate_daily = range(0, n)

for i in range(0, n):
	if (i == 0):
		growth_daily[i] = round(total[i] - capital[i], 2)
		growth_rate_daily[i] = growth_daily[i]/capital[i]
		index_growth_daily[i] = round(index[i] - float(content[i].get('o')), 2)
	else:
		growth_daily[i] = round(total[i] - total[i-1] - (capital[i] - capital[i-1]), 2)
		growth_rate_daily[i] = growth_daily[i]/(total[i-1] + (capital[i] - capital[i-1]))
		index_growth_daily[i] = round(index[i] - index[i-1], 2)
	index_growth_rate_daily[i] = index_growth_daily[i]/index[i-1]

x_grd = x
y_grd = [val * 100 for val in growth_rate_daily]
for i in range(0, n):
	y_grd[i] = round(y_grd[i], 2)

x_igrd = xindex
y_igrd = [val * 100 for val in index_growth_rate_daily]
for i in range(0, n):
	y_igrd[i] = round(y_igrd[i], 2)

grd = Scatter(
	x = x_grd,
	y = y_grd,
	name = u'daily %',
	line = Line(
		shape='spline'
		),
	marker = Marker(
		color = 'rgb(192, 128, 64)',
		)
	)
igrd = Scatter(
	x = x_igrd,
	y = y_igrd,
	name = u'index daily %',
	line = Line(
		shape='spline'
		),
	marker = Marker(
		color = 'rgb(64, 128, 192)',
		)
	)

# weekly, monday is 0, friday is 4
last_friday_idx = int()
growth_weekly = []
x_grw = [x[0]]
y_grw = [0.00]
last_week_base = float()
index_growth_weekly = []
x_igrw = [x[0]]
y_igrw = [0.00]
last_week_index_base = float()

for i in range(0, n):
	if x[i].weekday() == 4:
		last_friday_idx = i
		x_grw.append(x[i])
		x_igrw.append(x[i])
		if i == 4:
			last_week_base = capital[i]
			last_week_index_base = float(content[0].get('o'))
		else:
			last_week_base = total[i-7] + (capital[i] - capital[i-7])
			last_week_index_base = index[i-7]
		growth_weekly.append(round(total[i] - last_week_base, 2))
		index_growth_weekly.append(round(index[i] - last_week_index_base, 2))
		y_grw.append(round(100 * growth_weekly[-1]/last_week_base, 2))
		y_igrw.append(round(100 * index_growth_weekly[-1]/last_week_index_base, 2))
		print 'idx:', i, 'last_week_base:', last_week_base, 'growth_weekly:', growth_weekly[-1], 'grw:', y_grw[-1]
		print 'idx:', i, 'last_week_index_base:', last_week_index_base, 'index_growth_weekly:', index_growth_weekly[-1], 'igrw:', y_igrw[-1]

if x[-1].weekday() != 4:
	last_week_base = total[last_friday_idx] + (capital[-1] - capital[last_friday_idx])
	last_week_index_base = index[last_friday_idx]
	growth_weekly.append(round(total[-1] - last_week_base, 2))
	index_growth_weekly.append(round(index[-1] - last_week_index_base, 2))
	y_grw.append(round(100 * growth_weekly[-1]/last_week_base, 2))
	y_igrw.append(round(100 * index_growth_weekly[-1]/last_week_index_base, 2))
	x_grw.append(x[-1])
	x_igrw.append(x[-1])
	print '-1:', i, 'last_week_base:', last_week_base, 'growth_weekly:', growth_weekly[-1], 'grw:', y_grw[-1]
	print '-1:', i, 'last_week_index_base:', last_week_index_base, 'index_growth_weekly:', index_growth_weekly[-1], 'igrw:', y_igrw[-1]

grw = Scatter(
	x = x_grw,
	y = y_grw,
	name = u'weekly %',
	line = Line(
		shape='spline'
		),
	marker = Marker(
		color = 'rgb(192, 64, 32)',
		)
	)
igrw = Scatter(
	x = x_igrw,
	y = y_igrw,
	name = u'index weekly %',
	line = Line(
		shape='spline'
		),
	marker = Marker(
		color = 'rgb(32, 64, 192)',
		)
	)

# TODO monthly
last_month_idx = 0
growth_monthly = [0.00]
x_grm = [x[0]]
y_grm = [0.00]
last_month_base = float()
index_growth_monthly = [0.00]
x_igrm = [x[0]]
y_igrm = [0.00]
last_month_index_base = float()

for i in range(0, n):
	if (x[i].day == calendar.monthrange(x[i].year, x[i].month)[1]):
		last_month_idx = i;
		if (i == 23):	# first month
			last_month_base = capital[i]
			last_month_index_base = index[0]
		else:
			last_month_base = total[i - x[i].day] + (capital[i] - capital[i - x[i].day])
			last_month_index_base = index[i - x[i].day]
		x_grm.append(x[i])
		x_igrm.append(x[i])
		growth_monthly.append(round(total[i] - last_month_base, 2))
		index_growth_monthly.append(round(index[i] - last_month_index_base, 2))
		y_grm.append(round(100*growth_monthly[-1]/last_month_base, 2))
		y_igrm.append(round(100*index_growth_monthly[-1]/last_month_index_base, 2))
		print 'idx:', i, 'last_month_base:', last_month_base, 'growth_monthly:', growth_monthly[-1], 'grm:', y_grm[-1]
		print 'idx:', i, 'last_month_index_base:', last_month_index_base, 'index_growth_monthly:', index_growth_monthly[-1], 'igrw:', y_igrw[-1]

if (x[-1].day != calendar.monthrange(x[-1].year, x[-1].month)[1]):
	last_month_base = total[last_month_idx] + (capital[-1] - capital[last_month_idx])
	last_month_index_base = index[last_month_idx]
	growth_monthly.append(round(total[-1] - last_month_base, 2))
	index_growth_monthly.append(round(index[-1] - last_month_index_base, 2))
	y_grm.append(round(100 * growth_monthly[-1]/last_month_base, 2))
	y_igrm.append(round(100 * index_growth_monthly[-1]/last_month_index_base, 2))
	x_grm.append(x[-1])
	x_igrm.append(x[-1])
	print '-1:', i, 'last_month_base:', last_month_base, 'growth_monthly:', growth_monthly[-1], 'grm:', y_grm[-1]
	print '-1:', i, 'last_month_index_base:', last_month_index_base, 'index_growth_monthly:', index_growth_monthly[-1], 'igrw:', y_igrw[-1]

grm = Scatter(
	x = x_grm,
	y = y_grm,
	name = u'monthly %',
	marker = Marker(
		color = 'rgb(255, 0, 0)',
		)
	)
igrm = Scatter(
	x = x_igrm,
	y = y_igrm,
	name = u'index monthly %',
	marker = Marker(
		color = 'rgb(0, 0, 255)',
		)
	)


data_gr = Data([grd, igrd, grw, igrw, grm, igrm])

# perform request to remote or print out the data
if len(sys.argv) == 2 and sys.argv[1] == 'upload':
	unique_url = py.plot(data_tot, filename = 'port-stat', auto_open=False)
	print 'port-stat:', unique_url
	unique_url = py.plot(data_gr, filename = 'growth-stat', auto_open=False)
	print 'growth-stat:', unique_url
else:
	print 'daily:'
	print y_grd
	print growth_daily
	print y_igrd
	print index_growth_daily
	print 'weekly:'
	print y_grw
	print growth_weekly
	print y_igrw
	print index_growth_weekly
	print y_grm
	print growth_monthly
	print y_igrm
	print index_growth_monthly
