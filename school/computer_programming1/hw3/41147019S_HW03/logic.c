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
    cOut = andGate(a, b);
    tmpS = xorGate(a, b);

    return tmpS;
}

bool fullAdder(bool a, bool b, bool c){
    cOut = orGate(andGate(a, b), andGate(xorGate(a, b), c)); 

    return xorGate(xorGate(a, b), c);
}
