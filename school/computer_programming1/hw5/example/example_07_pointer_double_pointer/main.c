#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void memory_alloc( int32_t **, size_t );

int main()
{
    size_t  size = 0;

    printf("Please enter an array size: ");
    scanf( "%lu", &size );

    int32_t *ptr = NULL;

    memory_alloc( &ptr, size );

    for( size_t i = 0 ; i < size ; i++ )
    {
        printf( "%4d ", *( ptr + i ) );

        if( i % 8 == 7 )
        {
            printf( "\n" );
        }
    }

    return 0;
}

void memory_alloc( int32_t **ptr, size_t s )
{
    *ptr = calloc( sizeof( int32_t ), s ); // Not 1, why?

    for( size_t i = 0 ; i < s ; i++ )
    {
        *( *ptr + i ) = i;
    }

    return;
}
