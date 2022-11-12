#ifndef LOGIC_H
#define LOGIC_H
#include <stdbool.h>

bool norGate(bool, bool);
bool notGate(bool);
bool andGate(bool, bool);
bool orGate(bool, bool);
bool xorGate(bool, bool);
bool xnorGate(bool, bool);
bool nandGate(bool, bool);
bool halfAdder(bool, bool);
bool fullAdder(bool, bool, bool);
//void multiplier(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3);
//void print(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3);
#endif
