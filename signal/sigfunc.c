#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int should_exit = 0;

void sig_handler(int signo)
{
	switch (signo) {
	case SIGINT:
		should_exit = 1;
		printf("received SIGINT\n");
		break;
	case SIGTERM:
		should_exit = 1;
		printf("received SIGTERM\n");
		break;
	default:
		printf("unhandled signal: %d\n", signo);
		break;
	}
}

int stop(void)
{
	int pid = getpid();
	if (pid > 0) {
		printf("Sending SIGTERM to %d\n", pid);
		return kill(pid, SIGTERM);
	}

	return 0;
}

int signal_init(void)
{
	struct sigaction act;

	act.sa_handler = sig_handler;

	memset(&act.sa_mask, 0, sizeof(act.sa_mask));

	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	sigaction(SIGTERM, &act, 0);
	sigaction(SIGINT, &act, 0);

	return 0;
}


int main(void)
{
	char cmd;

	signal_init();

	/*
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGINT\n");
	*/

	/*
	 * A long long wait so that
	 * we can easily issue a signal to this process
	 */
	printf("command: ");
	while (!should_exit) {
		scanf("%c", &cmd);
		switch (cmd) {
		case 's':
			stop();
			break;
		case '\n':
			continue;
			break;
		default:
			printf("unsupported cmd: %c\n", cmd);
			break;
		}
		sleep(1);
		printf("command: ");
	}

	return 0;
}
