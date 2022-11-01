#include <stdio.h>
#include <stdint.h>
#include "hanoi.h"

int main(){
    int32_t n = 0;
    printf("Please enter the disk number (2-20): ");
    scanf("%d", &n);

    if(n < 2 || n > 20){
        printf("Error");

        return 0;
    }
    
    step1(n, 1, 3, 2);

    return 0;
}
