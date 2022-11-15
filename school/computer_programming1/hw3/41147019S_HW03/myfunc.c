#include <stdio.h>
#include <stdint.h>
#include "myfunc.h"

static int32_t two = 0; 
static int32_t one = 0;  
static int32_t zero = 0; 
static int32_t flag = 0;

int32_t setup( int32_t a, int32_t b, int32_t c){
    two = a;
    one = b;
    zero = c;    
    flag = 1;
    
    if(a == 0){
        return -1;
    }
    else{
        return 0;
    }
}

double value( double x ){
    if(flag == 0){
        printf("Error\n");
        return -1;
    }
    return two * x * x + one * x + zero;
}

double min( double m, double n ){
    double small = m;
    double big = n;

    if(flag == 0){
        printf("Error\n");
        return -1;
    }

    if(m > n){
        big = m;
        small = n;
    }
    
    if(small < (one/(-2*two)) && big > (one/(-2*two))){
        return value(one/(-2*two));
    }
    else{
        if(value(m) > value(n)){
            return value(n);
        }
        else{
            return value(m);
        }
    }
}

double max( double m, double n ){
    double small = m;
    double big = n;

    if(flag == 0){
        printf("Error\n");
        return -1;
    }

    if(m > n){
        big = m;
        small = n;
    }
    
    if(small < (one/(-2*two)) && big > (one/(-2*two))){
        return value(one/(-2*two));
    }
    else{
        if(value(m) > value(n)){
            return value(m);
        }
        else{
            return value(n);
        }
    }
}

double slope( double t ){
    if(flag == 0){
        printf("Error\n");
        return -1;
    }

    return 2 * two * t + one;
}
