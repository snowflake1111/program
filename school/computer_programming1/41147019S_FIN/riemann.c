#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "riemann.h"

double riemann_sum( int32_t coefficients[], int32_t powers[], int32_t size, double a, double b, int32_t n ){
    double ans = 0;
    double x = 0;
    double value = 0;

    for(int32_t i=0 ; i<n ; i++){
        x = (double) a + (b-a)*i / n;
        
        for(int32_t j=0 ; j<size ; j++){
            value = value + coefficients[j] * pow(x, powers[j]);
        }

        ans = ans + value * (b-a) / n;

        value = 0;
    }

    return ans;
}