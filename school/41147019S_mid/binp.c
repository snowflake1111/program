#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "binp.h"

int32_t isBinaryPalindrome(int32_t x){
    int64_t temp1 = 0;
    int64_t temp2 = 0;
    
    if(x > 0){
        temp1 = 0;
        temp2 = x % 2;

        printf("%lld\n", temp1);
        printf("%lld\n", temp2);

        if(temp1 != temp2){
            return 0;
        }

        for(int32_t i=0; i<15 ; i++){
            temp1 = (x / (int64_t) pow(2, i+1)) % 2;
            temp2 = (x / (int64_t) pow(2, 30 - i)) % 2;
        
            printf("%lld\n", temp1);
            printf("%lld\n", temp2);

            if(temp1 != temp2){
                return 0;
            }
        }
    }
    else{
        temp1 = 1;
        temp2 = (x + 2147483648) % 2;

        printf("%lld\n", temp1);
        printf("%lld\n", temp2);

        if(temp1 != temp2){
            return 0;
        }

        for(int32_t i=0; i<15 ; i++){
            temp1 = ((x + 2147483648)/ (int64_t) pow(2, i+1)) % 2;
            temp2 = ((x + 2147483648)/ (int64_t) pow(2, 30 - i)) % 2;
          
            printf("%lld\n", temp1);
            printf("%lld\n", temp2);
  
            if(temp1 != temp2){
                return 0;
            }
        }
    }

    return 1;
}
