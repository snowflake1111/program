#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    int32_t index = 0;
    
    while(1){
        int32_t count = 0;
        int32_t line = 1;
        
        scanf("%d", &n);
        
        if(n < 0){
            break;
        }
        
        while(n > line){
            line = line * 2;
            count = count + 1;
        }
        
        printf("Case %d: %d\n", index+1, count);
        
        index = index + 1;
    }
    
    return 0;
}
