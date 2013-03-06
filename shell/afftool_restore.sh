#!/system/bin/sh
#
# Copyright 2011 MARVELL SEMICONDUCTOR, LTD. All Rights Reserved.
# Author: yrliao@marvell.com (Yiran Liao)
#
# Called to do restore the affinity.

# NOTE!
# This script is used for resume mechanism.

##### Customization ######
ENV_BAK_PATH=/tmp/.suspend.bak
IRQ_BAK_PATH=$ENV_BAK_PATH/irq
PS_BAK_PATH=$ENV_BAK_PATH/ps
IRQ_PROC_PATH=/proc/irq
SCHEDTOOL_PATH=/system/bin

# Restore irq
cd $IRQ_BAK_PATH
$SCHEDTOOL_PATH/schedtool -y $IRQ_BAK_PATH/irq_affinity >/dev/null 2>&1
cd - >/dev/null
# Restore ps
cd $PS_BAK_PATH
$SCHEDTOOL_PATH/schedtool -z $PS_BAK_PATH/ps_affinity >/dev/null 2>&1
cd - >/dev/null
