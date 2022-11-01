#include <stdio.h>
#include <stdint.h>
#include "hanoi.h"

void step(int32_t n, int32_t from, int32_t mid, int32_t to){
    if(n == 1){
        printf("move disk %d to %d\n", n, to);
    }
    else {
        step(n-1, from, to, mid);
        printf("move disk %d to %d\n", n, to);
        step(n-1, mid, from, to);
    }

    return;
}