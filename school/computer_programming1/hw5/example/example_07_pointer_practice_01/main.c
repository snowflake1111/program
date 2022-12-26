#include <stdio.h>
#include <stdint.h>

int main()
{
    int8_t      a = 10;
    int16_t     b = 20;
    int32_t     c = 30;
    int64_t     d = 40;

    printf( "a's value is %d\n", a );
    printf( "a's address is %p\n", &a );
    printf( "b's value is %d\n", b );
    printf( "b's address is %p\n", &b );
    printf( "c's value is %d\n", c );
    printf( "c's address is %p\n", &c );
    printf( "d's value is %ld\n", d );
    printf( "d's address is %p\n", &d );
    printf( "\n" );

    void *ptr = NULL;

    ptr = &a;
    printf( "Value in %p is %d\n", ptr, *( (int8_t *)ptr ) );
    ptr = &b;
    printf( "Value in %p is %d\n", ptr, *( (int16_t *)ptr ) );
    ptr = &c;
    printf( "Value in %p is %d\n", ptr, *( (int32_t *)ptr ) );
    ptr = &d;
    printf( "Value in %p is %ld\n", ptr, *( (int64_t *)ptr ) );


    return 0;
}
