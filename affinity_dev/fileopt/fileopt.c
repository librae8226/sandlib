#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned long parse_affinity(char *arg);

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char *filepath = NULL;
	char ch = 0;
	char arr_pid[5] = {0};
	char arr_aff[3] = {0};
	pid_t pid = 0;
	unsigned long aff = 0;

	filepath = argv[1];
	printf("file path: %s\n",filepath); 
	if (filepath == NULL) {
		printf("please specify a file!\n");
		return -1;
	}
	if ((fp = fopen(filepath, "r")) == NULL) {
		printf("`%s' open failed!\n", filepath);
		return -1;
	}
	fseek(fp, 0L, SEEK_SET);
	while(1) {
		fgets(arr_pid, 6, fp);
		pid = (pid_t)atoi(arr_pid);
		if (pid == 0) {
			fprintf(stderr, "get pid failed!\n");
		} else {
			printf("%d", pid);
			fseek(fp, 1L, SEEK_CUR);
			fgets(arr_aff, 4, fp);
			printf(": %s\n", arr_aff);
			/* TODO process data */
			printf(">>> pid: %d, aff: %lu\n", pid, parse_affinity(arr_aff));
			if (fgetc(fp) == EOF)
				break;
		}
	}

	fclose(fp);
	return 0;
}

unsigned long parse_affinity(char *arg)
{
	unsigned long tmp_aff=0;
	char *tmp_arg;
	size_t valid_len;
	char *optarg = arg;

	if(*arg == '0' && *(arg+1) == 'x') {
		/* we're in standard hex mode */
		tmp_aff=strtol(optarg, NULL, 16);

	} else if ((valid_len=strspn(arg, "0123456789,."))) {
		/* new list mode: schedtool -a 0,2 -> run on CPU0 and CPU2 */

		/* split on ',' and '.', because '.' is near ',' :) */
		while((tmp_arg=strsep(&arg, ",."))) {
			int tmp_shift;

			if(isdigit((int)*tmp_arg)) {
				tmp_shift=atoi(tmp_arg);
				tmp_aff |= (0x1 << tmp_shift);
			}
		}

	} else {
		exit(1);
	}
	return tmp_aff;
}
