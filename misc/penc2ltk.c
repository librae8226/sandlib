#include <stdio.h>
#include <string.h>

void strrev(char *p)
{
	char *q = p;
	while(q && *q) ++q;
	for(--q; p < q; ++p, --q)
		*p = *p ^ *q, *q = *p ^ *q, *p = *p ^ *q;
}

int main(int argc, char **argv)
{
	char ltk[33] = {0};
	char tmp, i;
	printf("penc: %s\n",  argv[argc-1]);
	strrev(argv[argc-1]);
	strcpy(ltk, &argv[argc-1][24]);
	for (i = 0; i < 32; i += 2) {
		tmp = ltk[i];
		ltk[i] = ltk[i + 1];
		ltk[i + 1] = tmp;
	}
	printf("ltk:  %s\n", ltk);
	return 0;
}
