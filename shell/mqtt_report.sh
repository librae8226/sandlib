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
#	mqtt_pub -h $host $topic "`date '+%Y-%m-%d %k:%M:%S'` #"$cnt
	WEATHERJSON=/tmp/openweathermap.json
	FORECASTJSON=/tmp/openweathermap_forecast.json
	curl -X GET 'api.openweathermap.org/data/2.5/find?q=Shanghai&units=metric&appid=2de143494c0b295cca9337e1e96b00e0' > $WEATHERJSON
	curl -X GET 'api.openweathermap.org/data/2.5/forecast/daily?q=Shanghai&units=metric&cnt=2&appid=2de143494c0b295cca9337e1e96b00e0' > $FORECASTJSON
	city=`cat $WEATHERJSON | JSON.sh -b | grep "name" | awk '{print $2}' | sed -e 's/^"//'  -e 's/"$//'`
	weather=`cat $WEATHERJSON | JSON.sh -b | grep "\"weather\",0,\"main\"" | awk '{print substr($0, index($0,$2))}' | sed -e 's/^"//'  -e 's/"$//'`
	temp=`cat $WEATHERJSON | JSON.sh -b | grep "\"temp\"" | awk '{print $2}'`
	weather_f=`cat $FORECASTJSON | JSON.sh -b | grep "\"list\",1,\"weather\",0,\"main\"" | awk '{print substr($0, index($0,$2))}' | sed -e 's/^"//'  -e 's/"$//'`
	temp_f_min=`cat $FORECASTJSON | JSON.sh -b | grep "\"list\",1,\"temp\",\"min\"" | awk '{print $2}'`
	temp_f_max=`cat $FORECASTJSON | JSON.sh -b | grep "\"list\",1,\"temp\",\"max\"" | awk '{print $2}'`
	pahopub $topic --host $host --msg ""
	pahopub $topic --host $host --msg "----- cut $cnt -----"
	pahopub $topic --host $host --msg "`date '+%Y-%m-%d %k:%M:%S'`"
	pahopub $topic --host $host --msg "<$city Weather>"
	pahopub $topic --host $host --msg "tod: $temp'C $weather"
	pahopub $topic --host $host --msg "tom: $temp_f_min:$temp_f_max'C $weather_f"
	pahopub $topic --host $host --msg "<Biloba Status>"
	pahopub $topic --host $host --msg "cpu: `cat /proc/loadavg | awk '{print $1}'`%  task: `cat /proc/loadavg | awk '{print $4}'`"
	mem=$(expr `free -m | awk '{print $3}' | awk 'NR==3'` \* 100 / 16034)
	pahopub $topic --host $host --msg "mem: `printf "%4d" $mem`%    swap: $(expr `free -m | awk '{print $3}' | awk 'NR==4'` \* 100 / 15920)%"
	t00=$(expr `cat /sys/class/hwmon/hwmon1/temp2_input` / 1000)
	t01=$(expr `cat /sys/class/hwmon/hwmon1/temp3_input` / 1000)
	t02=$(expr `cat /sys/class/hwmon/hwmon1/temp4_input` / 1000)
	t03=$(expr `cat /sys/class/hwmon/hwmon1/temp5_input` / 1000)
	pahopub $topic --host $host --msg "t0: $t00'C $t01'C $t02'C $t03'C"
	t10=$(expr `cat /sys/class/hwmon/hwmon2/temp2_input` / 1000)
	t11=$(expr `cat /sys/class/hwmon/hwmon2/temp3_input` / 1000)
	t12=$(expr `cat /sys/class/hwmon/hwmon2/temp4_input` / 1000)
	t13=$(expr `cat /sys/class/hwmon/hwmon2/temp5_input` / 1000)
	pahopub $topic --host $host --msg "t1: $t10'C $t11'C $t12'C $t13'C"
	echo "`expr $cnt`"
	cnt=`expr $cnt + 1`
done
