#!/usr/bin/env python

import sys
import math
import json
from pprint import pprint

# CONSTANTS
NITEMS = 3

json_data=open('public.json')

data = json.load(json_data)
pprint(data)

capital = range(0, NITEMS)
total = range(0, NITEMS)

for i in range(0, NITEMS):
	capital[i] = float(data[i]["capital"])
	total[i] = float(data[i]["total"])

for i in range(0, NITEMS):
	print '{0:s} - {1:8.2f} - {2:8.2f} - ({3:s})'.format(data[i]["timestamp"], capital[i], total[i], data[i]["info"])

for i in range(0, NITEMS):
	sys.stdout.write("{0} # {1:>8} # {2:>8} # ({3})\n".format(data[i]["timestamp"], data[i]["capital"], data[i]["total"], data[i]["info"]))

json_data.close()

print 'The value of PI is approximately {0:.3f}.'.format(math.pi)
