#include "smallten.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
extern bool cOut;
void communicate() {
    printf("NOT GATE\n");
    for (int i = 0; i <= 1; ++i) {
        printf("%d:%d\n", i, notGate(i));
    }
    printf("AND GATE:\n");
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            printf("%d %d:%d\n", i, j, andGate(i, j));
        }
    }
    printf("OR GATE:\n");
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            printf("%d %d:%d\n", i, j, orGate(i, j));
        }
    }
    printf("XOR GATE:\n");
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            printf("%d %d:%d\n", i, j, xorGate(i, j));
        }
    }
    printf("XNOR GATE:\n");
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            printf("%d %d:%d\n", i, j, xnorGate(i, j));
        }
    }
    printf("NAND GATE:\n");
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            printf("%d %d:%d\n", i, j, nandGate(i, j));
        }
    }
    printf("HALFADDER:\n");
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            int c, s;
            s = halfAdder(i, j);
            c = cOut;
            printf("%d %d:C:%d S:%d\n", i, j, c, s);
        }
    }
    printf("FULLADDER:\n");
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
                int c, s;
                s = fullAdder(i, j, k);
                c = cOut;
                printf("%d %d %d:C:%d S:%d\n", i, j, k, c, s);
            }
        }
    }
}