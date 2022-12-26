#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t     array[10] = {0};

    printf( "array is %p\n", array );
    printf( "&array is %p\n", &array );
    printf( "&(array[0]) is %p\n", &(array[0]) );
    printf( "&(array[1]) is %p\n", &(array[1]) );
    printf( "&(array[2]) is %p\n", &(array[2]) );

    return 0;
}
