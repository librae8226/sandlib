#!/bin/bash

if [ $1null = 'null' ]; then
	FILE=./cscope.files
else
	FILE=$1
fi
echo 'Gen from' $FILE
cscope -R -b -i $FILE
