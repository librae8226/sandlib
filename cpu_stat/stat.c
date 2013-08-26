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
#define NSTATE_MAX	32

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
	char tbuf[16] = {0};
	char sbuf[16] = {0};
	char *p = NULL;

	assert(pbuf != NULL);
	assert(tis != NULL);

	printf("0x%p: ", tis);
	fputs(pbuf, stdout);

	p = strrchr(pbuf, ' ');
	assert(p != NULL);

	strcpy(tbuf, p + 1);
	strncpy(sbuf, pbuf, p - pbuf);

	tis->state = atoi(sbuf);
	tis->time = atoi(tbuf);

	printf("s: %d\n", tis->state);
	printf("t: %d\n", tis->time);

	return 0;
}

static int fill_tis_table(char *fname, struct time_in_state tbl[], char *buf)
{
	FILE *fp = NULL;
	char *pbuf = NULL;
	int sz = 0;
	int ret = 0;
	int i = 0;

	assert(tbl != NULL);
	assert(buf != NULL);

	fp = fopen(fname, "r");
	if (!fp) {
		printf("open %s failed.\n", fname);
		return -EIO;
	}

	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	rewind(fp);

	do {
		pbuf = fgets(buf, sz, fp);
		if (pbuf == NULL)
			break;

		ret = fill_tis(&tbl[i], pbuf);
		if (ret < 0) {
			printf("fill_tis failed.\n");
			fclose(fp);
			return -EIO;
		}
		i++;
	} while (pbuf != NULL);

	printf("nstate: %d\n", i);

	fclose(fp);
	return i;
}

static unsigned int get_cpu_duty(struct time_in_state tbl[], int nstate)
{
	int smax = 0;
	int tmax = 0;
	int idmax = 0;
	int time_sum = 0;
	int i;
	unsigned int duty;

	for (i = 0; i < nstate; i++) {
		if (smax < tbl[i].state) {
			smax = tbl[i].state;
			idmax = i;
		}
		time_sum += tbl[i].time;
	}

	tmax = tbl[idmax].time;
	printf("id: %d, smax: %d, tmax: %d\n", idmax, smax, tmax);
	duty = (unsigned int)tmax * 100 / time_sum;

	return duty;
}

int main(int argc, char *argv[])
{
	int ret;
	char buf[256] = {0};
	int duty = 0;
	int nstate = 0;
	struct time_in_state tis_table[NSTATE_MAX];

	ret = file_read(FTIME_IN_STATE, buf);
	printf("ret %d\n", ret);
	printf("raw data:\n");
	fprintf(stdout, buf, 256);

	printf("process:\n");
	nstate = fill_tis_table(FTIME_IN_STATE, tis_table, buf);
	duty = get_cpu_duty(tis_table, nstate);

	printf("duty: %d\n", duty);

	return 0;
}
