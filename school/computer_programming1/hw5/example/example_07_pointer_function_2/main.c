#include <stdio.h>
#include <stdint.h>

void    print_array( int32_t b[], size_t size );
void    sort_array( int32_t b[], size_t size, int32_t ( * compare)( int32_t a, int32_t b ) );
int32_t ascending( int32_t, int32_t );
int32_t descending( int32_t, int32_t );

int main()
{
    int32_t     numbers[10] = {0};
    printf("Please enter 10 integers:\n");

    scanf( "%d %d %d %d %d %d %d %d %d %d",
            &(numbers[0]), &(numbers[1]), &(numbers[2]), &(numbers[3]), &(numbers[4]),
            &(numbers[5]), &(numbers[6]), &(numbers[7]), &(numbers[8]), &(numbers[9]) );

    printf( "Original Order:\n" );
    print_array( numbers, 10 );

    printf( "Ascending Order:\n" );
    sort_array( numbers, 10, ascending );
    print_array( numbers, 10 );

    printf( "Descending Order:\n" );
    sort_array( numbers, 10, descending );
    print_array( numbers, 10 );

    return 0;
}

void    print_array( int32_t b[], size_t size )
{
    for( size_t i = 0 ; i < size ; i++ )
    {
        printf( "%d ", b[i] );
    }
    printf( "\n" );
}

void    sort_array( int32_t b[], size_t size, int32_t ( * compare)( int32_t a, int32_t b ) )
{
    for( size_t i = 0 ; i < size ; i++ )
    {
        for( size_t j = i ; j < size ; j++ )
        {
            if( compare( b[i], b[j] ) )
            {
                int32_t tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
}

int32_t ascending( int32_t a, int32_t b )
{
    return b < a;
}

int32_t descending( int32_t a, int32_t b )
{
    return b > a;
}
