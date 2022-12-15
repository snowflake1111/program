#include <stdio.h>
#include <stdint.h>
#include "rotate.h"

int main(){
    double x = 1;
    double y = 0;
    double theta = 0;
    
    printf("x: ");
    scanf("%lf", &x);
    
    printf("y: ");
    scanf("%lf", &y);
    
    printf("theta: ");
    scanf("%lf", &theta);
    
    rotate(&x, &y, theta);
    
    printf("x: %lf\n", x);
    printf("y: %lf\n", y);
    
    return 0;
}
