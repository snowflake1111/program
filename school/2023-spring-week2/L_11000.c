#include <stdio.h>
#include <stdint.h>

int main(){
    int64_t n = 0;
    
    while(1){
        int64_t m = 0;
        int64_t g = 1;
        
        scanf("%lld", &n);
        
        if(n == -1){
            break;
        }
        
        for(int64_t i=0 ; i<n ; i++){
            int64_t tempm = m;
            
            m = m + g;
            g = tempm + 1;
        }
        
        printf("%lld %lld\n", m, m+g);
    }
    
    return 0;
}
