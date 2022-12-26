#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "mymemcmp.h"

int main(){
    char s1[] = "Time flies.";
    char t1[] = "Time is money.";

    char s2[] = "Time is money.";
    char t2[] = "Time is money.";

    char s3[] = "Time flies.";
    char t3[] = "";
    
    char s4[] = "";
    char t4[] = "";

    char s5[] = " ";
    char t5[] = "  ";

    printf("%d\n", mymemcmp(s1, t1, 4));
    printf("%d\n", mymemcmp(s1, t1, 10));
    printf("%d\n", mymemcmp(t1, s1, 10));

    printf("%d\n", mymemcmp(s2, t2, 4));
    printf("%d\n", mymemcmp(s2, t2, 10));
    printf("%d\n", mymemcmp(t2, s2, 10));

    printf("%d\n", mymemcmp(s3, t3, 4));
    printf("%d\n", mymemcmp(s3, t3, 10));
    printf("%d\n", mymemcmp(t3, s3, 10));

    printf("%d\n", mymemcmp(s4, t4, 4));
    printf("%d\n", mymemcmp(s4, t4, 10));
    printf("%d\n", mymemcmp(t4, s4, 10));

    printf("%d\n", mymemcmp(s5, t5, 4));
    printf("%d\n", mymemcmp(s5, t5, 10));
    printf("%d\n", mymemcmp(t5, s5, 10));
    
    return 0;
}