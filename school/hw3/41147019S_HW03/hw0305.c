#include <stdio.h>
#include <stdint.h>
#include "logic.h"
#include "smallten.h"

int main(){
    int32_t x0 = 0;
    int32_t x1 = 0;
    int32_t x2 = 0;
    int32_t x3 = 0;
    int32_t y0 = 0;
    int32_t y1 = 0;
    int32_t y2 = 0;
    int32_t y3 = 0;
    
    communicate();

    printf("Please enter the first number (A) in binary: ");
    scanf("%d%d%d%d", &x3, &x2, &x1 &x0);

    printf("Please enter the second number (B) in binary: ");
    scanf("%d%d%d%d", &y3, &y2, &y1 &y0);
    
    multiplier(x0, x1, x2, x3, y0, y1, y2, y3);

}
    