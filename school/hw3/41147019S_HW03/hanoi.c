#include <stdio.h>
#include <stdint.h>
#include "hanoi.h"

void step(int32_t n, int32_t a, int32_t b, int32_t c){
    if(n == 1) {
        printf("Move sheet from %d to %d\n", a, c);
    }
    else {
        step(n-1, 1, 2, 3);
        step(1, 1, 3, 2);
        step(n-1, 3, 1, 2);
    }

    return;
}