#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        int32_t max = 0;
        int32_t min = 0;
        int32_t num = 0;
        int32_t temp = 0;
        
        scanf("%d", &num);
        
        for(int32_t j=0 ; j<num ; j++){
            scanf("%d", &temp);
            
            if(j == 0){
                max = temp;
                min = temp;
            }
            
            if(temp > max){
                max = temp;
            }
            else if(temp < min){
                min = temp;
            }
        }
        
        printf("%d\n", 2 * (max - min));
    }
    
    return 0;
}
