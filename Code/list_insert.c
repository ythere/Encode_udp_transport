#include <sys/types.h>
#include <stdio.h>

typedef struct data{
    int number;
    char contain[1024];
    struct data *next;
} Data;

Data *create();
void showList( Data *head );

int main( int argc, char *argv[] )
{
    Data *head;
    head = create();
    showList(head);
    memset( head, 0, sizeof( *head ) );
	showList( head );
	printf("end...\n");
    return 0;

}

Data *create()
{
    Data *head = NULL;
    Data *pEnd = head;
    Data *pS;
    int counter = 0;
    printf( "Please input your data...\n" );
    for ( counter = 0; counter < 15; counter++ )
    {
        pS = malloc( sizeof( Data ) );
        pS->number = counter;
        pS->next = NULL;
        char z[15];
        fgets( z , sizeof( z ), stdin );
        strcpy( pS->contain, z );
        if ( head == NULL )
        {
            head = pS;
        }
        else {
            pEnd->next = pS;
        }
        pEnd = pS;
    }
    return head;
}

void showList( Data *head )
{
    Data *pRead = head;
    printf( "the data of the link list are:\n" );
    while( pRead != NULL )
    {
        printf( "%d\t%s\n", pRead->number, pRead->contain );
        pRead = pRead->next;
    }
    printf( "end...\n" );
}
