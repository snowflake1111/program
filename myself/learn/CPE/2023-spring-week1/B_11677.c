#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t h1 = 0;
    int32_t m1 = 0;
    int32_t h2 = 0;
    int32_t m2 = 0;
    int32_t time = 0;
    
    while(1){
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        
        if(h1 == 0 && h2 == 0 && m1 == 0 && m2 == 0){
            break;
        }
        
        if(h1 < h2){
            time = (h2 - h1) * 60 + (m2 - m1);
        }
        else{
            time = (24 - (h1 - h2)) * 60 + (m2 - m1);
        }
        
        printf("%d\n", time);
    }
    
    return 0;
}
