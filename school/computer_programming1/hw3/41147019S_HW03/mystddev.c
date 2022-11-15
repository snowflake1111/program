#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "mystddev.h"

double get_stddev( int32_t number ){
    static int64_t num[100] = {0};
    static double minus[100] = {0}; 
    static int64_t count = 0;
    static int64_t sum = 0;
    double average = 0;
    double minus_sum = 0;
    static int32_t remember = 0;

    if(number != 154 && number != -321 && number != 965){
        remember = 0;
    }
    if(number == 154){
        remember = number;
    }
    else if(remember == 154 && number == -321){
        remember = number;
    }
    else if(remember == -321 && number == 965){
        for(int64_t i=0 ; i<count ; i++){
            num[i] = 0;
            minus[i] = 0;
        }

        sum = 0;
        count = 0;
        remember = 0;
        
        return 0;
    }

    count = count + 1;
    num[count - 1] = number;
    
    sum = sum + number;
    average = (double) sum / count;

    for(int64_t i=0 ; i<count ; i++){
        minus[i] = pow(num[i] - average, 2);
        minus_sum = minus_sum + minus[i];
    }
    
    return sqrt(minus_sum / count); 
}