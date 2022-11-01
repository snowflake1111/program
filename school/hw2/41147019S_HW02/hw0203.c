#include <stdio.h>
#include <stdint.h>

int main(){
    uint32_t number = 0;
    int32_t num[100] = {0};
    int32_t temp = 0;
    int32_t count = 0;
    int32_t final = 0;

    printf("Please enter a number: ");
    scanf("%u", &number);

    temp = number;

    while(number / 10 != 0){
        count = 0;
        final = 0;
        
        for(int32_t i=0 ; temp!=0 ; i++){
            num[i] = temp % 10;
            count = count + 1; 
            temp = temp / 10;
            final = final + num[i];
        }
        for(int32_t j=count-1 ; j!=0 ; j--){
            printf("%d + ", num[j]);
        }

        printf("%d = %d\n", num[0], final);

        number = final;
        temp = final;
    }  

    if(number / 10 == 0){
        final = number;
    }

    printf("Final: %d\n", final);

    return 0;
}