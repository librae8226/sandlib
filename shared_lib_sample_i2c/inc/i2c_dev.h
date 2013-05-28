#ifndef __LIB_I2C_DEV_H__
#define __LIB_I2C_DEV_H__

/* This is the structure as used in the I2C_RDWR ioctl call */
struct i2c_rdwr_ioctl_data {
	struct i2c_msg *msgs;
	unsigned int nmsgs;
};

int i2c_open(int id);
int i2c_close(int fd);
int i2c_rdwr_bytes(int fd, struct i2c_msg *msgs, int nmsgs);

#endif
