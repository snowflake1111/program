#include <stdio.h>
#include "myfunction.h"
#include <stdint.h>

int main(){
    int32_t a = 1, b = 2, c = 0;
    c = add_function(a, b);
    printf("%d\n", c);

    return 0;
}