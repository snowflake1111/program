#include <stdio.h>
#include <stdint.h>
#include "riemann.h"

int main(){
    int32_t coefficients[] = {1, 2, 1};
    int32_t powers[] = {0, 1, 2};
    int32_t size = 3;
    int32_t a = 1;
    int32_t b = 3;
    int32_t n = 4;

    printf("%lf\n", riemann_sum( coefficients, powers, size, a, b, n ));

    return 0;
}