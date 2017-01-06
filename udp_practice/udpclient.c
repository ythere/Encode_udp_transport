#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/epoll.h>
#include <assert.h>

struct info{
	char name[10];
	char buf[100];
};

void *getmessage( void *p )
{
	int *sockfd = int *p;
	struct info from;
	while( recvfrom( *sockfd, &from, sizeof( from ), 0 ) > 0 ){
		printf( " %s say: %s\n", from.name, from.buf );
		memset( from.name, 0, sizeof( from.name ) );
		memset( from.buf, 0, sizeof( from.buf ) );
	}
}

int main( int argc, char *argc[] )
{
	if ( argc != 3 )
	{
		perror( "please check your input items\n" );
		return 1;
	}
	
	struct sockaddr_in client;
	struct sockaddr_in server;
	
	char *ip = argv[1];
	bzero( &client, sizeof( client ) );
	client.sin_family = AF_INET;
	inet_pton( AF_INET, ip, &client.sin_addr );
	client.sin_port = atoi( argv[2] );
	socklen_t clientlen = sizeof( client );
	
	int clientfd = socket( AF_INET, SOCK_DGRAM, 0 );
	assert( clientfd != -1 );
	
	int res = connect( clientfd, (struct sockaddr* )&client, &clientlen );
	assert( res != -1 );
	
	printf( "please input your name:" );
	scanf( "%s", in.name );
	getchar();
	
	pthread_t pid;
	pthread_create( pid , 0, getmessage, ( void * )&res );
	while( 1 )
	{
		gets( in.buf );
		if( !strcmp( in.buf, "bye") ){
			strcpy( in.buf, "exit" );
			send( res, &in, sizeof( in ), 0 );
			exit( 0 );
		}
		if ( send( res, &in, sizeof( in ), 0 ) == -1 )
			perror( "send" );
		memset( in.buf, 0, strlen( in.buf ) );
	}
}
