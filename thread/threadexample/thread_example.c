/* 
 * @FILE	thread_example.c
 * @BRIEF	c multiple thread programming in linux
 * @AUTHOR	falcon
 * @EMAIL	tunzhj03@st.lzu.edu.cn
 * @CHANGE	librae
 */

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>

#define MAX 10

struct _operations
{
	void (*open)(void);
	int (*read)(void);
	void (*write)(int data);
	void (*close)(void);
};
pthread_t thread[2];
pthread_mutex_t mut;
int number = 0;
int i;

static void drv_open(void);
static int drv_read(void);
static void drv_write(int data);
static void drv_close(void);

struct _operations drv_opt =
{
	.open = drv_open,
	.read = drv_read,
	.write = drv_write,
	.close = drv_close,
};

void *thread1(void)
{
	printf ("thread1: I'm thread 1\n");
	drv_open();
	for (i = 0; i < MAX; i++)
	{
		printf("thread1: number = %d\n",number);
		pthread_mutex_lock(&mut);
		number = drv_read();
		pthread_mutex_unlock(&mut);
		sleep(2);
	}
	printf("thread1: Is main() waiting for my finishing\n");
	drv_close();
	pthread_exit(NULL);
}

void *thread2(void)
{
	printf("thread2 : I'm thread 2\n");
	for (i = 0; i < MAX; i++)
	{
		printf("thread2: number = %d\n",number);
		pthread_mutex_lock(&mut);
		drv_write(i);
		pthread_mutex_unlock(&mut);
		sleep(3);
	}
	printf("thread2: Is main() waiting for my finishing?\n");
	pthread_exit(NULL);
}

void thread_create(void)
{
	int temp;
	memset(&thread, 0, sizeof(thread));
	/* Creating threads */

	if ((temp = pthread_create(&thread[0], NULL, (void *)thread1, NULL)) != 0) {
		printf("Failed to create thread 1!\n");
	} else {
		printf("Thread 1 has beed created.\n");
	}
	if ((temp = pthread_create(&thread[1], NULL, (void *)thread2, NULL)) != 0) {
		printf("Failed to create thread 2!\n");
	} else {
		printf("Thread 2 has beed created.\n");
	}
}

void thread_wait(void)
{
	/* Waiting for threads finish */

	if(thread[0] !=0) {
		pthread_join(thread[0],NULL);
		printf("Thread 1 has beed finished.\n");
	}
	if(thread[1] !=0) {
		pthread_join(thread[1],NULL);
		printf("Thread 2 has beed finished.\n");
	}
}

static void drv_open(void)
{
	printf("drv_open.\n");
}

static int drv_read(void)
{
	printf("drv_read.\n");
	return number;
}

static void drv_write(int data)
{
	printf("drv_write.\n");
	number = data;
}

static void drv_close(void)
{
	printf("drv_close.\n");
}

int main(void)
{
	/* Initialize the mutex with default properties */
	pthread_mutex_init(&mut, NULL);
	printf("I'm the main task and I am creating threads, hoho~\n");
	thread_create();
	printf("I'm the main task and I am waiting for threads finished, hoho~\n");
	thread_wait();
	return 0;
}

