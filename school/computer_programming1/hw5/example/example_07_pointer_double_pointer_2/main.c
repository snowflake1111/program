#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void two_dimension_alloc( int32_t **, size_t, size_t );

int main()
{
    size_t  size_row = 0, size_column = 0;

    printf("Please enter two integers for row and column: ");
    scanf( "%lu %lu", &size_row, &size_column );

    int32_t *ptr = NULL;

    two_dimension_alloc( &ptr, size_row, size_column );

    for( size_t i = 0 ; i < size_row ; i++ )
    {
        for( size_t j = 0 ; j < size_column; j++ )
        {
            printf( "%4d ", *( ptr + i * size_column + j ) );
            // printf( "%4d ", ptr[i][j] );
        }

        printf( "\n" );
    }

    return 0;
}

void two_dimension_alloc( int32_t **ptr, size_t row, size_t column )
{
    *ptr = calloc( sizeof( int32_t ), row * column );

    for( size_t i = 1 ; i <= row ; i++ )
    {
        for( size_t j = 1 ; j <= column ; j++ )
        {
            *( *ptr + ( i - 1 ) * column + ( j - 1 ) ) = i * j;
        }
    }

    return;
}
