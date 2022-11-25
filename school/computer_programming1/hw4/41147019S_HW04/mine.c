#include <stdio.h>
#include <stdint.h>
#include "mine.h"

void find_good_cells( const int32_t board[16][30], int32_t row[480], int32_t col[480] ){
    int32_t count[16][30] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    int32_t flag[16][30] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    int32_t real_board[16][30] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    int32_t max = 0;
    int32_t value = 0;
    
    //判斷真正值
    for(int32_t i=0 ; i<16 ; i++){
        for(int32_t j=0 ; j<30 ; j++){
            change_board(i, j, board, real_board);
        }
    }
    
    //印出真正值
    for(int32_t i=0 ; i<16 ; i++){
        for(int32_t j=0 ; j<30 ; j++){
            printf("%d ", real_board[i][j]);
        }
        
        printf("\n");
    }
    
    //計算count
    for(int32_t i=0 ; i<16 ; i++){
        for(int32_t j=0 ; j<30 ; j++){
            count[i][j] = calculate(i, j, real_board, count, flag);
            
            if(count[i][j] > max){
                max = count[i][j];
            }
            
            //flag清零
            for(int32_t i=0 ; i<16 ; i++){
                for(int32_t j=0 ; j<30 ; j++){
                    flag[i][j] = 0;
                }
            }
        }
    }
    
    printf("\n\n");
    
    //印出count
    for(int32_t i=0 ; i<16 ; i++){
        for(int32_t j=0 ; j<30 ; j++){
            printf("%d ", count[i][j]);
        }
        
        printf("\n");
    }
    
    for(int32_t i=0 ; i<16 ; i++){
        for(int32_t j=0 ; j<30 ; j++){
            if(count[i][j] == max){
                printf("row %d col %d\n", i, j);
            }
        }
    }
    
    return;
}

void change_board(int32_t a, int32_t b, const int32_t board[16][30], int32_t real_board[16][30]){
    if(board[a][b] == 1){
        real_board[a][b] = -1;
        
        return;
    }
    
    for(int32_t i=a-1 ; i<a+2 ; i++){
        for(int32_t j=b-1 ; j<b+2 ; j++){
            if(i<0 || j<0 || i>15 || j>29 || ((i == a) && (j == b))){
                continue;
            }
            else{
                if(board[i][j] == 1){
                    real_board[a][b] = real_board[a][b] + 1;
                }
            }
        }
    }
    
    return;
}

int32_t calculate(int32_t a, int32_t b, int32_t real_board[16][30], int32_t count[16][30], int32_t flag[16][30]){
    int32_t temp[16][30] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    
    flag[a][b] = 1;
    
    if(real_board[a][b] == -1){
        return 0;
    }
    else if(real_board[a][b] > 0){
        return 1;
    }
    
    temp[a][b] = 1;
    
    for(int32_t i=a-1 ; i<a+2 ; i++){
        for(int32_t j=b-1 ; j<b+2 ; j++){
            if(i<0 || j<0 || i>15 || j>29 || flag[i][j] == 1){
                continue;
            }
            else{
                if(real_board[i][j] > 0){
                    temp[a][b] = temp[a][b] + 1;
                    flag[i][j] = 1;
                }
                else if(real_board[i][j] == 0){
                    temp[a][b] = temp[a][b] + calculate(i, j, real_board, count, flag);
                }
            }
        }
    }
    
    return temp[a][b];
}
