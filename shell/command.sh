#!/bin/bash

today=`date +%Y%m%d%k%M%S`
res=tree$today
num_of_files=`ls -l | wc -l`

echo $res
echo $num_of_files

