#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "hanoi.h"

void step1(int32_t n, int32_t from, int32_t mid, int32_t to){
    if(n == 1){
        printf("move disk %d to %d\n", n, to);
    }
    else {
        step1(n-1, from, to, mid);
        printf("move disk %d to %d\n", n, to);
        step1(n-1, mid, from, to);
    }

    return;
}

void step2(int32_t n, int32_t from, int32_t mid, int32_t to){
    for(int32_t i=0 ; i<(pow(2, n) - 1) ; i++){
        if((i+1) % 2 == 0){

        }
    }

    return;
}