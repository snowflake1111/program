#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t n = 0;
    int32_t num = 0;
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        int32_t count[10] = {0};
        
        scanf("%d", &num);
        
        for(int32_t i=1 ; i<=num ; i++){
            for(int32_t j=i ; j>0 ; j=j/10){
                if(j % 10 == 0){
                    count[0] = count[0] + 1;
                }
                else if(j % 10 == 1){
                    count[1] = count[1] + 1;
                }
                else if(j % 10 == 2){
                    count[2] = count[2] + 1;
                }
                else if(j % 10 == 3){
                    count[3] = count[3] + 1;
                }
                else if(j % 10 == 4){
                    count[4] = count[4] + 1;
                }
                else if(j % 10 == 5){
                    count[5] = count[5] + 1;
                }
                else if(j % 10 == 6){
                    count[6] = count[6] + 1;
                }
                else if(j % 10 == 7){
                    count[7] = count[7] + 1;
                }
                else if(j % 10 == 8){
                    count[8] = count[8] + 1;
                }
                else if(j % 10 == 9){
                    count[9] = count[9] + 1;
                }
            }
        }
 
        printf("%d %d %d %d %d %d %d %d %d %d\n", count[0], count[1], count[2], count[3], count[4], count[5], count[6], count[7], count[8], count[9]);
    }
    
    return 0;
}
