#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "mystddev.h"
int main() {
    int32_t input;
    while (~(scanf("%d", &input))) {
        printf("the Standard Deviation is %.6g\n", get_stddev(input));
    }
    return 0;
}