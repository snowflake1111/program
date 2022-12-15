#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "rotate.h"

void rotate( double *x, double *y, double theta ){
    double rad = 0;
    double pi = acos(-1);
    double tempx = 0;
    double tempy = 0;
    
    rad = theta * pi / 180;
    
    tempx = cos(rad) * (*x) - sin(rad) * (*y);
    tempy = sin(rad) * (*x) + cos(rad) * (*y);
    
    *x = tempx;
    *y = tempy;
    
    return;
}
