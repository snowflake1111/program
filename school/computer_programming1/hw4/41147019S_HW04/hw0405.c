#include <stdio.h>
#include <stdint.h>
#include "basic.h"

void step(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5], int32_t score, int32_t x[8], int32_t y[8], 
int32_t five_x[5], int32_t five_y[5], int32_t index, int32_t type_count[7], int32_t path[21][5], int32_t five_type[70][5], int32_t path_five_type[5],
int32_t final_point[70], int32_t type[5][5], int32_t *count_ptr);
void cell_calculate(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5]);
void top5(int32_t x[9], int32_t y[9], int32_t path[21][5], int32_t five_x[5], int32_t five_y[5], int32_t point[5][5], int32_t path_five_type[5], int32_t type_count[7], int32_t type[5][5]);
void get_point(int32_t final_point[70], int32_t five_x[5], int32_t five_y[5], int32_t five_type[70][5], int32_t type[5][5], int32_t point[5][5], int32_t *count_ptr, int32_t type_count[7]);
void special(int32_t final_point[70], int32_t type_count[7], int32_t *count_ptr);
void count_calculate(int32_t five_type[70][5], int32_t type_count[7], int32_t *count_ptr);

int main(){
    int32_t point[5][5] = {{0}, {0}, {0}, {0}, {0}};
    int32_t final_point[70] = {0};
    int32_t top1 = 0;
    int32_t top1_index = 0;
    int32_t top2 = 0;
    int32_t top2_index = 0;
    int32_t top3 = 0;
    int32_t top3_index = 0;
    int32_t score = 0;
    int32_t five_x[5] = {0};
    int32_t five_y[5] = {0};
    int32_t x[9] = {0};
    int32_t y[9] = {0};
    int32_t five_type[70][5] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
    int32_t index = 0;
    int32_t count = 0;
    int32_t type_count[7] = {0};
    int32_t path_five_type[5] = {0};
    int32_t path[21][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 6}, {1, 2, 3, 4, 7},
                           {1, 2, 3, 5, 6}, {1, 2, 3, 5, 7}, {1, 2, 3, 6, 7},
                           {1, 2, 4, 5, 6}, {1, 2, 4, 5, 7}, {1, 2, 4, 6, 7},
                           {1, 2, 5, 6, 7}, {1, 3, 4, 5, 6}, {1, 3, 4, 5, 7},
                           {1, 3, 4, 6, 7}, {1, 3, 5, 6, 7}, {1, 4, 5, 6, 7},
                           {2, 3, 4, 5, 6}, {2, 3, 4, 5, 7}, {2, 3, 4, 6, 7},
                           {2, 3, 5, 6, 7}, {2, 4, 5, 6, 7}, {3, 4, 5, 6, 7}};   
    
    for(int32_t i=0 ; i<5 ; i++){
        for(int32_t j=0 ; j<5 ; j++){
            cell_calculate(i, j, AttributeID1, AttributeID2, point);
        }
    }
    
    step(0, 0, AttributeID1, AttributeID2, point, score, x, y, five_x, five_y, index, type_count, path, five_type, path_five_type, final_point, TypeOfAttribute, &count);
    
    printf("final point: ");
    for(int32_t i=0 ; i<70 ; i++){
        printf("%d ", final_point[i]);
    }
    
    printf("\n");

    for(int32_t i=0 ; i<5 ; i++){
        for(int32_t j=0 ; j<5 ; j++){
            printf("%d ", point[i][j]);
        }
        printf("\n");
    }

    for(int32_t i=0 ; i<70 ; i++){
        if(final_point[i] > top1){
            top1 = final_point[i];
            top1_index = i;
        }
        else if(final_point[i] > top2){
            top2 = final_point[i];
            top2_index = i;
        }
        else if(final_point[i] > top3){
            top3 = final_point[i];
            top3_index = i;
        }
    }

    printf("1st Top Total Point: %d. Type of five Artifacts: %d %d %d %d %d\n", top1, five_type[top1_index][0], five_type[top1_index][1], five_type[top1_index][2], five_type[top1_index][3], five_type[top1_index][4]);
    printf("2nd Top Total Point: %d. Type of five Artifacts: %d %d %d %d %d\n", top2, five_type[top2_index][0], five_type[top2_index][1], five_type[top2_index][2], five_type[top2_index][3], five_type[top2_index][4]);
    printf("3rd Top Total Point: %d. Type of five Artifacts: %d %d %d %d %d\n", top3, five_type[top3_index][0], five_type[top3_index][1], five_type[top3_index][2], five_type[top3_index][3], five_type[top3_index][4]);
    
    printf("Target Boss required point: %d\n", bossPoint);
    
    if(top3 >= bossPoint){
        printf("\033[32mReady Perfectly!\n\033[0m");
    }
    else{
        printf("\033[31mGonna be OK.\n\033[0m");
    }
    
    return 0;
}

