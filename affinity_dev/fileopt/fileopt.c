#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VIRT_PROC_IRQ_DIR	"/home/yliao/Desktop/affinity_dev/irq"

int ps_affinity(char *filepath);
int irq_affinity(char *filepath);
unsigned long parse_affinity(char *arg);
int irq_set_affinity(const char *irq_dir, int iid, int aff);
int print_irq_affinity(const char *irq_dir);

int main(int argc, char *argv[])
{
	char *filepath = NULL;

	filepath = argv[1];
	print_irq_affinity(filepath);

	return 0;
}

int ps_affinity(char *filepath)
{
	FILE *fp = NULL;
	char ch = 0;
	char arr_pid[5] = {0};
	char arr_aff[3] = {0};
	pid_t pid = 0;
	unsigned long int aff = 0;

	if (filepath == NULL) {
		printf("please specify ps_affinity file!\n");
		return -1;
	}
	if ((fp = fopen(filepath, "r")) == NULL) {
		printf("`%s' open failed!\n", filepath);
		return -1;
	}
	fseek(fp, 0L, SEEK_SET);
	while (1) {
		fgets(arr_pid, 6, fp);
		pid = (pid_t)atoi(arr_pid);
		if (pid == 0) {
			fprintf(stderr, "get pid failed!\n");
		} else {
			fseek(fp, 1L, SEEK_CUR);
			fgets(arr_aff, 4, fp);
			aff = parse_affinity(arr_aff);
			if (fgetc(fp) == EOF)
				break;
			printf("%d: %lu\n", pid, aff);
			/* TODO process data */
		}
	}

	fclose(fp);
}

int irq_affinity(char *filepath)
{
	FILE *fp = NULL;
	char ch = 0;
	char irq_id[3] = {0};
	char irq_aff = 0;
	int iid = 0;
	int aff = 0;
	int ret = 0;

	if (filepath == NULL) {
		printf("please specify irq_affinity file!\n");
		return -1;
	}
	if ((fp = fopen(filepath, "r")) == NULL) {
		printf("`%s' open failed!\n", filepath);
		return -1;
	}
	fseek(fp, 0L, SEEK_SET);
	while (1) {
		fgets(irq_id, 4, fp);
		iid = atoi(irq_id);
		fseek(fp, 1L, SEEK_CUR);
		irq_aff = fgetc(fp);
		aff = atoi(&irq_aff);
		if (fgetc(fp) == EOF)
			break;
		printf("%d: %d\n", iid, aff);
		/* TODO process data */
		ret = irq_set_affinity(VIRT_PROC_IRQ_DIR, iid, aff);
		if (ret != 0)
			printf("irq_set_affinity failed!\n");
	}

	fclose(fp);
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

int irq_set_affinity(const char *irq_dir, int iid, int aff)
{
	char filepath[50] = {0};
	char iid_str[3] = {0};
	char aff_str[2] = {0};
	FILE *fp = NULL;

	/* WARN abort to check string length */
	strcpy(filepath, irq_dir);
	sprintf(iid_str, "%d", iid);
	strcat(filepath, "/");
	strcat(filepath, iid_str);
	strcat(filepath, "/");
	strcat(filepath, "smp_affinity");

	if (filepath == NULL) {
		printf("please specify irq smp_affinity file!\n");
		return -1;
	}
	if ((fp = fopen(filepath, "wb")) == NULL) {
		printf("`%s' open failed!\n", filepath);
		return -1;
	}
	fseek(fp, 0L, SEEK_SET);
	sprintf(aff_str, "%d\n", aff);
	fputs(aff_str, fp);

	fclose(fp);
	return 0;
}

int print_irq_affinity(const char *irq_dir)
{
	char filepath[100] = {0};
	char aff_str[2] = {0};
	char *pstr = NULL;
	char *pstr_iid = NULL;
	int iid = 0;
	FILE *fp = NULL;

	/* WARN abort to check string length */
	strcpy(filepath, irq_dir);
	pstr = filepath;
	while (*pstr != '\0') {
		if (*pstr == '/' && *(pstr + 1) != '\0')
			pstr_iid = pstr + 1;
		pstr++;
	}
	if (pstr_iid == NULL || *pstr_iid == 'd')
		return -1;
	iid = atoi(pstr_iid);
	strcat(filepath, "/");
	strcat(filepath, "smp_affinity");

	if (filepath == NULL) {
		printf("please specify irq smp_affinity file!\n");
		return -1;
	}
	if ((fp = fopen(filepath, "r")) == NULL) {
		printf("`%s' open failed!\n", filepath);
		return -1;
	}
	fseek(fp, 0L, SEEK_SET);
	fgets(aff_str, 2, fp);
	printf("%3d %s\n", iid, aff_str);

	fclose(fp);
	return 0;
}
