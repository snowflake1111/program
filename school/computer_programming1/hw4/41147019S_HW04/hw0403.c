#include <stdio.h>
#include <stdint.h>
#define RED "\x1B[0;31m"
#define GRN "\x1B[0;32m"
#define YEL "\x1B[0;33m"
#define YEL_L "\x1B[1;33m"
#define BLU "\x1B[0;34m"
#define RESET "\x1B[0m"
#define RED_L "\x1B[1;31m"

int main(){
    int64_t state = 1;
    
    printf("Start:\n");
    printf(RED"* * *\n");
    printf(RED"* * *\n");
    printf(RED"* * *\n");

    while(1){
        printf("Input:\n");
        printf(RED"* * *\n");
        printf(RED"* * *\n");
        printf(RED"* * *\n");
    }

    printf(RED"*\n");
    printf(RED_L"*\n");
    printf(YEL"*\n");
    printf(YEL_L"*\n");
    printf(GRN"*\n");
    printf(BLU"*\n");
    printf(RESET"*\n");
    
}
/*
void print(){
    switch(color)
}
*/