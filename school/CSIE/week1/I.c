#include <stdio.h>
#include <stdint.h>

void judge(int32_t m, int32_t n, int32_t x, int32_t y);

int main(){
    int32_t t = 0;
    int32_t m = 0;
    int32_t n = 0;
    int32_t x = 0;
    int32_t y = 0;
    
    while(1){
        scanf("%d", &t);
        
        if(t == 0){
            break;
        }
        
        scanf("%d %d", &m, &n);
        
        for(int32_t i=0 ; i<t ; i++){
            scanf("%d %d", &x, &y);
            
            judge(m, n, x, y);
        }
    }
    
    return 0;
}

void judge(int32_t m, int32_t n, int32_t x, int32_t y){
    if(x == m || y == n){
        printf("divisa\n");
    }
    else if(x > m && y > n){
        printf("NE\n");
    }
    else if(x < m && y > n){
        printf("NO\n");
    }
    else if(x < m && y < n){
        printf("SO\n");
    }
    else if(x > m && y < n){
        printf("SE\n");
    }
    
    return;
}
