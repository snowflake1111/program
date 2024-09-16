#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    int32_t e = 0;
    int32_t f = 0;
    int32_t c = 0;
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        int32_t left = 0;
        int32_t count = 0;
        
        scanf("%d %d %d", &e, &f, &c);
        
        left = e + f;
        
        while(left >= c){
            count = count + 1;
            left = left - c + 1;
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}
