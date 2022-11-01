#include <stdio.h>
#include <stdint.h>
#include "hanoi.h"

int main(){
    int32_t n = 0;
    printf("Please enter the disk number (2-20): ");
    scanf("%d", &n);
    step(n, 1, 2, 3);

    return 0;
}
