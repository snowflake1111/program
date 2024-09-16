#include <stdio.h>
#include <stdint.h>
#include <math.h>

int64_t judge(int64_t n);

int main(){
    int64_t n = 0;
    
    while(scanf("%lld", &n) != EOF){
        int64_t num[10] = {0};
        int64_t change_n = 0;
        int64_t tempn = n;
        int64_t count = 1;
        int64_t state1 = 0;
        int64_t state2 = 0;
        
        state1 = judge(n);
        
        if(state1 == 0){
            printf("%lld is not prime.\n", n);
            continue;
        }
        
        while(tempn / 10 > 0){
            num[count - 1] = tempn % 10;
            count = count + 1;
            tempn = tempn / 10;
        }
        
        num[count-1] = tempn;
        
        for(int64_t i=0 ; i<count ; i++){
            change_n = change_n + (num[i] * pow(10, count-i-1));
        }
        
        if(n == change_n){
            printf("%lld is prime.\n", n);
            continue;
        }
        
        state2 = judge(change_n);
        
        if(state2 == 1){
            printf("%lld is emirp.\n", n);
        }
        else{
            printf("%lld is prime.\n", n);
        }
    }
    
    return 0;
}

int64_t judge(int64_t n){
    int64_t state = 1;
    
    if(n == 1 || (n % 2 == 0 && n != 2)){
        state = 0;
    }
    else{
        for(int64_t i=3 ; i<=sqrt(n) ; i=i+2){
            if(n % i == 0){
                state = 0;
                
                break;
            }
        }
    }
    
    return state;
}
