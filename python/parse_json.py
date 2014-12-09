#!/usr/bin/env python

import json
from pprint import pprint
json_data=open('public.json')

data = json.load(json_data)
pprint(data)

for i in range(1,11):
	print '{0} - {1}'.format(data[i]["timestamp"], data[i]["brewTemp"])

json_data.close()
