#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int32_t Start(int32_t input);
int32_t S1(int32_t input);
int32_t S2(int32_t input);
int32_t S3(int32_t input);
int32_t S4(int32_t input);
int32_t S5(int32_t input);
int32_t S6(int32_t input);
int32_t (*func_ptr_arr[8]) (int32_t input) = {Start, S1, S2, S3, S4, S5, S6};

int main(){
    int32_t input = 0;
    int32_t state = 0;
    
    while(1){
        state = (*func_ptr_arr[state]) (input);

        printf("Please enter an integer: ");
        scanf("%d", &input);
    }
    
    return 0;
}

int32_t Start(int32_t input){
    if(input == 10 || input == 35){
        printf("S1\n");
        return 1;
    }
    else if(input == 11){
        printf("S3\n");
        return 3;
    }
    else if(input == 20 || input == 78){
        printf("S5\n");
        return 5;
    }
    else{
        printf("Start\n");
        return 0;
    }
}

int32_t S1(int32_t input){
    if(input == 19){
        printf("S2\n");
        return 2;
    }
    else if(input == 12 || input == 36){
        printf("S6\n");
        return 6;
    }
    else{
        printf("S1\n");
        return 1;
    }
}

int32_t S2(int32_t input){
    if(input == 43){
        printf("S2\n");
        return 2;
    }
    else if(input == 99){
        printf("Final\n");
        exit(0);
    }
    else{
        printf("Start\n");
        return 0;
    }
}

int32_t S3(int32_t input){
    printf("S4\n");
    return 4;
}

int32_t S4(int32_t input){
    printf("S6\n");
    return 6;
}

int32_t S5(int32_t input){
    if(input == 1){
        printf("S4\n");
        return 4;
    }
    else if(input == 2){
        printf("S6\n");
        return 6;
    }
    else{
        printf("Start\n");
        return 0;
    }
}

int32_t S6(int32_t input){
    if(input == 108){
        printf("Final\n");
        exit(0);
    }
    else{
        printf("S5\n");
        return 5;
    }
}