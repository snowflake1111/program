#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "myfunc.h"

double cal_n_derivatives( int32_t n, double a, int32_t size, int32_t coefficients[], int32_t powers[] ){
    double ans = 0;

    for(int32_t i=0 ; i<size ; i++){
        if(powers[i] - n >= 0 && coefficients[i] != 0){
            int64_t coef = coefficients[i];
            
            for(int32_t j=0 ; j<n ; j++){
                coef = coef * (powers[i] - j);
            }

            ans = ans + coef * pow(a, powers[i] - n);
        }
    }
    
    return ans;
}