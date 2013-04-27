#!/bin/sh

# 0x50=80
slave=82
addr=0
cnt=0
i2cget=./bin/tools/i2cget
i2cset=./bin/tools/i2cset


printf "================================ slave: 0x%02x ==================================\n" $slave >> /tmp/eeprom_data
while [ $cnt -lt 256 ] ; do
	data=`$i2cget -f -y 0 $slave $addr`
	#$i2cset -f -y 0 $slave $addr $addr
	printf "0x%02x " $data >> /tmp/eeprom_data
	#$addr=`busybox expr $addr + 4`
	addr=`expr $addr + 1`
	#mod=`busybox expr $cnt % 16`
	mod=`expr $cnt % 16`
	if [ $mod -eq 15 ] ; then
		#echo "(`busybox expr $cnt - 15`) "
		echo "(`expr $cnt - 15`)"
		printf "\n" >> /tmp/eeprom_data
	fi
	#cnt=`busybox expr $cnt + 1`
	cnt=`expr $cnt + 1`
done
printf "==================================== end ======================================\n\n" $slave >> /tmp/eeprom_data
