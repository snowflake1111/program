#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "myfunc.h"

int main(){
    int32_t coefficients[] = {12, 34, 56};
    int32_t powers[] = {5, 2, 0};

    printf("%lf\n", cal_n_derivatives(3, 2, 3, coefficients, powers));
}
