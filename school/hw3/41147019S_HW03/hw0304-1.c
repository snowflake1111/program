#include <stdio.h>
#include <stdint.h>
#include "hanoi.h"

int main(){
    int32_t n = 0;
    printf("Please enter the disk number (2-20): ");
    scanf("%d", &n);
    step(n, 1, 3, 2);

    return 0;
}
