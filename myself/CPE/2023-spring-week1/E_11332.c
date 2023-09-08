#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    
    while(1){
        scanf("%d", &n);
        
        if(n == 0){
            break;
        }
        
        while(n > 9){
            int32_t sum = 0;
            
            while(n > 0){
                sum = sum + (n % 10);
                n = n / 10;
            }
            
            n = sum;
        }
        
        printf("%d\n", n);
    }
    
    return 0;
}
