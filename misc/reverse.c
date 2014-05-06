#include <stdio.h>

void strrev(char *p)
{
	char *q = p;
	while(q && *q) ++q;
	for(--q; p < q; ++p, --q)
		*p = *p ^ *q, *q = *p ^ *q, *p = *p ^ *q;
}

int main(int argc, char **argv)
{
	do {
		printf("%s ",  argv[argc-1]); strrev(argv[argc-1]);
		printf("%s\n", argv[argc-1]);
	} while(--argc);

	return 0;
}
