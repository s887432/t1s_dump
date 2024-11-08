// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
	
#define DEBUG_TIME

#ifdef DEBUG_TIME
#include <sys/time.h>
#include <unistd.h>
#endif

#define MAX_BUF_SIZE	128
unsigned char recvBuf[MAX_BUF_SIZE];

int main(int argc, char **argv) 
{
	int sockfd;
	struct sockaddr_in servaddr, cliaddr;

	int retval;
	int len = sizeof(struct sockaddr_in);
	
	if( argc != 2 )
	{
		printf("Usage: udp_server PORT_NUMBER\r\n");
		return -1;
	}
		
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
		
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
		
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(atoi(argv[1]));
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	while(1)
	{
		retval = recvfrom(sockfd, recvBuf, MAX_BUF_SIZE, MSG_WAITALL, (struct sockaddr *) &servaddr, &len);
		if( retval > 0 )
		{
			printf("[%d] ", retval);
			for(int i=0; i<retval; i++)
			{
				printf("%02X, ", recvBuf[i]);
			}
			printf("\n\r");
		}
	}	
	
	close(sockfd);
	return 0;
}
