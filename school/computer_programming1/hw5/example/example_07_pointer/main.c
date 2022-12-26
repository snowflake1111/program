#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t     a = 7;

    printf( "a's value is %d\n", a );
    printf( "a's address is %p\n", &a );
    printf( "\n" );

    int32_t     *a_ptr = &a;

    printf( "a_ptr's value is %p\n", a_ptr );
    printf( "a_ptr's address is %p\n", &a_ptr );
    printf( "The value in %p is %d\n", a_ptr, *a_ptr );

    return 0;
}
