#include <stdio.h>
#include <stdint.h>

int32_t value(int32_t a, int32_t b, int32_t c, int32_t x){
    return a*x*x + b*x + c;
}

int main(){
    int32_t a = 0;
    int32_t b = 0;
    int32_t c = 0;
    int32_t d = 0;
    int32_t L = 0;
    
    while(1){
        int32_t count = 0;

        scanf("%d %d %d %d %d", &a, &b, &c, &d, &L);
        
        if(a == 0 && b == 0 && c == 0 && d == 0 && L == 0){
            return 0;
        }

        for(int32_t i=0 ; i<=L ; i++){
            int32_t n = value(a, b, c, i);

            if(n % d == 0){
                count++;
            }
        }
        
        printf("%d\n", count);
    }

    return 0;
}