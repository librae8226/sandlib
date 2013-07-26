#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static void jmpfunction(jmp_buf env_buf)
{
	longjmp(env_buf, (int)"tutorialspoint.com");
}

int main(int argc, char *argv[])
{
	int val;
	jmp_buf env_buffer;

	/* save calling environment for longjmp */
	val = setjmp(env_buffer);
	if (val != 0) {
		printf("Returned from a longjmp() with value = %s\n", val);
		exit(0);
	}
	printf("Jump function call\n");
	jmpfunction(env_buffer);

	return 0;
}
