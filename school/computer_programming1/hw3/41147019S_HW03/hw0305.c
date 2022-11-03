#include <stdio.h>
#include <stdint.h>
#include "logic.h"
#include "smallten.h"

int main(){
    bool x0 = false;
    bool x1 = false;
    bool x2 = false;
    bool x3 = false;
    bool y0 = false;
    bool y1 = false;
    bool y2 = false;
    bool y3 = false;
    
    communicate();

    printf("Please enter the first number (A) in binary: ");
    scanf("%i%i%i%i", &x3, &x2, &x1, &x0);

    printf("Please enter the second number (B) in binary: ");
    scanf("%i%i%i%i", &y3, &y2, &y1, &y0);
    
    multiplier(x0, x1, x2, x3, y0, y1, y2, y3);
    print(x0, x1, x2, x3, y0, y1, y2, y3);
}
    