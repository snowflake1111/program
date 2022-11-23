#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "myfunc.h"

int main(){
    int32_t coefficients[100] = {0};
    int32_t powers[100] = {0};
    int32_t n = 0;
    double a = 0;
    int32_t size = 0;
    
    printf("n: ");
    scanf("%d", &n);
    printf("a: ");
    scanf("%lf", &a);
    printf("size: ");
    scanf("%d", &size);

    for(int32_t i=0 ; i<size ; i++){
        printf("coef %d: ", i+1);
        scanf("%d", &coefficients[i]);
    }
    for(int32_t i=0 ; i<size ; i++){
        printf("pow %d: ", i+1);
        scanf("%d", &powers[i]);
    }
    
    printf("%lf\n", cal_n_derivatives(n, a, size, coefficients, powers));
}
