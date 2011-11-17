#!/bin/sh

IRQ_BAK_PATH=/home/yliao/Desktop/affinity_dev/irq
IRQ_PROC_PATH=/home/yliao/Desktop/affinity_dev/irq_test
PS_BAK_PATH=/home/yliao/Desktop/affinity_dev/ps
SCHEDTOOL_PATH=/home/yliao/Desktop/affinity_dev

backup_irq()
{
	cd /proc/irq
	for name in `ls`
	do
		test -d $name
		if [ $? == "0" ]; then
			cd $name
			pwd
			mkdir -p $IRQ_BAK_PATH/$name
			touch $IRQ_BAK_PATH/$name/smp_affinity
			cat ./smp_affinity > $IRQ_BAK_PATH/$name/smp_affinity
			cd ..
		fi
	done
	cd - >/dev/null
}

restore_irq()
{
	cd $IRQ_BAK_PATH
	for name in `ls`
	do
		cd $name
		pwd
		cat ./smp_affinity > $IRQ_PROC_PATH/$name/smp_affinity
		cd ..
	done
	cd - >/dev/null
}

backup_ps()
{
	cd /proc
	for name in `ls`
	do
		#if [[ $name =~ ^[0-9]*.?[0-9]*$ ]]; then     
		#	echo "$name is numeric !!!"
		#else
		#	echo "$name is NOT numeric"
		#fi
		expr $name : '^[0-9]\+$' >/dev/null 2>&1
		if [ $? -eq 0 ]; then
			aff=`$SCHEDTOOL_PATH/schedtool $name | awk -F , '{print $4}' | awk -F " " '{print $2}'`
			if [ "$aff" ]; then
				mkdir -p $PS_BAK_PATH/$name
				touch $PS_BAK_PATH/$name/ps_affinity
				echo $aff > $PS_BAK_PATH/$name/ps_affinity
			else
				echo "NULL string"
			fi
		fi
	done
	cd - >/dev/null
}

restore_ps()
{
	cd $PS_BAK_PATH
	for name in `ls`
	do
		$SCHEDTOOL_PATH/schedtool -a `cat $name/ps_affinity` $name
	done
	cd - >/dev/null
}

echo '[backup begin]'
backup_ps
echo '[backup done]'
echo '[restore begin]'
restore_ps
echo '[restore done]'
