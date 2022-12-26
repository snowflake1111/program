#include <stdio.h>
#include <stdint.h>
#include "canvas.h"

void print(int32_t all_color[row_size][col_size], int32_t row_size, int32_t col_size);
void change(int32_t color, int32_t all_color[row_size][col_size], int32_t row_size, int32_t col_size, int32_t x, int32_t y);

int main(){
    int32_t color = 0;
    int32_t all_color[100][100];
    int32_t x = 0;
    int32_t y = 0;

    for(int32_t i=0 ; i<100 ; i++){
        for(int32_t j=0 ; j<100 ; j++){
            all_color[i][j] = 0;
        }   
    }

    print(all_color, row_size, col_size);

    while(1){
        printf("\n");
        printf("Please enter the point (x,y): ");
        scanf("%d,%d", &x, &y);

        printf("Please enter the color[0-4]: ");
        scanf("%d", &color);
        
        if((x == y) || (x + y == (row_size - 1))){
            printf("warning\n");
            continue;
        }
        else{
            change(color, all_color, row_size, col_size, x, y);
            print(all_color, row_size, col_size);    
        }
    }

    return 0;
}

void print(int32_t all_color[row_size][col_size], int32_t row_size, int32_t col_size){
    printf(" ");

    for(int32_t i=0 ; i<row_size ; i++){
        printf(" ");
        printf("%d", i % 10);
    }

    printf("\n");

    for(int32_t i=0 ; i<row_size ; i++){
        printf("%d", i % 10);

        for(int32_t j=0 ; j<col_size ; j++){
            if(i == j || i + j == (row_size - 1)){
                printf("\033[40m  \033[0m");
            }
            else{
                if(all_color[i][j] == 0){
                    printf("\033[47m  \033[0m");  
                }
                else if(all_color[i][j] == 1){
                    printf("\033[41m  \033[0m");  
                }
                else if(all_color[i][j] == 2){
                    printf("\033[43m  \033[0m");  
                }
                else if(all_color[i][j] == 3){
                    printf("\033[42m  \033[0m");  
                }
                else if(all_color[i][j] == 4){
                    printf("\033[44m  \033[0m");  
                }
            }
        }
        printf("\n");
    }

    return;
}

void change(int32_t color, int32_t all_color[row_size][col_size], int32_t row_size, int32_t col_size, int32_t x, int32_t y){
    if((x - y > 0) && (x + y < (row_size - 1))){
        for(int32_t i=0 ; i<row_size ; i++){
            for(int32_t j=0 ; j<col_size ; j++){
                if((i - j > 0) && (i + j < (row_size - 1))){
                    all_color[i][j] = color;
                }
            }
        }
    }

    else if((x - y < 0) && (x + y < (row_size -1))){
        for(int32_t i=0 ; i<row_size ; i++){
            for(int32_t j=0 ; j<col_size ; j++){
                if((i - j < 0) && (i + j < (row_size -1))){
                    all_color[i][j] = color;
                }
            }
        }
    }

    else if((x - y < 0) && (x + y > (row_size -1))){
        for(int32_t i=0 ; i<row_size ; i++){
            for(int32_t j=0 ; j<col_size ; j++){
                if((i - j < 0) && (i + j > (row_size -1))){
                    all_color[i][j] = color;
                }
            }
        }
    }

    else if((x - y > 0) && (x + y > (row_size -1))){
        for(int32_t i=0 ; i<row_size ; i++){
            for(int32_t j=0 ; j<col_size ; j++){
                if((i - j > 0) && (i + j > (row_size -1))){
                    all_color[i][j] = color;
                }
            }
        }
    }

    return;
}