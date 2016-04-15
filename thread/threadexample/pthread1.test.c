#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static thread1_exit = 0;
void *print_message_function( void *ptr );

main()
{
	pthread_t thread1;
	char *message1 = "Thread 1";
	int  iret1;
	int i;

	/* Create independent threads each of which will execute function */
	do {
		printf("%s, starting thread1\n", __func__);
		iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
		i = 0;
		while (1) {
			i++;
			printf("%s, i: %d\n", __func__, i);
			if (i >= 10) {
				thread1_exit = 1;
				break;
			}
			sleep(1);
		}
		iret1 = pthread_join( thread1, NULL);
		printf("%s, join ret: %d\n", __func__, iret1);
	} while (1);

	/* Wait till threads are complete before main continues. Unless we  */
	/* wait we run the risk of executing an exit which will terminate   */
	/* the process and all threads before the threads have completed.   */


	printf("Thread 1 returns: %d\n",iret1);
	exit(0);
}

void *print_message_function( void *ptr )
{
	char *message;
	message = (char *) ptr;
	printf("%s in\n", __func__);
	while (!thread1_exit) {
		printf("%s \n", message);
		sleep(1);
	}
	printf("%s out\n", __func__);
}
