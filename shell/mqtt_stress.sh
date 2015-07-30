#!/bin/sh

if [ $1exist = 'exist' -o $2exist = 'exist' ]; then
	echo "Invalid arguments"
	exit
fi
host=$1
topic=$2
cnt=0

#while [ $cnt -lt 256 ] ; do
while true; do
	mqtt_pub -h $host $topic "`date '+%Y-%m-%d %k:%M:%S'` stress #"$cnt
	echo "`expr $cnt`"
	cnt=`expr $cnt + 1`
	sleep 1
done
