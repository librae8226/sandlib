#include <stdio.h>
#include <stdlib.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({            \
		const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
		(type *)( (char *)__mptr - offsetof(type,member) );})

#define CONT(prt, type, mem) container_of((prt), type, mem)

struct test {
	int a;
};

struct m {
	int b;
	struct test t;
	int c;
};

int main(int argc, char *argv[])
{
	/* existing structure */
	struct m *ma;
	ma = malloc(sizeof(struct m));
	ma->t.a = 5;
	ma->b = 3;
	/* pointer to existing entry */
	struct test *te = &ma->t;

	struct m *m = CONT(te, struct m, t);

	printf("m->b = %d\n", m->b);

	return EXIT_SUCCESS;
}
