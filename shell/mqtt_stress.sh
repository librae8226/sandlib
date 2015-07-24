#!/bin/sh

host=linkgo.io
topic=presence
cnt=0

#while [ $cnt -lt 256 ] ; do
while true; do
	mqtt_pub -h $host $topic "`date '+%Y-%m-%d %k:%M:%S'` stress #"$cnt
	echo "`expr $cnt`"
	cnt=`expr $cnt + 1`
	sleep 1
done
