#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXLINE 80
#define SERV_PORT 8888

void do_echo( int sockfd, struct sockaddr *pclinaddr, socklen_t pclinlen)
{
	char msg[MAXLIE];
	int n;
	for ( ; ; )
	{
		len = pclinlen;
		n = recvfrom( sockfd, msg, MAXLINE, 0, pclinaddr, &len );
		sendto( sockfd, msg, n, 0, pclinaddr, len );
	}
}

int main( int argc, char *argv[] )
{
	int sockfd;
	struct sockaddr_in servaddr, clienaddr;
	sockfd = socket( AF_INET, SOCK_DGRAM, 0 );
	bzero( &servaddr, sizeof( servaddr ) );
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons( SERV_PORT );
	servaddr.sin_addr.s_addr = htonl( INADDR_ANY );
	
	int res = bind( sockfd, ( struct sockaddr* )&servaddr, sizeof( servaddr ) );
	assert( res != -1 );
	
	do_echo( sockfd, ( struct sockaddr* )&clienaddr, sizeof( clienaddr ) );
	return 0;
}