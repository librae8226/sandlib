#!/bin/sh

# NOTE!
# This script is used for suspend & resume mechanism.
# All critial and miscellaneous stuffs could backup and restore in this script
# Add more requirements by provide functions as backup_xxx() and restore_xxx().

##### customization ######
ENV_BAK_PATH=/home/yliao/Desktop/affinity_dev/suspend.bak
IRQ_BAK_PATH=$ENV_BAK_PATH/irq
PS_BAK_PATH=$ENV_BAK_PATH/ps
IRQ_PROC_PATH=/home/yliao/Desktop/affinity_dev/irq
SCHEDTOOL_PATH=/system/bin
TOOL_PREFIX=

backup_irq()
{
	mkdir -p $IRQ_BAK_PATH
	$TOOL_PREFIX touch $IRQ_BAK_PATH/irq_affinity
	cd $IRQ_PROC_PATH
	for name in `ls`
	do
		#$TOOL_PREFIX printf "%3d %d\n" $name `cat $name/smp_affinity 2>/dev/null` >> $IRQ_BAK_PATH/irq_affinity
		/home/yliao/Desktop/affinity_dev/fileopt/fileopt $IRQ_PROC_PATH/$name >> $IRQ_BAK_PATH/irq_affinity
	done
	cd - >/dev/null
}

restore_irq()
{
	cd $IRQ_BAK_PATH
	while read line
	do
		echo "$line" > .irq_restore_tmp
		name=`$TOOL_PREFIX awk '{print $1}'` < .irq_restore_tmp
		aff=`$TOOL_PREFIX awk '{print $2}'` < .irq_restore_tmp
		echo $aff > $IRQ_PROC_PATH/$name/smp_affinity
	done < irq_affinity
	cd - >/dev/null
}

backup_ps()
{
	mkdir -p $PS_BAK_PATH
	$TOOL_PREFIX touch $PS_BAK_PATH/ps_affinity
	$TOOL_PREFIX touch $PS_BAK_PATH/.ps_backup_tmp
	cd /proc
	for name in `ls`
	do
		$TOOL_PREFIX expr $name : '^[0-9]\+$' >/dev/null 2>&1
		if [ $? -eq 0 ]; then
			echo "$name" >> $PS_BAK_PATH/.ps_backup_tmp
		fi
	done
	pid=`cat $PS_BAK_PATH/.ps_backup_tmp`
	$SCHEDTOOL_PATH/schedtool $pid > $PS_BAK_PATH/ps_affinity
	cd - >/dev/null
}

restore_ps()
{
	cd $PS_BAK_PATH
	$SCHEDTOOL_PATH/schedtool -z $PS_BAK_PATH/ps_affinity >/dev/null 2>&1
	cd - >/dev/null
}

main()
{
	if [ -n "$1" ]; then
		if [ $1 == "backup" ]; then
			rm -rf $ENV_BAK_PATH
			backup_irq
			#backup_ps
			:
		elif [ $1 == "restore" ]; then
			#restore_irq
			#restore_ps
			:
		else
			echo "USAGE: ./afftool.sh ARG"
			echo "ARG could be: backup OR restore."
		fi

	else
		echo "USAGE: ./afftool.sh ARG"
		echo "ARG could be: backup OR restore."
	fi
}

main "$@"
