#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define MY_PORT_NUMBER 49999

int main(int argc, char **argv) {
	int listenfd;
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{
		perror("socket");
		exit(1);
	}
	printf("Server socket created\n");


	struct sockaddr_in servAddr;

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(MY_PORT_NUMBER);
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if (bind(listenfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
	{
		perror("bind");
		exit(1);
	}
	printf("Socket bound to port\n");

	if ((listen(listenfd, 1)) < 0) 
	{
		perror("listen");
		exit(1);
	}
	printf("Listening for connections...\n\n");

	int connectfd, status;
	int length = sizeof(struct sockaddr_in);
	struct sockaddr_in clientAddr;

	while (1) {
		if ((connectfd = accept(listenfd, (struct sockaddr *)&clientAddr, &length)) < 0) {
			perror("accept");
			exit(1);
		}
		printf("Client connection found!\n");

		if (fork()) {			  
			close(connectfd);		 
			waitpid(-1, &status, 0); 
		}
		else {
			struct hostent *hostEntry;
			char *hostName;
			if ((hostEntry = gethostbyaddr(&(clientAddr.sin_addr), sizeof(struct in_addr), AF_INET)) == NULL) {
				herror("gethostbyaddr");
				exit(1);
			}
			hostName = hostEntry->h_name;
			printf("Connected to: %s\n", hostName);

			char buffer[100];
			time_t ltime;
			time(&ltime);
			strcpy(buffer, ctime(&ltime));
			int len = strlen(buffer);
			buffer[len] = '\0';

			if ((write(connectfd, buffer, 100)) <= 0) {
				perror("write");
				exit(1);
			}
			printf("Wrote time and date to client\n");
			printf("%s exiting...\n\n", hostName);
			close(connectfd);
			exit(0);		 
		}
	}
}
