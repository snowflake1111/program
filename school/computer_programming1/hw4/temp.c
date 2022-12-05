#include <stdio.h>
#include <stdint.h>
#include "basic.h"

void cell_calculate(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5]);
void step(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5], int32_t final_point[70], int32_t temp[9], /*int32_t *save_ptr,*/ int32_t *index_ptr, int32_t type[5][5], int32_t result_type[71][9], int32_t *count_ptr, int32_t result_ID1[71][9], int32_t result_ID2[71][9]);
void special(int32_t i, int32_t result_type[71][9], int32_t result_ID1[71][9], int32_t result_ID2[71][9], int32_t final_point[70]);
void sort(int32_t k, int32_t array[], int32_t result_type[71][9], int32_t result_ID1[71][9], int32_t result_ID2[71][9], size_t n);

int main(){
    int32_t point[5][5] = {{0}, {0}, {0}, {0}, {0}};
    int32_t final_point[70] = {0};
    int32_t result_type[71][9] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    int32_t result_ID1[71][9] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    int32_t result_ID2[71][9] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    int32_t temp[9] = {0};
    int32_t top1 = 0;
    int32_t top2 = 0;
    int32_t top3 = 0;
    int32_t index = 0;
    int32_t count = 0;
    int32_t save = 0;

    for(int32_t i=0 ; i<5 ; i++){
        for(int32_t j=0 ; j<5 ; j++){
            cell_calculate(i, j, AttributeID1, AttributeID2, point);
        }
    }
    
    step(0, 1, AttributeID1, AttributeID2, point, final_point, temp, /*&save,*/ &index, TypeOfAttribute, result_type, &count, result_ID1, result_ID2);
    step(1, 0, AttributeID1, AttributeID2, point, final_point, temp, /*&save,*/ &index, TypeOfAttribute, result_type, &count, result_ID1, result_ID2);

    for(int32_t i=0 ; i<70 ; i++){
        printf("%d ", final_point[i]);
    } 

    printf("\n");  

    //特殊規則
    for(int32_t i=0 ; i<70 ; i++){
        special(i, result_type, result_ID1, result_ID2, final_point);
    }

    for(int32_t i=0 ; i<5 ; i++){
        for(int32_t j=0 ; j<5 ; j++){
            printf("%d ", point[i][j]);
        }
        printf("\n");
    }

    for(int32_t i=0 ; i<70 ; i++){
        printf("%d ", final_point[i]);
    }

    printf("\n");

    //判斷前三    
    
    
    for(int32_t i=0 ; i<3 ; i++){
        printf("%dst Top Total Point: %d. Type of five Artifacts: \n", i+1);
    }
    
    printf("Target Boss required point: %d\n", bossPoint);
    
//    if(){
        printf("\033[32mReady Perfectly!\n\033[0m");
//    }
//    else{
        printf("\033[31mGonna be OK.\n\033[0m");
//    }
    
    return 0;
}

void cell_calculate(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5]){
    if(ID1[i][j] == 1 || ID2[i][j] == 1){
        point[i][j] = point[i][j] + 125;
    }
    if(ID1[i][j] == 2 || ID2[i][j] == 2){
        point[i][j] = point[i][j] + 100;
    }
    if(ID1[i][j] == 3 || ID2[i][j] == 3){
        point[i][j] = point[i][j] + 75;
    }
    if(ID1[i][j] == 4 || ID2[i][j] == 4){
        point[i][j] = point[i][j] + 50;
    }
    if(ID1[i][j] == 5 || ID2[i][j] == 5){
        point[i][j] = point[i][j] + 50;
    }
    if(ID1[i][j] == 6 || ID2[i][j] == 6){
        point[i][j] = point[i][j] + 25;
    }
    if(ID1[i][j] == 7 || ID2[i][j] == 7){
        point[i][j] = point[i][j] + 10;
    }
}

