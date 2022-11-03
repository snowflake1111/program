#include <stdio.h>
#include <stdint.h>
#include "resistance.h"

int main(){
    int32_t r = 0;
    int32_t n = 0;

    printf("Please enter the resistance (1-100): ");    
    scanf("%d", &r);

    printf("Please enter n (1-100): ");
    scanf("%d", &n);

    if(r < 1 || r > 100 || n < 1 || n > 100){
        printf("Error");
        return 0;
    }

    printf("Ans: %f\n", calculate(r, n));
    
    return 0;
}