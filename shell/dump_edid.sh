#!/bin/sh

#addr=$((16#f7fe1c00))
addr=4160625664
cnt=0


while [ $cnt -lt 16 ] ; do
	#busybox devmem
	data=$addr
	printf "0x%x " $data
	#$addr=`busybox expr $addr + 4`
	addr=`expr $addr + 4`
	#mod=`busybox expr $cnt % 16`
	mod=`expr $cnt % 16`
	if [ $mod -eq 15 ] ; then
		#echo "(`busybox expr $cnt - 15`) "
		echo "(`expr $cnt - 15`)"
	fi
	#cnt=`busybox expr $cnt + 1`
	cnt=`expr $cnt + 1`
done