void step(int32_t i, int32_t j, int32_t ID1[5][5], int32_t ID2[5][5], int32_t point[5][5], int32_t score, int32_t x[9], int32_t y[9], 
int32_t five_x[5], int32_t five_y[5], int32_t index, int32_t type_count[7], int32_t path[21][5], int32_t five_type[70][5], int32_t path_five_type[5],
int32_t final_point[70], int32_t type[5][5], int32_t *count_ptr){
    x[index] = i;
    y[index] = j;  
    
    if(i == 4 && j == 4){
        top5(x, y, path, five_x, five_y, point, path_five_type, type_count, type);
        get_point(final_point, five_x, five_y, five_type, type, point, count_ptr, type_count);
        
        printf("score: %d", score);
        printf("\n");
        printf("final point: %d", final_point[*count_ptr]);
        printf("\n");
        
        printf("x: ");
        for(int32_t i=0 ; i<9 ; i++){
            printf("%d ", x[i]);
        }

        printf("\n");

        printf("y: ");
        for(int32_t i=0 ; i<9 ; i++){
            printf("%d ", y[i]);
        }

        printf("\n");
    }
    else{
        if(j < 4){
            step(i, j+1, ID1, ID2, point, score + point[i][j], x, y, five_x, five_y, index+1, type_count, path, five_type, path_five_type, final_point, type, count_ptr);
            
        }
        if(i < 4){
            step(i+1, j, ID1, ID2, point, score + point[i][j], x, y, five_x, five_y, index+1, type_count, path, five_type, path_five_type, final_point, type, count_ptr);
        }
    }

    return;
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

    return;
}

void top5(int32_t x[9], int32_t y[9], int32_t path[21][5], int32_t five_x[5], int32_t five_y[5], int32_t point[5][5], int32_t path_five_type[5], int32_t type_count[7], int32_t type[5][5]){
    int32_t path_point = 0;
    int32_t max = 0;
    int32_t max_index = 0;

    for(int32_t i=0 ; i<21 ; i++){
        for(int32_t j=0 ; j<5 ; j++){
            path_point = path_point + point[x[path[i][j]]][y[path[i][j]]];
            path_five_type[j] = type[x[path[i][j]]][y[path[i][j]]];

            if(path_five_type[j] == 1){
                type_count[0] = type_count[0] + 1;
            }
            else if(path_five_type[j] == 2){
                type_count[1] = type_count[1] + 1;
            }
            else if(path_five_type[j] == 3){
                type_count[2] = type_count[2] + 1;
            }
            else if(path_five_type[j] == 4){
                type_count[3] = type_count[3] + 1;
            }
            else if(path_five_type[j] == 5){
                type_count[4] = type_count[4] + 1;
            }
            else if(path_five_type[j] == 6){
                type_count[5] = type_count[5] + 1;
            }
            else if(path_five_type[j] == 7){
                type_count[6] = type_count[6] + 1;
            }
        }

        for(int32_t j=0 ; j<7 ; j++){
            if(type_count[j] >= 2){
                if(type_count[j] >= 4){
                    if(j == 0){
                        path_point = path_point + 160;
                    }
                    else if(j == 1){
                        path_point = path_point + 150;
                    }
                    else if(j == 2){
                        path_point = path_point + 75;
                    }
                    else if(j == 3){
                        path_point = path_point + 135;
                    }
                    else if(j == 4){
                        path_point = path_point + 125;
                    }
                    else if(j == 5){
                        path_point = path_point + 95;
                    }
                    else if(j == 6){
                        path_point = path_point + 110;
                    }
                }
                else{
                    if(j == 0){
                        path_point = path_point + 10;
                    }
                    else if(j == 1){
                        path_point = path_point + 20;
                    }
                    else if(j == 2){
                        path_point = path_point + 35;
                    }
                    else if(j == 3){
                        path_point = path_point + 50;
                    }
                    else if(j == 4){
                        path_point = path_point + 60;
                    }
                    else if(j == 5){
                        path_point = path_point + 75;
                    }
                    else if(j == 6){
                        path_point = path_point + 100;
                    }
                }
            }
        }

        for(int32_t j=0 ; j<7 ; j++){
            type_count[j] = 0;
        }

        if(path_point > max){
            max = path_point;
            max_index = i;
        }

        path_point = 0;
    }

    for(int32_t i=0 ; i<5 ; i++){
        five_x[i] = x[path[max_index][i]];
        five_y[i] = y[path[max_index][i]];
    }

    return;
}

