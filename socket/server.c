/*
 * A simple server in the internet domain using TCP
 * The port number is passed as an argument
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

volatile int stop = 0;

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

void cfinish(int sig)
{
	printf("%s sig: %d.\n", __func__, sig);
	signal(SIGINT, NULL);
	stop = 1;
}

int main(int argc, char *argv[])
{
	int sockfd, newsockfd, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;

	signal(SIGINT, cfinish);
	signal(SIGTERM, cfinish);

	if (argc < 2) {
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("ERROR opening socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	int on = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	if (bind(sockfd, (struct sockaddr *) &serv_addr,
				sizeof(serv_addr)) < 0) {
		error("ERROR on binding");
	}
	listen(sockfd,5);
	clilen = sizeof(cli_addr);

	while (!stop) {
		newsockfd = accept(sockfd,
				(struct sockaddr *) &cli_addr,
				&clilen);
		if (newsockfd < 0)
			error("ERROR on accept");
		else
			printf("connection established: %d\n", newsockfd);
		bzero(buffer, 256);
		n = read(newsockfd, buffer, 255);
		if (n < 0) error("ERROR reading from socket");
		printf("recv %d bytes: %s\n", n, buffer);
#if 0
		n = write(newsockfd,"I got your message",18);
		if (n < 0) error("ERROR writing to socket");
#else
		/* for client side timeout test */
		sleep(10);
#endif
		close(newsockfd);
	}
	close(sockfd);
	printf("%s exited.\n", argv[0]);
	return 0;
}
