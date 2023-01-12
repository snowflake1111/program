#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    int32_t n = 0;
    char num[10] = {0};
//    int32_t a[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        int32_t sum = 0;
        
        scanf("%s", num);
        
        for(int32_t j=0 ; j<3 ; j++){
            int32_t temp = num[j] - 'A';
            sum = sum + (temp * pow(26, 2-j));
        }
        
        sum = sum - (1000 * (num[4] - '1' + 1) + 100 * (num[5] - '1' + 1) + 10 * (num[6] - '1' + 1) + (num[7] - '1' + 1));
        
        if(sum > 100 || sum < -100){
            printf("not nice\n");
        }
        else{
            printf("nice\n");
        }
    }
    
    return 0;
}
