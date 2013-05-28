#include <sys/ioctl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <linux/i2c.h>

#ifndef ANDROID
#include <linux/i2c-dev.h>
#else
#include "i2c_dev.h"
#endif

#include "i2c_dbg.h"

static char *__id_to_dev(int id)
{
	switch (id) {
	case 0:
		return "/dev/i2c-0";
	case 1:
		return "/dev/i2c-1";
	case 2:
		return "/dev/i2c-2";
	case 3:
		return "/dev/i2c-3";
	default:
		return NULL;
	}
}

int i2c_open(int id)
{
	int fd;
	char *dev = __id_to_dev(id);
	if ((fd = open(dev, O_RDWR)) < 0)
		SLOGE("Could not open i2c at %s\n", dev);
	return fd;
}

int i2c_close(int fd)
{
	if (fd > 0)
		close(fd);
	return 0;
}

int i2c_rdwr_bytes(int fd, struct i2c_msg *msgs, int nmsgs)
{
	struct i2c_rdwr_ioctl_data msg_rdwr;
	int ret;

	if (fd < 0) {
		SLOGE("File descriptor error: %d\n", fd);
		return -EBADF;
	}

	msg_rdwr.msgs = msgs;
	msg_rdwr.nmsgs = nmsgs;

	if ((ret = ioctl(fd, I2C_RDWR, &msg_rdwr)) < 0) {
		SLOGE("ioctl error: %d\n", ret);
		return -EIO;
	}

	return 0;
}
