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
    int32_t a = 0;
    int32_t b = 0;

    communicate();

    printf("Please enter the first number (A) in binary: ");
    scanf("%d%d%d%d", &x3, &x2, &x1 &x0);

    printf("Please enter the second number (B) in binary: ");
    scanf("%d%d%d%d", &y3, &y2, &y1 &y0);

    a = x3 * 8 + x2 * 4 + x1 * 2 + x0;
    b = y3 * 8 + y2 * 4 + y1 * 2 + y0;
    
    multiplier(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3);

    printf("A = %d%d%d%d (2) = %d (10)\n", x3, x2, x1, x0, a);
    printf("B = %d%d%d%d (2) = %d (10)\n", y3, y2, y1, y0, b);
    printf("A x B = %d * %d = %d%d%d%d%d%d%d%d (2) = 154 (10)\n", z7, z6, z5, z4, z3, z2, z1, z0);
}
    