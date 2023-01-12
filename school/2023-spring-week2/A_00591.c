#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    int32_t index = 0;
    
    while(1){
        int32_t block[100] = {0};
        int32_t avg = 0;
        int32_t count = 0;
        
        scanf("%d", &n);
        
        if(n == 0){
            break;
        }
        
        for(int32_t i=0 ; i<n ; i++){
            scanf("%d", &block[i]);
            avg = avg + block[i];
        }
        
        avg = avg / n;
        
        for(int32_t i=0 ; i<n ; i++){
            if(block[i] > avg){
                count = count + (block[i] - avg);
            }
        }
        
        index = index + 1;
        
        printf("Set #%d\n", index);
        printf("The minimum number of moves is %d.\n\n", count);
    }
    
    return 0;
}
