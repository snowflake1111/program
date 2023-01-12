#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t zero(int32_t a[20], int32_t n);

int main(){
    int32_t t = 0;
    
    scanf("%d", &t);
    
    for(int32_t i=0 ; i<t ; i++){
        int32_t n = 0;
        int32_t state = 0;
        int32_t a[20] = {0};
        
        scanf("%d", &n);
        
        for(int32_t j=0 ; j<n ; j++){
            scanf("%d", &a[j]);
        }
        
        for(int32_t j=0 ; j<1000 ; j++){
            if(zero(a, n) == 1){
                state = 1;
                
                break;
            }
            
            a[n] = a[0];
            
            int32_t temp[20] = {0};
            
            for(int32_t k=0 ; k<n ; k++){
                temp[k] = abs(a[k] - a[k+1]);
            }
            for(int32_t k=0 ; k<n ; k++){
                a[k] = temp[k];
            }
        }
        
        if(state == 1){
            printf("ZERO\n");
        }
        else{
            printf("LOOP\n");
        }
    }
    
    return 0;
}

int32_t zero(int32_t a[20], int32_t n){
    for(int32_t i=0 ; i<n ; i++){
        if(a[i] != 0){
            return 0;
        }
    }
    
    return 1;
}
