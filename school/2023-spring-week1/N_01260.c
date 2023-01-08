#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        int32_t a[2000] = {0};
        int32_t count = 0;
        int32_t index = 0;
        
        scanf("%d", &index);
        
        for(int32_t j=0 ; j<index ; j++){
            scanf("%d", &a[j]);
        }
        
        for(int32_t j=1 ; j<index ; j++){
            for(int32_t k=0 ; k<j ; k++){
                if(a[k] <= a[j]){
                    count = count + 1;
                }
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}
