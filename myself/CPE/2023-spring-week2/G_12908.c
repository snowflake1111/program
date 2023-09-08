#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    
    while(1){
        int32_t count = 0;
        int32_t sum = 0;
        
        scanf("%d", &n);
        
        if(n == 0){
            break;
        }
        
        while(1){
            if((count * (1 + count)) / 2 > n){
                sum = ((count * (1 + count)) / 2) - n;
                
                break;
            }
            
            count = count + 1;
        }
        
        printf("%d %d\n", sum, count);
    }
    
    return 0;
}
