#include <stdio.h>
#include <stdint.h>

void sort(int32_t line[4]);

int main(){
    int32_t n = 0;
    int32_t line[4] = {0};
    
    scanf("%d", &n);
    
    for(int32_t i=0 ; i<n ; i++){
        scanf("%d %d %d %d", &line[0], &line[1], &line[2], &line[3]);

        sort(line);
    
        if(line[0] == line[3]){
            printf("square\n");
        }
        else if((line[0] == line[1]) && (line[2] == line[3])){
            printf("rectangle\n");
        }
        else if((line[0] + line[1] + line[2]) > line[3]){
            printf("quadrangle\n");
        }
        else{
            printf("banana\n");
        }
    }
    
    return 0;
}

void sort(int32_t line[4]){
    int32_t temp = 0;
    
    for(int32_t i=0 ; i<3 ; i++){
        for(int32_t j=i ; j<3 ; j++){
            if(line[j+1] < line[i]){
                temp = line[j+1];
                line[j+1] = line[i];
                line[i] = temp;
            }
        }
    }
    
    return;
}
