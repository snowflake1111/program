#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t     a = 7;

    printf( "a's value is %d\n", a );
    printf( "a's address is %p\n", &a );
    printf( "\n" );

    int32_t     *a_ptr = &a;
    *a_ptr = 14;

    printf( "a's value is %d\n", a );
    printf( "a's address is %p\n", &a );

    return 0;
}
