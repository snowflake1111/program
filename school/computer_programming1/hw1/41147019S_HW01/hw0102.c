#include <stdio.h>
#include <stdint.h>
    
int main(){
    int32_t first_number = 0;
    int32_t second_number = 0;
    int32_t answer = 0;
    int32_t pos_answer = 0;
    int32_t pos = 1;
    int32_t first_one = 0;
    int32_t first_two = 0;
    int32_t first_three = 0;
    int32_t second_one = 0;
    int32_t second_two = 0;
    int32_t second_three = 0;
    int32_t answer_one = 0;
    int32_t answer_two = 0;
    int32_t answer_three = 0;


    printf("Please enter the first  number: ");
    scanf("%d", &first_number);
    
    printf("Please enter the second number: ");
    scanf("%d", &second_number);
    
    if(first_number < 100 ||
         first_number > 999 ||
           second_number < 100 ||
             second_number > 999){
        printf("Error\n");
    }
    else{
        answer = first_number - second_number;
    
        if(answer < 0){
            pos_answer = -1 * answer;
            pos = 0;
        }
        else{
            pos_answer = answer;
        }
    
        first_three = first_number % 10;
        first_two = (first_number / 10) % 10;
        first_one = first_number / 100;
    
        second_three = second_number % 10;
        second_two = (second_number / 10) % 10;
        second_one = second_number / 100;
    
        answer_three = pos_answer % 10;
        answer_two = (pos_answer / 10) % 10;
        answer_one = pos_answer / 100;
    
        printf("   %d %d %d\n", first_one, first_two, first_three);
        printf("-) %d %d %d\n", second_one, second_two, second_three);
        printf("--------\n");
        
        if(pos_answer >= 100){
            if(pos == 1){
                printf("   %d %d %d\n", answer_one, answer_two, answer_three);
            }
            else{
                printf(" - %d %d %d\n", answer_one, answer_two, answer_three);
            }
        }
        else if(pos_answer >= 10){
            if(pos == 1){
                printf("     %d %d\n", answer_two, answer_three);
            }
            else{
                printf("   - %d %d\n", answer_two, answer_three);
            }
        }
        else{
            if(pos == 1){
                printf("       %d\n", answer_three);
            }
            else{
                printf("     - %d\n", answer_three);
            }
        }
    }
    
    return 0;
}
