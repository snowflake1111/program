#include <stdio.h>
#include <stdint.h>

void function01( int32_t );
void function02( int32_t );

int main()
{
    void    ( *func )( int32_t );
    int32_t n = 10;

    func = function01;
    func( n );
    func = function02;
    func( n );

    return 0;
}

void function01( int32_t number )
{
    printf( "This is function 01: %d!\n", number );
    return;
}

void function02( int32_t number )
{
    printf( "This is function 02: %d!\n", number );
    return;
}
