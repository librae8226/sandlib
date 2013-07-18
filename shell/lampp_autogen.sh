#!/bin/bash

stat `pwd` | grep Modify > .autogen.diff.1

while true
do
	stat `pwd` | grep Modify > .autogen.diff.2
	diff .autogen.diff.2 .autogen.diff.1 > /dev/null
	if [ $? -eq 1 ]; then
		cp .autogen.diff.2 .autogen.diff.1
		echo "Update detected, ready to build..."
		jekyll build --destination /opt/lampp/htdocs/leafgrass
	fi
	sleep 5
done
