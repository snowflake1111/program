#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void    print_array( int32_t b[], size_t size );

int main()
{
    int32_t size = 0;
    int32_t *ptr = NULL;

    printf( "Please enter your array size: " );
    scanf( "%d", &size );

    ptr = malloc( sizeof( int ) * size );

    for( size_t i = 0 ; i < size ; i++ )
    {
        *( ptr + i ) = i;
    }

    print_array( ptr, size );

    printf( "sizeof(ptr): %lu\n", sizeof( ptr ) );

    return 0;
}

void    print_array( int32_t b[], size_t size )
{
    for( size_t i = 0 ; i < size ; i++ )
    {
        printf( "%4d ", b[i] );
        if( i% 8 == 7 )
        {
            printf( "\n" );
        }
    }
    printf( "\n" );
}
