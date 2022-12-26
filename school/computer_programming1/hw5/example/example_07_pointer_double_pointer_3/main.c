#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    size_t  size_row = 0, size_column = 0;

    printf("Please enter two integers for row and column: ");
    scanf( "%lu %lu", &size_row, &size_column );

    int32_t **ptr = NULL;

    ptr = calloc( sizeof( int32_t * ), size_row );

    for( size_t i = 0 ; i < size_row ; i++ )
    {
        *( ptr + i ) = calloc( sizeof( int32_t ), size_column );

        for( size_t j = 0 ; j < size_column ; j++ )
        {
            *( *( ptr + i ) + j ) = ( i + 1 ) * ( j + 1 );
        }
    }

    for( size_t i = 0 ; i < size_row ; i++ )
    {
        for( size_t j = 0 ; j < size_column; j++ )
        {
            printf( "%4d ", *( *( ptr + i ) + j ) );
        }

        printf( "\n" );
    }

    return 0;
}