void get_point(int32_t final_point[70], int32_t five_x[5], int32_t five_y[5], int32_t five_type[70][5], int32_t type[5][5], int32_t point[5][5], int32_t *count_ptr, int32_t type_count[7]){
    for(int32_t i=0 ; i<5 ; i++){
        five_type[*count_ptr][i] = type[five_x[i]][five_y[i]];
        final_point[*count_ptr] = final_point[*count_ptr] + point[five_x[i]][five_y[i]];
    }
    
    count_calculate(five_type, type_count, count_ptr);
    special(final_point, type_count, count_ptr);

    *count_ptr = *count_ptr + 1; 

    return;    
}

void special(int32_t final_point[70], int32_t type_count[7], int32_t *count_ptr){
    for(int32_t i=0 ; i<7 ; i++){
        if(type_count[i] >= 2){
            if(type_count[i] >= 4){
                if(i == 0){
                    final_point[*count_ptr] = final_point[*count_ptr] + 160;
                }
                else if(i == 1){
                    final_point[*count_ptr] = final_point[*count_ptr] + 150;
                }
                else if(i == 2){
                    final_point[*count_ptr] = final_point[*count_ptr] + 75;
                }
                else if(i == 3){
                    final_point[*count_ptr] = final_point[*count_ptr] + 135;
                }
                else if(i == 4){
                    final_point[*count_ptr] = final_point[*count_ptr] + 125;
                }
                else if(i == 5){
                    final_point[*count_ptr] = final_point[*count_ptr] + 95;
                }
                else if(i == 6){
                    final_point[*count_ptr] = final_point[*count_ptr] + 110;
                }
            }
            else{
                if(i == 0){
                    final_point[*count_ptr] = final_point[*count_ptr] + 10;
                }
                else if(i == 1){
                    final_point[*count_ptr] = final_point[*count_ptr] + 20;
                }
                else if(i == 2){
                    final_point[*count_ptr] = final_point[*count_ptr] + 35;
                }
                else if(i == 3){
                    final_point[*count_ptr] = final_point[*count_ptr] + 50;
                }
                else if(i == 4){
                    final_point[*count_ptr] = final_point[*count_ptr] + 60;
                }
                else if(i == 5){
                    final_point[*count_ptr] = final_point[*count_ptr] + 75;
                }
                else if(i == 6){
                    final_point[*count_ptr] = final_point[*count_ptr] + 100;
                }
            }
        }
    }

    for(int32_t i=0 ; i<7 ; i++){
        type_count[i] = 0;
    }

    return;
}

void count_calculate(int32_t five_type[70][5], int32_t type_count[7], int32_t *count_ptr){
    for(int32_t i=0 ; i<5 ; i++){
        if(five_type[*count_ptr][i] == 1){
            type_count[0] = type_count[0] + 1;
        }
        else if(five_type[*count_ptr][i] == 2){
            type_count[1] = type_count[1] + 1;
        }
        else if(five_type[*count_ptr][i] == 3){
            type_count[2] = type_count[2] + 1;
        }
        else if(five_type[*count_ptr][i] == 4){
            type_count[3] = type_count[3] + 1;
        }
        else if(five_type[*count_ptr][i] == 5){
            type_count[4] = type_count[4] + 1;
        }
        else if(five_type[*count_ptr][i] == 6){
            type_count[5] = type_count[5] + 1;
        }
        else if(five_type[*count_ptr][i] == 7){
            type_count[6] = type_count[6] + 1;
        }
    }

    return;
}