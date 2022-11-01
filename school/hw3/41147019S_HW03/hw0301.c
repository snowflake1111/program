#include <stdint.h>
#include <stdio.h>
#include "myfunc.h"

int main(){
    int32_t a = 0;
    int32_t b = 0;
    int32_t c = 0;
    scanf("%d %d %d", &a, &b, &c);
    
    setup(a, b, c);
    printf("%f\n", value(4));
    printf("%f\n", min(-5,5));
    printf("%f\n", max(5,-5));
    printf("%f\n", slope(4));
    
    return 0;
}
