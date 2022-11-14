#include <stdio.h>
#include <stdint.h>
#include "logic.h"
#include "smallten.h"

extern bool z0, z1, z2, z3, z4, z5, z6, z7;
extern bool cOut, tmpS, tmpC;

void multiplier(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3);
int32_t change(int32_t n0, int32_t n1, int32_t n2, int32_t n3);

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

    printf("A = %d%d%d%d (2) = %d (10)\n", x3, x2, x1, x0, change(x0, x1, x2, x3));
    printf("B = %d%d%d%d (2) = %d (10)\n", y3, y2, y1, y0, change(y0, y1, y2, y3));
    printf("A x B = %d * %d = %d%d%d%d%d%d%d%d (2) = %d (10)\n", change(x0, x1, x2, x3), change(y0, y1, y2, y3), z7, z6, z5, z4, z3, z2, z1, z0, change(x0, x1, x2, x3)*change(y0, y1, y2, y3));
}

void multiplier(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3){
    z0 = andGate(x0, y0);
    z1 = andGate(x1, y0);
    z2 = andGate(x2, y0);
    z3 = andGate(x3, y0);
    
    z1 = halfAdder(z1, andGate(x0, y1));
    z2 = fullAdder(z2, andGate(x1, y1), cOut);
    z3 = fullAdder(z3, andGate(x2, y1), cOut);
    z4 = halfAdder(andGate(x3, y1), cOut);
    z5 = cOut;

    z2 = halfAdder(z2, andGate(x0, y2));
    z3 = fullAdder(z3, andGate(x1, y2), cOut);
    z4 = fullAdder(z4, andGate(x2, y2), cOut);
    z5 = fullAdder(z5, andGate(x3, y2), cOut);
    z6 = cOut;

    z3 = halfAdder(z3, andGate(x0, y3));
    z4 = fullAdder(z4, andGate(x1, y3), cOut);
    z5 = fullAdder(z5, andGate(x2, y3), cOut);
    z6 = fullAdder(z6, andGate(x3, y3), cOut);
    z7 = cOut;

    return;
}

int32_t change(int32_t n0, int32_t n1, int32_t n2, int32_t n3){
    return n3 * 8 + n2 * 4 + n1 * 2 + n0;
}
