#include <stdio.h>
#include <stdint.h>
#include "myfunc.h"

static int32_t two = 0;   //a
static int32_t one = 0;   //b
static int32_t zero = 0;  //c

// Setup a quadratic function.
// This function must be called before all other functions.
// If a == 0, return -1; otherwise, return 0.
int32_t setup( int32_t a, int32_t b, int32_t c){
    two = a;
    one = b;
    zero = c;
    
    if(a == 0){
        return -1;
    }
    else{
        return 0;
    }
}

// Return f(x)
double value( double x ){
    return two * x * x + one * x + zero;
}

// Return the minimum value of f(x) between m and n
// m may be greater than/equal to/smaller than n
double min( double m, double n ){
    double small = m;
    double big = n;
    
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

// Return the maximum value of f(x) between m and n
// m may be greater than/equal to/smaller than n
double max( double m, double n ){
    double small = m;
    double big = n;
    
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

// Return slope of the tangent line of f(x) at x=t
double slope( double t ){
    return 2 * two * t + one;
}
