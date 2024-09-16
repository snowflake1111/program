#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){
    int32_t n = 0;
    char test[100] = {0};
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        int32_t count = 0;
        int32_t grade = 0;
        
        scanf("%s", test);
        
        for(int32_t j=0 ; j<strlen(test) ; j++){
            if(test[j] == 'O'){
                count = count + 1;
                grade = grade + count;
            }
            else{
                count = 0;
            }
        }
        
        printf("%d\n", grade);
    }
    
    return 0;
}
