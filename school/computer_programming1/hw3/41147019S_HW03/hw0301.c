#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "myfunc.h"

int main() {
    int32_t a, b, c;
    printf("input your ax^2+bx+c\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("setup state:%d\n", setup(a, b, c));
    int32_t step = 0;
    double x, m, n;
    while (1) {
        printf(
            "input your step\n0:exit\n1:print value\n2.print minimum in "
            "range\n3.print maximum in range\n4.print slope\n");
        scanf("%d", &step);
        switch (step) {
            case 0:
                return 0;
            case 1:
                printf("input x\n");
                scanf("%lf", &x);
                printf("value of f(x) at x=%.6g is %.6g\n", x, value(x));
                break;
            case 2:
                printf("input m\n");
                scanf("%lf", &m);
                printf("input n\n");
                scanf("%lf", &n);
                printf("the minimum value in [%.6g, %.6g] is %.6g\n",
                       m < n ? m : n, m > n ? m : n, min(m, n));
                break;
            case 3:
                printf("input m\n");
                scanf("%lf", &m);
                printf("input n\n");
                scanf("%lf", &n);
                printf("the maximum value in [%.6g, %.6g] is %.6g\n",
                       m < n ? m : n, m > n ? m : n, max(m, n));
                break;
            case 4:
                printf("input x\n");
                scanf("%lf", &x);
                printf(
                    "the slope of the tangent line of f(x) at x=%.6g is %.6g\n",
                    x, slope(x));
                break;
            default:
                printf("no this step\n");
                break;
        }
    }
    return 0;
}
