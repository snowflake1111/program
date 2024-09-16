#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t h = 0;
    int32_t m = 0;
    
    while(1){
        double angle = 0;
        
        scanf("%d:%d", &h, &m);
        
        if(h == 0 && m == 0){
            break;
        }
        
        angle = (h * 30 + ((double) (30 * m) / 60.0)) - (m * 6);
        
        if(angle < 0){
            angle = angle * -1;
        }
        
        if(angle > 180){
            angle = 360 - angle;
        }
        
        printf("%.3f\n", angle);
    }
    
    return 0;
}
