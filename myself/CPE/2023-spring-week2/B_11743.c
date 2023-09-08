#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    int32_t n = 0;
    int32_t a[4] = {0};
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        int32_t temp = 0;
        int32_t sum = 0;
        
        scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
        
        for(int32_t j=0 ; j<4 ; j++){
            for(int32_t k=0 ; k<4 ; k++){
                if(k % 2 == 0){
                    sum = sum + (a[j] / (int32_t) pow(10, k)) % 10;
                }
                else{
                    temp = (a[j] / (int32_t) pow(10, k)) % 10;
                    
                    if(2 * temp > 9){
                        sum = sum + ((2 * temp) % 10) + ((2 * temp) / 10);
                    }
                    else{
                        sum = sum + (2 * temp);
                    }
                }
            }
        }
        
        if(sum % 10 == 0){
            printf("Valid\n");
        }
        else{
            printf("Invalid\n");
        }
    }

    return 0;
}
