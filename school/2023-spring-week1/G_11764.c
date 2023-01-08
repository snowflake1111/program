#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    int32_t block[50] = {0};
    
    scanf("%d", &n);

    for(int32_t i=0 ; i<n ; i++){
        int32_t block_num = 0;
        int32_t low = 0;
        int32_t high = 0;
        
        scanf("%d", &block_num);
        
        for(int32_t j=0 ; j<50 ; j++){
            block[j] = 0;
        }
        
        for(int32_t j=0 ; j<block_num ; j++){
            scanf("%d", &block[j]);
        }
        
        for(int32_t j=0 ; j<block_num - 1 ; j++){
            if(block[j+1] > block[j]){
                high = high + 1;
            }
            else if(block[j+1] < block[j]){
                low = low + 1;
            }
        }
        
        printf("Case %d: %d %d\n", i+1, high, low);
    }
    
    return 0;
}
