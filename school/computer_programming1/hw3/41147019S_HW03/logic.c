#include <stdio.h>
#include "logic.h"

bool cOut, tmpS, tmpC;
bool z0, z1, z2, z3, z4, z5, z6, z7;

bool norGate(bool a, bool b) {
    return !(a || b);
}

bool notGate(bool a){
    return norGate(a, a);
}

bool andGate(bool a, bool b){
    return norGate(norGate(a, a), norGate(b, b));    
}

bool orGate(bool a, bool b){
    return norGate(norGate(a, b), norGate(a, b));
}

bool xorGate(bool a, bool b){
    return norGate(norGate(norGate(a, a), norGate(b,b)), norGate(a, b));
}

bool xnorGate(bool a, bool b){
    return norGate(norGate(norGate(a, b), a), norGate(norGate(a, b), b));
}

bool nandGate(bool a, bool b){
    return norGate(norGate(norGate(a, a), norGate(b, b)), norGate(norGate(a, a), norGate(b, b)));
}

bool halfAdder(bool a, bool b){
    return xorGate(a, b);
}

bool fullAdder(bool a, bool b, bool c){
    return xorGate(xorGate(a, b), c);
}

void multiplier(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3){
    z0 = andGate(x0, y0);
    
    z1 = halfAdder(andGate(x1, y0), andGate(x0, y1));
    tmpC = andGate(andGate(x1, y0), andGate(x0, y1));
    tmpS = z1;

    z2 = fullAdder()

    return;
}

void print(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3){
    printf("A = %d%d%d%d (2) = %d (10)\n", x3, x2, x1, x0, x3 * 8 + x2 * 4 + x1 * 2 + x0);
    printf("B = %d%d%d%d (2) = %d (10)\n", y3, y2, y1, y0, y3 * 8 + y2 * 4 + y1 * 2 + y0);
    printf("A x B = %d * %d = %d%d%d%d%d%d%d%d (2) = %d (10)\n", x3 * 8 + x2 * 4 + x1 * 2 + x0, y3 * 8 + y2 * 4 + y1 * 2 + y0, z7, z6, z5, z4, z3, z2, z1, z0, x3 * 8 + x2 * 4 + x1 * 2 + x0 + y3 * 8 + y2 * 4 + y1 * 2 + y0);
    
    return;
}