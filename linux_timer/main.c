#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>

int count = 0;

void set_timer()
{
	struct itimerval itv, oldtv;
	itv.it_interval.tv_sec = 0;
	itv.it_interval.tv_usec = 1000;
	itv.it_value.tv_sec = 1;
	itv.it_value.tv_usec = 0;

	setitimer(ITIMER_REAL, &itv, &oldtv);
}

void sigalarm_handler(int sig)
{
	count++;
	if (count % 1000 == 0)
		printf("count: %d\n", count);
}

int main(int argc, char *argv[])
{
	signal(SIGALRM, sigalarm_handler);
	set_timer();
	while (count < 10000) {
	}
	return 0;
}

