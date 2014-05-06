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
	printf("penc: %s\n",  argv[argc-1]);
	strrev(argv[argc-1]);
	printf("ltk:  %s\n", &argv[argc-1][24]);
	return 0;
}
