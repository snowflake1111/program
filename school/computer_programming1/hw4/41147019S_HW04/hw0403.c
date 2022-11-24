#include <stdio.h>
#include <stdint.h>
#define RED "\x1B[0;31m"    //1
#define RED_L "\x1B[1;31m"  //2
#define GRN "\x1B[0;32m"    //3
#define YEL "\x1B[0;33m"    //4
#define BLU "\x1B[0;34m"    //5
#define RESET "\x1B[0m"     //6

void print(int32_t color[][12]);

int main(){
    int32_t input = 0;
    int32_t color[9][12] = {{0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 6, 6, 6, 0, 0, 0, 0, 0, 0},
                            {3, 3, 3, 1, 1, 1, 5, 5, 5, 2, 2, 2},
                            {3, 3, 3, 1, 1, 1, 5, 5, 5, 2, 2, 2},
                            {3, 3, 3, 1, 1, 1, 5, 5, 5, 2, 2, 2},
                            {0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0}};
                                
    printf("Start:\n");
    print(color);
    
    while(1){
        printf(RESET"Input [0-6]: ");
        scanf("%d", &input);
        
        int32_t temp1[3][3] = {{0}, {0}};
        int32_t temp2[12] = {0};
        
        if(input == 0){
            break;
        }
        else if(input == 1 || input == 2 || input == 3){      
            if(input == 1){
                for(int32_t i=0 ; i<3 ; i++){
                    for(int32_t j=0 ; j<3 ; j++){
                        temp1[i][j] = color[i][j+3];
                    }
                }
                for(int32_t i=0 ; i<3 ; i++){
                    for(int32_t j=0 ; j<3 ; j++){
                        color[i][j+3] = temp1[j][2-i];
                    }
                }
            }
         
            for(int32_t i=0 ; i<12 ; i++){
                temp2[i] = color[input+2][i];
            }
            for(int32_t i=0 ; i<3 ; i++){
                color[input+2][i] = temp2[i+9];
            }
            for(int32_t i=0 ; i<9 ; i++){
                color[input+2][i+3] = temp2[i];
            }

            if(input == 3){
                for(int32_t i=0 ; i<3 ; i++){
                    for(int32_t j=0 ; j<3 ; j++){
                        temp1[i][j] = color[i+6][j+3];
                    }
                }
                for(int32_t i=0 ; i<3 ; i++){
                    for(int32_t j=0 ; j<3 ; j++){
                        color[i+6][j+3] = temp1[2-j][i];
                    }
                }
            }
        }
        else if(input == 4 || input == 5 || input == 6){  
            if(input == 4){
                for(int32_t i=0 ; i<3 ; i++){
                    for(int32_t j=0 ; j<3 ; j++){
                        temp1[i][j] = color[i+3][j];
                    }
                }
                for(int32_t i=0 ; i<3 ; i++){
                    for(int32_t j=0 ; j<3 ; j++){
                        color[i+3][j] = temp1[2-j][i];
                    }
                }
            }
         
            for(int32_t i=0 ; i<9 ; i++){
                temp2[i] = color[i][input-1];
            }
            for(int32_t i=0 ; i<3 ; i++){
                temp2[i+9] = color[i+3][15-input];
            }

            for(int32_t i=0 ; i<3 ; i++){
                color[i][input-1] = temp2[11-i];
            }
            for(int32_t i=0 ; i<6 ; i++){
                color[i+3][input-1] = temp2[i];
            }
            for(int32_t i=0 ; i<3 ; i++){
                color[i+3][15-input] = temp2[i+6];
            }

            if(input == 6){
                for(int32_t i=0 ; i<3 ; i++){
                    for(int32_t j=0 ; j<3 ; j++){
                        temp1[i][j] = color[i+3][j+6];
                    }
                }
                for(int32_t i=0 ; i<3 ; i++){
                    for(int32_t j=0 ; j<3 ; j++){
                        color[i+3][j+6] = temp1[j][2-i];
                    }
                }
            }
        }
        else{
            printf("Wrong input\n");
            continue;
        }

        print(color);
    }
    
    return 0;
}

void print(int32_t color[][12]){
    for(int32_t i=3 ; i<6 ; i++){
        for(int32_t j=3 ; j<5 ; j++){
            if(color[i][j] == 1){
                printf(RED"* ");
            }
            else if(color[i][j] == 2){
                printf(RED_L"* ");
            }
            else if(color[i][j] == 3){
                printf(GRN"* ");
            }
            else if(color[i][j] == 4){
                printf(YEL"* ");
            }
            else if(color[i][j] == 5){
                printf(BLU"* ");
            }
            else if(color[i][j] == 6){
                printf(RESET"* ");
            }
        }
        
        if(color[i][5] == 1){
            printf(RED"*\n");
        }
        else if(color[i][5] == 2){
            printf(RED_L"*\n");
        }
        else if(color[i][5] == 3){
            printf(GRN"*\n");
        }
        else if(color[i][5] == 4){
            printf(YEL"*\n");
        }
        else if(color[i][5] == 5){
            printf(BLU"*\n");
        }
        else if(color[i][5] == 6){
            printf(RESET"*\n");
        }
    }
    
    return;
}
