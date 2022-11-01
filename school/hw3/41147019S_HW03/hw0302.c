#include <stdio.h>
#include <stdint.h>
#include "mystddev.h"

int main(){
    int32_t n = 0;
    
    scanf("%d", &n);
    
    while(n != -1){
        printf("%f\n", get_stddev(n));
        
        scanf("%d", &n);
    }
    
    return 0;
}
