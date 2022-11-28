#include <stdio.h>
#include <stdint.h>
#include "basic.h"

void cell_calculate(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5]);
void step(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5], int32_t final_point[70], int32_t temp, int32_t save, int32_t index, int32_t type[5][5], int32_t result_type[8][70]);

int main(){
    int32_t point[5][5] = {{0}, {0}, {0}, {0}, {0}};
    int32_t final_point[70] = {0};
    int32_t result_type[8][70] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    int32_t top1 = 0;
    int32_t top2 = 0;
    int32_t top3 = 0;

    for(int32_t i=0 ; i<5 ; i++){
        for(int32_t j=0 ; j<5 ; j++){
            cell_calculate(i, j, AttributeID1, AttributeID2, point);
        }
    }
    
    step(0, 1, AttributeID1, AttributeID2, point, final_point, 0, 0, 0, TypeOfAttribute, result_type);
    step(1, 0, AttributeID1, AttributeID2, point, final_point, 0, 0, 0, TypeOfAttribute, result_type);


    //特殊規則
    if()    
    

    for(int32_t i=0 ; i<5 ; i++){
        for(int32_t j=0 ; j<5 ; j++){
            printf("%d", point[i][j]);
        }
    }

    for(int32_t i=0 ; i<70 ; i++){
        printf("%d", final_point[i]);
    }

    //判斷前三    
    
    
    for(int32_t i=0 ; i<3 ; i++){
        printf("%dst Top Total Point: %d. Type of five Artifacts: \n", i+1);
    }
    
    printf("Target Boss required point: %d\n", bossPoint);
    
    if(){
        printf("\033[32mReady Perfectly!\n\033[0m");
    }
    else{
        printf("\033[31mGonna be OK.\n\033[0m");
    }
    
    return 0;
}

void cell_calculate(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5]){
    if(ID1 == 1 || ID2 == 1){
        point[i][j] = point[i][j] + 125;
    }
    if(ID1 == 2 || ID2 == 2){
        point[i][j] = point[i][j] + 100;
    }
    if(ID1 == 3 || ID2 == 3){
        point[i][j] = point[i][j] + 75;
    }
    if(ID1 == 4 || ID2 == 4){
        point[i][j] = point[i][j] + 50;
    }
    if(ID1 == 5 || ID2 == 5){
        point[i][j] = point[i][j] + 50;
    }
    if(ID1 == 6 || ID2 == 6){
        point[i][j] = point[i][j] + 25;
    }
    if(ID1 == 7 || ID2 == 7){
        point[i][j] = point[i][j] + 10;
    }
}

void step(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5], int32_t final_point[70], int32_t temp, int32_t save, int32_t index, int32_t type[5][5], int32_t result_type[8][70]){
    temp = point[i][j];
    result_type
    
    if(i < 4 && j < 4){
        step(i+1, j, ID1, ID2, point, final_point, 0, save, index);
        step(i, j+1, ID1, ID2, point, final_point, 0, save, index);
    }
    else if(i == 4 && j < 4){
        step(i, j+1, ID1, ID2, point, final_point, 0, save, index);
    }
    else if(i == 4 && j < 4){
        step(i+1, j, ID1, ID2, point, final_point, 0, save, index);
    }
    else{
        final_point[index] = save;
        index = index + 1;
        save = save - temp;
    }    
}
