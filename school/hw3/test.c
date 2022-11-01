#include <stdio.h>
#include <stdint.h>

void step(int32_t n, int32_t disk, int32_t rod){
    if(n == 1){
        printf("move disk %d to rod %d\n", disk, rod);
    }
    else if(n == 2){
        
    }
    else{
        step(n-1, 3);
        step(1, n, 2);
        step()
    }
}
