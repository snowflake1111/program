#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t     array[10] = { 1, 2, 3, 4, 5,
                              6, 7, 8, 9, 10 };

    int32_t     *ptr = &( array[0] );

    for( size_t i = 0 ; i < 10 ; i++ )
    {
        printf( "%p: %d\n", ptr + i, *( ptr + i ) );
    }

    printf( "---\n" );

    int16_t     *ptr2 = &( array[0] );

    for( size_t i = 0 ; i < 20 ; i++ )
    {
        printf( "%p: %d\n", ptr2 + i, *( ptr2 + i ) );
    }

    printf( "---\n" );

    int8_t      *ptr3 = &( array[0] );

    for( size_t i = 0 ; i < 40 ; i++ )
    {
        printf( "%p: %d\n", ptr3 + i, *( ptr3 + i ) );
    }

    return 0;
}
