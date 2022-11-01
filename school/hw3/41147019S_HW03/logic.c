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
    z1 = halfAdder((andGate(x1, y0), andGate(x0, y1)));
    z2 = halfAdder(fullAdder(andGate(x2, y0), andGate(x1, y1), z1), andGate(x0, y2));
    z3 = halfAdder(fullAdder(fullAdder(andGate(x3, y0), andGate(x2, y1), fullAdder(andGate(x2, y0), andGate(x1, y1), z1), andGate(x0, y2)), andGate(x1, y2), z2), andGate(x0, y3));
    z4 = fullAdder(fullAdder(halfAdder(andGate(x3, y1), fullAdder(andGate(x3, y0), andGate(x2, y1), fullAdder(andGate(x2, y0), andGate(x1, y1), z1), andGate(x0, y2))), andGate(x2, y2), fullAdder(fullAdder(andGate(x3, y0), andGate(x2, y1), fullAdder(andGate(x2, y0), andGate(x1, y1), z1), andGate(x0, y2)), andGate(x1, y2), z2)), andGate(x1, y3), z3);
    z5 = fullAdder(fullAdder(halfAdder(andGate(x3, y1), halfAdder(andGate(x3, y1), fullAdder(andGate(x3, y0), andGate(x2, y1), fullAdder(andGate(x2, y0), andGate(x1, y1), z1)))), andGate(x3, y2), fullAdder(halfAdder(andGate(x3, y1), fullAdder(andGate(x3, y0), andGate(x2, y1), fullAdder(andGate(x2, y0), andGate(x1, y1), z1), andGate(x0, y2))), andGate(x2, y2), fullAdder(fullAdder(andGate(x3, y0), andGate(x2, y1), fullAdder(andGate(x2, y0), andGate(x1, y1), z1), andGate(x0, y2)), andGate(x1, y2), z2))), andGate(x2, y3), z4);
    z6 = fullAdder(fullAdder(halfAdder(andGate(x3, y1), halfAdder(andGate(x3, y1), fullAdder(andGate(x3, y0), andGate(x2, y1), fullAdder(andGate(x2, y0), andGate(x1, y1), z1)))), andGate(x3, y2), fullAdder(halfAdder(andGate(x3, y1), fullAdder(andGate(x3, y0), andGate(x2, y1), fullAdder(andGate(x2, y0), andGate(x1, y1), z1), andGate(x0, y2))), andGate(x2, y2), fullAdder(fullAdder(andGate(x3, y0), andGate(x2, y1), fullAdder(andGate(x2, y0), andGate(x1, y1), z1), andGate(x0, y2)), andGate(x1, y2), z2))), andGate(x3, z3), z5);
    z7 = z6;
}