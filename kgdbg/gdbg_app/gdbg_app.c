#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/rtc.h>
#include <linux/ioctl.h>
#include <linux/fs.h>
#include <stdio.h>
#include <stdlib.h>
#include "OSAL_api.h"


#define DEV_NODE        "/dev/gdbg"
#define COMMAND1        0x1
#define COMMAND2        0x2
#define CMD_WRITE_REG   0x55
#define CMD_READ_REG    0xAA
#define SEEK_FIXED      0x0 /* FIXME this value must be 0/1? */
#define SEEK_INC        0x1
#define ENABLE_WRITE    1   /* we'd better not write to register directly */
#define MAX_R_BYTES     1024


void app_init(const char *dev_node, int *pfd);
void app_fin(int fd);
int app_write(int fd, unsigned int addr, unsigned int *data, unsigned int nb);
int app_read(int fd, unsigned int addr, unsigned int *data, unsigned int nb);
static void usage(void);
static void test(void);
static void test_rw_reg(void);

struct mem_unit {
	unsigned int addr;
	unsigned int val;
};

int fd = 0;


int main(int argc, char *argv[])
{
	char arg = 0;
	unsigned int addr = 0;
	unsigned int val = 0;
	unsigned int nb = 0;
	int i = 0, j = 0;
	struct mem_unit r_buf[MAX_R_BYTES];

	memset(r_buf, 0, sizeof(struct mem_unit));

	if (argc != 4 || *argv[1] != '-') {
		usage();
		return -1;
	} else {
		arg = *(argv[1] + 1);
		//printf(">>> %s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]);
	}

	app_init(DEV_NODE, &fd);

	switch (arg) {
	case 'w':
		sscanf(argv[2], "%X", &addr);
		sscanf(argv[3], "%X", &val);
		//printf("w %08X %08X\n", addr, val);
		app_write(fd, addr, &val, sizeof(unsigned int));
		break;
	case 'r':
		sscanf(argv[2], "%X", &addr);
		nb = atoi(argv[3]);
		//printf("r %08X %08X\n", addr, nb);
		printf("@ADDRESS   @MSB ... @LSB\n");
		for (i = 0; i < nb; i++) {
			app_read(fd, addr + i, &val, 1);
			r_buf[i].addr = addr + i;
			r_buf[i].val = val;
		}
		for (i = 0; i < nb; i += 4) {
			printf("%08X:  ", r_buf[i].addr);
			for (j = 3; j >= 0; j--) {
				if (i + j < nb)
					printf("%02X ", r_buf[i + j].val);
				else
					printf("   ");
			}
			printf("\n");
		}
		break;
	default:
		usage();
		break;
	}

	app_fin(fd);

	return 0;
}

void app_init(const char *dev_node, int *pfd)
{
	*pfd = open(dev_node, O_RDWR);
	if( *pfd == -1) {
		perror("error open\n");
		exit(-1);
	}
}

void app_fin(int fd)
{
	close(fd);
}

int app_write(int fd, unsigned int addr, unsigned int *data, unsigned int nb)
{
	int retval = 0;

	retval = lseek(fd, 0, SEEK_FIXED);
	if (retval == -1) {
		perror("lseek error\n");
		exit(-1);
	}

	retval = write(fd, data, nb);
	if (retval == -1) {
		perror("write error\n");
		exit(-1);
	} else {
		printf("data write to 0x%08X:\n0x%08X\n", addr, *data);
	}
	MV_OSAL_Task_Sleep(10);

#if (ENABLE_WRITE == 1)
	retval = ioctl(fd, CMD_WRITE_REG, addr);
	if (retval == -1) {
		perror("ioctl error\n");
		exit(-1);
	}
#endif

	return retval;
}

int app_read(int fd, unsigned int addr, unsigned int *data, unsigned int nb)
{
	int retval = 0;

	retval = ioctl(fd, CMD_READ_REG, addr);
	if (retval == -1) {
		perror("ioctl error\n");
		exit(-1);
	}

	retval = lseek(fd, 0, SEEK_FIXED);
	if (retval == -1) {
		perror("lseek error\n");
		exit(-1);
	}

	retval = read(fd, data, nb);
	if(retval == -1) {
		perror("read error\n");
		exit(-1);
	} else {
		//printf("data read from kernel space:\n0x%08X\n", *data);
	}
	MV_OSAL_Task_Sleep(2);

	return retval;
}

static void usage(void)
{
	printf("Usage: gdbg [OPTION] ARGS...\n");
	printf("  NOTE!\n");
	printf("  Please make sure you have done mknod & insmod before doing so.\n\n");

	printf("  -w\n\twrite data to kernel space memory\n");
	printf("\tARGS: addr, data\n");
	printf("\t- write data to addr\n");
	printf("\te.g. gdbg_app -w F7FCD040 1C400\n");

	printf("  -r\n\tread data from kernel space memory\n");
	printf("\tARGS: addr, nbytes\n");
	printf("\t- read nbytes start from addr\n");
	printf("\te.g. gdbg_app -r F7FCD040 8\n");

	printf("  -h\n\tshow this menu\n");

	printf("\n");
}

static void test(void)
{
	int fd = 0;
	char data_out[256] = {0};
	char data_in[256] = "data to test gdbg module";
	int retval = 0;

	fd = open("/dev/gdbg", O_RDWR);
	if( fd == -1) {
		perror("error open\n");
		exit(-1);
	}
	MV_OSAL_Task_Sleep(50);

	retval = ioctl(fd, COMMAND1, 0);
	if (retval == -1) {
		perror("ioctl error\n");
		exit(-1);
	}
	MV_OSAL_Task_Sleep(50);

	retval = write(fd, data_in, strlen(data_in));
	if (retval == -1) {
		perror("write error\n");
		exit(-1);
	} else {
		printf("data write to kernel space:\n%s\n", data_in);
	}
	MV_OSAL_Task_Sleep(50);

	retval = lseek(fd, 3, SEEK_FIXED);
	if (retval == -1) {
		perror("lseek error\n");
		exit(-1);
	}
	MV_OSAL_Task_Sleep(50);

	retval = read(fd, data_out, 4);
	if(retval == -1) {
		perror("read error\n");
		exit(-1);
	} else {
		printf("data read from kernel space:\n%s\n", data_out);
	}
	MV_OSAL_Task_Sleep(50);

	close(fd);
}

static void test_rw_reg(void)
{
	unsigned int data_in = 0;
	unsigned int data_out = 0;

	app_init(DEV_NODE, &fd);
	app_read(fd, 0xF7FCD040, &data_out, sizeof(unsigned int));
	data_in = data_out;
	app_write(fd, 0xF7FCD040, &data_in, sizeof(unsigned int));
	app_read(fd, 0xF7FCD040, &data_out, sizeof(unsigned int));
	app_fin(fd);
}

