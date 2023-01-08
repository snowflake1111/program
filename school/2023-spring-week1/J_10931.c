#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t num[100] = {0};
    
    while(1){
        int32_t n = 0;
        int32_t count = 0;
        int32_t index = 0;
        
        scanf("%d", &n);
        
        if(n == 0){
            break;
        }
        
        for(int32_t i=0 ; i<100 ; i++){
            num[i] = 0;
        }
        
        printf("The parity of ");
        
        for(int32_t i=n ; i>0 ; i=i/2){
            num[index] = i % 2;
            
            if(i % 2 == 1){
                count = count + 1;
            }
            
            index = index + 1;
        }
        
        for(int32_t i=0 ; i<index ; i++){
            printf("%d", num[index-i-1]);
        }
        
        printf(" is %d (mod 2).\n", count);
    }
    
    return 0;
}
