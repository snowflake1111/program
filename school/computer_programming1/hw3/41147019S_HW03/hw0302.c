#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "mystddev.h"

int main() {
    int32_t num = 0;
    scanf("%d", &num);
    while(num != -1){
        printf("%lf\n", get_stddev(num));
        scanf("%d", &num);
    }
    
    return 0;
}
