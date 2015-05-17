#!/bin/bash

# $1: mode, e.g.
#    digitalwrite
#    digitalread
#    anologwrite
#    anologread

# $2: param, e.g.
#    D7,HIGH (digital write high)
#    D7 (digital read)
#    A15,215 (anolog high)
#    A15 i(anolog read)

# EXAMPLE REQUEST IN TERMINAL
# Core ID is 48ff71065067555022312287
# Your access token is 12f1a31e1bfea0efeba12e36799b60c44184a1ed
curl https://api.spark.io/v1/devices/48ff71065067555022312287/$1 \
  -d access_token=a5bed30bce34a25109350f6ed83e4446172d23f3 -d args=$2

# Alternative, use command line tool

#spark login
#spark list
#spark call 48ff71065067555022312287 $1 $2

#spark call 48ff71065067555022312287 hello 'D'


# To flash
#spark flash --usb core-firmware.bin
