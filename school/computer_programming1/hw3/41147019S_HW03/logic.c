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
    tmpC = andGate(a, b);
    tmpS = xorGate(a, b);

    return tmpS;
}

bool fullAdder(bool a, bool b, bool c){
    cOut = orGate(andGate(a, b), andGate(xorGate(a, b), c)); 

    return xorGate(xorGate(a, b), c);
}

void multiplier(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3){
    z0 = andGate(x0, y0);
    z1 = andGate(x1, y0);
    z2 = andGate(x2, y0);
    z3 = andGate(x3, y0);
    
    z1 = halfAdder(z1, andGate(x0, y1));
    z2 = fullAdder(z2, andGate(x1, y1), tmpC);
    z3 = fullAdder(z3, andGate(x2, y1), cOut);
    z4 = halfAdder(andGate(x3, y1), cOut);
    z5 = tmpC;

    z2 = halfAdder(z2, andGate(x0, y2));
    z3 = fullAdder(z3, andGate(x1, y2), tmpC);
    z4 = fullAdder(z4, andGate(x2, y2), cOut);
    z5 = fullAdder(z5, andGate(x3, y2), cOut);
    z6 = cOut;

    z3 = halfAdder(z3, andGate(x0, y3));
    z4 = fullAdder(z4, andGate(x1, y3), tmpC);
    z5 = fullAdder(z5, andGate(x2, y3), cOut);
    z6 = fullAdder(z6, andGate(x3, y3), cOut);
    z7 = cOut;

    return;
}

void print(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3){
    printf("A = %d%d%d%d (2) = %d (10)\n", x3, x2, x1, x0, x3 * 8 + x2 * 4 + x1 * 2 + x0);
    printf("B = %d%d%d%d (2) = %d (10)\n", y3, y2, y1, y0, y3 * 8 + y2 * 4 + y1 * 2 + y0);
    printf("A x B = %d * %d = %d%d%d%d%d%d%d%d (2) = %d (10)\n", x3 * 8 + x2 * 4 + x1 * 2 + x0, y3 * 8 + y2 * 4 + y1 * 2 + y0, z7, z6, z5, z4, z3, z2, z1, z0, (x3 * 8 + x2 * 4 + x1 * 2 + x0) * (y3 * 8 + y2 * 4 + y1 * 2 + y0));
    
    return;
}
