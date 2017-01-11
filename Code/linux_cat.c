#include <stdio.h>

void cat_one_file( FILE *fp )
{
    int ch;
    while( ch = getc( fp ) != NULL )
        putchar( ch );
}

int main( int argc, char *argv[] )
{
    if ( argc == 1 ){
        cat_one_file( stdin );
    } else {
        int i;
        FILE *fp;
        for( i = 0; i < argc; i++ ){
            fp = fopen( argv[i], "rb" );
            if( fp == NULL ){
                fprintf( stderr, "%s: %s can not open.\n", argv[i], argv[i] );
            }
            cat_one_file( fp );
            fclose( fp );
        }
    }
    return 0;
}
