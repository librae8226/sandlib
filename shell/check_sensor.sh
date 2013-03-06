#!/bin/sh

# This file is only a sample for specific board.

# Calculation Form (e.g.)
# I * 0.01ohm * 50 = 1.86V * cur_raw / 1024
# V / 3 = 1.86V * volt_raw / 1024

# It accesses the hwmon sysfs to get current and voltage data.
# The factor used to calculate could be different.
# Modify the variables for customization.
# Most of the hard code are related to HW rework.

if [ $1exist = 'exist' ]; then
	echo $0 INTERVAL
	echo INTERVAL: interval between each sample, in second
	exit
fi
interval=$1

FILE_ADC_CH_CURRENT=/sys/class/hwmon/hwmon0/adc_ch0_data
FILE_ADC_CH_VOLTAGE=/sys/class/hwmon/hwmon0/adc_ch1_data

ADC_REF=1860
ADC_MAX_SCOPE=1024

while true
do
	curr_raw=`cat $FILE_ADC_CH_CURRENT`
	volt_raw=`cat $FILE_ADC_CH_VOLTAGE`
	curr=$(($curr_raw * $ADC_REF))
	curr=$(($curr / $ADC_MAX_SCOPE))
	curr=$(($curr * 2))
	volt=$(($volt_raw * $ADC_REF))
	volt=$(($volt / $ADC_MAX_SCOPE))
	volt=$(($volt * 3))
	pwr=$(($curr*$volt))
	pwr=$(($pwr/1000))

	echo "current: "$curr "mA" '('$curr_raw')'
	echo "voltage: "$volt "mV" '('$volt_raw')'
	echo "power: "$pwr "mW"
	sleep $interval
done
