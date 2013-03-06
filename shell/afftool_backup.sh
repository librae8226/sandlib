#!/system/bin/sh
#
# Copyright 2011 MARVELL SEMICONDUCTOR, LTD. All Rights Reserved.
# Author: yrliao@marvell.com (Yiran Liao)
#
# Called to do backup the affinity.

# NOTE!
# This script is used for suspend mechanism.

##### Customization ######
ENV_BAK_PATH=/tmp/.suspend.bak
IRQ_BAK_PATH=$ENV_BAK_PATH/irq
PS_BAK_PATH=$ENV_BAK_PATH/ps
IRQ_PROC_PATH=/proc/irq
SCHEDTOOL_PATH=/system/bin

rm -rf $ENV_BAK_PATH
# Backup irq
mkdir -p $IRQ_BAK_PATH
cd $IRQ_PROC_PATH
for name in `ls`
do
    $SCHEDTOOL_PATH/schedtool -x $IRQ_PROC_PATH/$name >> $IRQ_BAK_PATH/irq_affinity
done
cd - >/dev/null
# Backup ps
mkdir -p $PS_BAK_PATH
cd /proc
for name in `ls`
do
    echo $name | grep "^[0-9]\+$" >/dev/null
    if [ $? -eq 0 ]; then
        echo "$name" >> $PS_BAK_PATH/.ps_backup_tmp
    fi
done
pid=`cat $PS_BAK_PATH/.ps_backup_tmp`
$SCHEDTOOL_PATH/schedtool $pid > $PS_BAK_PATH/ps_affinity
cd - >/dev/null