void step(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5], int32_t final_point[70], int32_t temp[9], /*int32_t *save_ptr,*/ int32_t *index_ptr, int32_t type[5][5], int32_t result_type[71][9], int32_t *count_ptr, int32_t result_ID1[71][9], int32_t result_ID2[71][9]){
    *count_ptr = *count_ptr + 1;
    temp[*count_ptr] = point[i][j];
//    *save_ptr = *save_ptr + temptemp[(*count_ptr)-1];
    result_type[*index_ptr][(*count_ptr)-1] = type[i][j];
//    result_type[(*index_ptr)+1][(*count_ptr)-1] = type[i][j];
    result_ID1[*index_ptr][(*count_ptr)-1] = ID1[i][j];
//    result_ID1[(*index_ptr)+1][(*count_ptr)-1] = ID1[i][j];
    result_ID2[*index_ptr][(*count_ptr)-1] = ID2[i][j];
//    result_ID2[(*index_ptr)+1][(*count_ptr)-1] = ID2[i][j];
    
    if(i < 4 && j < 4){
        step(i, j+1, AttributeID1, AttributeID2, point, final_point, temp, /*save_ptr,*/ index_ptr, TypeOfAttribute, result_type, count_ptr, result_ID1, result_ID2);
        step(i+1, j, AttributeID1, AttributeID2, point, final_point, temp, /*save_ptr,*/ index_ptr, TypeOfAttribute, result_type, count_ptr, result_ID1, result_ID2);
    }
    else if(i == 4 && j < 4){
        step(i, j+1, AttributeID1, AttributeID2, point, final_point, temp, /*save_ptr,*/ index_ptr, TypeOfAttribute, result_type, count_ptr, result_ID1, result_ID2);
    }
    else if(i < 4 && j == 4){
        step(i+1, j, AttributeID1, AttributeID2, point, final_point, temp, /*save_ptr,*/ index_ptr, TypeOfAttribute, result_type, count_ptr, result_ID1, result_ID2);
    }
    else{
        for(int32_t k=0 ; k<8 ; k++){
            result_type[(*index_ptr)+1][k] = result_type[*index_ptr][k];
            result_ID1[(*index_ptr)+1][k] = result_ID1[*index_ptr][k];
            result_ID2[(*index_ptr)+1][k] = result_ID2[*index_ptr][k];
        }

        sort(*index_ptr, temp, result_type, result_ID1, result_ID2, 8);
        
        for(int32_t k=0 ; k<5 ; k++){
            final_point[*index_ptr] = final_point[*index_ptr] + temp[k];
            printf("%d ", final_point[*index_ptr]);
            printf("\n");
        }

//        final_point[*index_ptr] = *save_ptr;
        *index_ptr = *index_ptr + 1;
    }   

    temp[*count_ptr] = 0;
//    *save_ptr = *save_ptr - temp;
    *count_ptr = *count_ptr - 1;
}

void special(int32_t i, int32_t result_type[71][9], int32_t result_ID1[71][9], int32_t result_ID2[71][9], int32_t final_point[70]){
    int32_t count_type[7] = {0};

    for(int32_t j=0 ; j<5 ; j++){
        if(result_type[i][j] == 1){
            count_type[0] = count_type[0] + 1;
        }
        else if(result_type[i][j] == 2){
            count_type[1] = count_type[1] + 1;
        }
        else if(result_type[i][j] == 3){
            count_type[2] = count_type[2] + 1;
        }
        else if(result_type[i][j] == 4){
            count_type[3] = count_type[3] + 1;
        }
        else if(result_type[i][j] == 5){
            count_type[4] = count_type[4] + 1;
        }
        else if(result_type[i][j] == 6){
            count_type[5] = count_type[5] + 1;
        }
        else if(result_type[i][j] == 7){
            count_type[6] = count_type[6] + 1;
        }
    }

    for(int32_t j=0 ; j<7 ; j++){
        if(count_type[j] >= 2){
            if(count_type[j] >= 4){
                if(j == 0){
                    final_point[i] = final_point[i] + 160;
                }
                else if(j == 1){
                    final_point[i] = final_point[i] + 150;
                }
                else if(j == 2){
                    final_point[i] = final_point[i] + 75;
                }
                else if(j == 3){
                    final_point[i] = final_point[i] + 135;
                }
                else if(j == 4){
                    final_point[i] = final_point[i] + 125;
                }
                else if(j == 5){
                    final_point[i] = final_point[i] + 95;
                }
                else if(j == 6){
                    final_point[i] = final_point[i] + 110;
                }
            }
            else{
                if(j == 0){
                    final_point[i] = final_point[i] + 10;
                }
                else if(j == 1){
                    final_point[i] = final_point[i] + 20;
                }
                else if(j == 2){
                    final_point[i] = final_point[i] + 35;
                }
                else if(j == 3){
                    final_point[i] = final_point[i] + 50;
                }
                else if(j == 4){
                    final_point[i] = final_point[i] + 60;
                }
                else if(j == 5){
                    final_point[i] = final_point[i] + 75;
                }
                else if(j == 6){
                    final_point[i] = final_point[i] + 100;
                }
            }
        }
    }
}

void sort(int32_t k, int32_t array[], int32_t result_type[71][9], int32_t result_ID1[71][9], int32_t result_ID2[71][9], size_t n){
    for(int32_t i=0 ; i<n ; i++){
        for(int32_t j=i+1 ; j<n ; j++){
            if(array[j] > array[i]){
                int32_t temp = 0;

                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                temp = result_type[k][i];
                result_type[k][i] = result_type[k][j];
                result_type[k][j] = temp;

                temp = result_ID1[k][i];
                result_ID1[k][i] = result_ID1[k][j];
                result_ID1[k][j] = temp;

                temp = result_ID2[k][i];
                result_ID2[k][i] = result_ID2[k][j];
                result_ID2[k][j] = temp;
            }
        }
    }
}
