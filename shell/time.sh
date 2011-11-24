#!/bin/sh

echo "--------------------"
timeStart=$(date +%s)
$*
timeEnd=$(date +%s)
echo "--------------------"
delta=`expr $timeEnd - $timeStart`
echo "Time Elapsed: $delta"
