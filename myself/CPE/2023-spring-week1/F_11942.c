#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    int32_t num[10] = {0};
    
    scanf("%d", &n);
    
    printf("Lumberjacks:\n");
    
    for(int32_t i=0 ; i<n ; i++){
        int32_t state = 1;
        int32_t judge = 0;
        
        scanf("%d %d %d %d %d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &num[9]);
        
        for(int32_t i=0 ; i<9 ; i++){
            if(num[i+1] > num[i]){
                judge = 1;
                break;
            }
            else if(num[i+1] < num[i]){
                judge = -1;
                break;
            }
        }
        
        
        if(judge == 1){
            for(int32_t j=0 ; j<8 ; j++){
                if(num[j+2] < num[j+1]){
                    state = 0;
                    break;
                }
            }
        }
        else if(judge == -1){
            for(int32_t j=0 ; j<8 ; j++){
                if(num[j+2] > num[j+1]){
                    state = 0;
                    break;
                }
            }
        }
        
        if(state == 1){
            printf("Ordered\n");
        }
        else{
            printf("Unordered\n");
        }
    }
    
    return 0;
}
