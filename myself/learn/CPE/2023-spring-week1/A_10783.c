#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    int32_t a[100] = {0};
    int32_t b[100] = {0};
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
    }
    
    for(int32_t i=0 ; i<n ; i++){
        int32_t ans = 0;
        
        for(int32_t j=a[i] ; j<=b[i] ; j++){
            if(j % 2 != 0){
                ans = ans + j;
            }
        }
        
        printf("Case %d: %d\n", i+1, ans);
    }
}

