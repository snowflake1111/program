#include <stdio.h>
#include <stdint.h>
#include "logic.h"
#include "smallten.h"

int main(){
    int32_t a = 0;
    int32_t b = 0;
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
    scanf("%d", &a);

    printf("Please enter the second number (B) in binary: ");
    scanf("%d", &b);
    
    x0 = a % 10;
    x1 = a / 10 % 10;
    x2 = a / 100 % 10;
    x3 = a / 1000;

    y0 = b % 10;
    y1 = b / 10 % 10;
    y2 = b / 100 % 10;
    y3 = b / 1000;
    
    if((x0 != 0 && x0 != 1) || (x1 != 0 && x1 != 1) || (x2 != 0 && x2 != 1) || (x3 != 0 && x3 != 1) ||
          (y0 != 0 && y0 != 1) || (y1 != 0 && y1 != 1) || (y2 != 0 && y2 != 1) || (y3 != 0 && y3 != 1)){
        printf("Error\n");

        return 0;
    }

    multiplier((bool) x0, (bool) x1, (bool) x2, (bool) x3, (bool) y0, (bool) y1, (bool) y2, (bool) y3);
    
    print(x0, x1, x2, x3, y0, y1, y2, y3);
}
    