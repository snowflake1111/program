#include <stdio.h>
#include <stdint.h>

void print(int32_t n);

int main(){
    int32_t n = 0;
    int32_t width[2000] = {0};
    int32_t time[2000] = {0};
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        scanf("%d", &width[i]);
        scanf("%d", &time[i]);
    }
    
    for(int32_t i=0 ; i<n ; i++){
        for(int32_t j=0 ; j<time[i] ; j++){
            print(width[i]);
            
            if(!(i == n-1 && j == time[i] - 1)){
                printf("\n");
            }
        }
    }
    
    return 0;
}

void print(int32_t n){
    for(int32_t i=0 ; i<n ; i++){
        for(int32_t j=0 ; j<i+1 ; j++){
            printf("%d", i+1);
        }
        printf("\n");
    }
    for(int32_t i=n-1 ; i>0 ; i--){
        for(int32_t j=0 ; j<i ; j++){
            printf("%d", i);
        }
        printf("\n");
    }
    
    return;
}
