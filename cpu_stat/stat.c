#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/un.h>


#define FTIME_IN_STATE	"time_in_state"
#define NSTATE		6

struct time_in_state {
	int state;
	int time;
};

static int file_read(char *fname, char *pdata)
{
	FILE *fp = NULL;
	int sz = 0;
	int ret = 0;

	fp = fopen(fname, "r");
	if (!fp) {
		printf("open %s failed.\n", fname);
		return -EIO;
	}

	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	rewind(fp);

	ret = fread(pdata, sizeof(char), sz, fp);
	if (ret < 0) {
		printf("read failed, %d.\n", ret);
		fclose(fp);
		return -EIO;
	}

	fclose(fp);
	return ret;
}

static int fill_tis(struct time_in_state *tis, char *pbuf)
{
	printf("0x%p: ", tis);
	fputs(pbuf, stdout);
	return 0;
}

static int fill_tis_table(char *fname, struct time_in_state *tbl, char *buf)
{
	FILE *fp = NULL;
	char *pbuf = NULL;
	int sz = 0;
	int ret = 0;
	int i = 0;

	fp = fopen(fname, "r");
	if (!fp) {
		printf("open %s failed.\n", fname);
		return -EIO;
	}

	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	rewind(fp);

	do {
		if (i >= NSTATE) {
			printf("tis table full.\n");
			break;
		}
		pbuf = fgets(buf, sz, fp);
		if (pbuf == NULL) {
			printf("read failed.\n");
			fclose(fp);
			return -EIO;
		}

		ret = fill_tis(&tbl[i], pbuf);
		if (ret < 0) {
			printf("fill_tis failed.\n");
			fclose(fp);
			return -EIO;
		}
		i++;
	} while (pbuf != NULL);

	fclose(fp);
	return ret;
}

static int get_cpu_duty(struct time_in_state *tbl)
{
	return 0;
}

int main(int argc, char *argv[])
{
	int ret;
	char buf[256] = {0};
	int duty = 0;
	struct time_in_state tis_table[NSTATE];

	ret = file_read(FTIME_IN_STATE, buf);
	printf("ret %d\n", ret);
	fprintf(stdout, buf, 256);

	fill_tis_table(FTIME_IN_STATE, tis_table, buf);
	duty = get_cpu_duty(tis_table);

	printf("duty: %d\n", duty);

	return 0;
}
