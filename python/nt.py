#!/usr/bin/env python

import requests
from geoip import geolite2

def ip2country():
    url = 'http://eth0.me'
    res = requests.get(url, timeout = 5)
    if res.text is not None:
        match = geolite2.lookup(res.text.strip())
        if match is not None:
            return match.country
    return 'CN'

ip2country()
