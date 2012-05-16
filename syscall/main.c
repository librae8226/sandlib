#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PS_NAME		"syscall"
//#define PS_NAME		"abcdefg"
#define TMP_FILE	"/tmp/tmp_pidof"

int main(void)
{
	FILE *fp;
	int r = -1;

	system("pidof " PS_NAME "; echo $? > " TMP_FILE);
	fp = fopen(TMP_FILE, "r");
	fseek(fp, 0L, SEEK_SET);
	r = fgetc(fp);
	r = atoi((char *)&r);
	printf("r = %d\n", r);
	fclose(fp);
	system("rm " TMP_FILE);

	return 0;
}

