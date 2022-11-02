#include <stdio.h>
#include <stdint.h>
#include "resistance.h"

double calculate(int32_t r, int32_t n){
    if(n == 1){
        return 2 * r; 
    }
    else{
        return r + (double) r / (1 + (r / calculate(r, n-1))); 
    }
}