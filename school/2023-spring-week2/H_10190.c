#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    int32_t m = 0;
    
    while(scanf("%d %d", &m, &n) != EOF){
        int32_t index = 0;
        int32_t state = 1;
        int32_t a[5000] = {0};
        
        if(m == 0 || n == 0 || (m % n != 0) || n == 1){
            printf("Boring!\n");
            continue;
        }
        
        for(int32_t i=m ; i>1 ; i=i/n){
            if(i % n != 0){
                state = 0;
                
                break;
            }
            
            a[index] = i;
            index = index + 1;
        }
        
        if(state == 1){
            for(int32_t i=0 ; i<index ; i++){
                printf("%d ", a[i]);
            }
            
            printf("1\n");
        }
        else{
            printf("Boring!\n");
        }
    }
    
    return 0;
}
