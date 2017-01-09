#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <assert.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERV_PORT 8888

void do_echo( FILE *fp,int sockfd,  struct sockaddr *servaddr, socklen_t servlen )
{
	int n;
	char sendline[MAXLINE], recvline[MAXLINE + 1];
	
	if( connect( sockfd, ( struct sockaddr* )&servaddr, servlen ) == -1 )
	{
		perror( "connect error\n" );
		exit( 1 );
	}
	while( fgets( sendline, MAXLINE, fp ) != NULL )
	{
		write( socket, sendline, strlen( sendline ) );
		n = read( sockfd, recvline, MAXLINE );
		if ( n == -1 )
		{
			perror( "read error\n" );
			exit( 1 );
		}
		
		recvline[n] = 0;
		fputs( recvline, stdout );
	}
}

int main( int argc, char *argv[] )
{
	int sockfd;
	struct sockaddr_in *servaddr;
	if ( argc != 2 )
	{
		printf( "usage: udpclient<IPaddress>\n" );
		exit( 1 );
	}
	bzero( &servaddr, sizeof( servaddr ) );
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons( SERV_PORT );
	int res = inet_hton( AF_INET, argv[1], $servaddr.sin_addr );
	assert( res >= 0 );
	
	int sockfd = socket( AF_INET, SOCK_DGRAM, 0 );
	do_echo( stdin, sockfd, ( struct sockaddr* )&servaddr, sizeof( servaddr ) );
	return 0;
	
}
