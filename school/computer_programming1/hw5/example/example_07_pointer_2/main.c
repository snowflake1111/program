#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t     a = 100;
    int32_t     b = -100;

    printf( "a's value is %d\n", a );
    printf( "a's address is %p\n", &a );
    printf( "\n" );

    int32_t     *ptr = &a;

    printf( "ptr's value is %p\n", ptr );
    printf( "ptr's address is %p\n", &ptr );
    printf( "The value in %p is %d\n", ptr, *ptr );
    printf( "\n" );

    ptr = &b;

    printf( "ptr's value is %p\n", ptr );
    printf( "ptr's address is %p\n", &ptr );
    printf( "The value in %p is %d\n", ptr, *ptr );

    return 0;
}
