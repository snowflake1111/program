#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t t = 0;
    int32_t n = 0;
    
    scanf("%d", &t);
    
    for(int32_t i=0 ; i<t ; i++){
        int32_t a[100] = {0};
        int32_t count = 0;
        
        scanf("%d", &n);
        
        for(int32_t j=0 ; j<n ; j++){
            scanf("%d", &a[j]);
        }
        
        for(int32_t j=0 ; j<n ; j++){
            for(int32_t k=j ; k<n ; k++){
                if(a[k] < a[j]){
                    int32_t temp = 0;
                    
                    count = count + 1;
                    temp = a[j];
                    a[j] = a[k];
                    a[k] = temp;
                }
            }
        }
        
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    
    return 0;
}
