#include <stdio.h>
#include <stdint.h>

int main(){
    double first_x = 0;
    double first_y = 0;
    double second_x = 0;
    double second_y = 0;
    double third_x = 0;
    double third_y = 0;
    double slope = 0;
    double a = 0;
    double b = 0;
    
    printf("Please enter the point A (x,y): ");
    scanf("%lf,%lf", &first_x, &first_y);
    
    printf("Please enter the point B (x,y): ");
    scanf("%lf,%lf", &second_x, &second_y);
    
    printf("Please enter the point C (x,y): ");
    scanf("%lf,%lf", &third_x, &third_y);
    
    if((int32_t) first_x != first_x || (int32_t) first_y != first_y ||
       (int32_t) second_x != second_x || (int32_t) second_y != second_y ||
       (int32_t) third_x != third_x || (int32_t) third_y != third_y){
        printf("Error\n");
    }
    else if(first_x == second_x && first_y == second_y){
        printf("Error\n");
    }
    else if(first_x != second_x && first_y == second_y){
        printf("The line: x = %lf\n", third_x);
    }
    else if(first_x == second_x && first_y != second_y){
        printf("The line: y = %lf\n", third_y);
    }
    else{
        slope = (double) (second_y - first_y) / (double) (second_x - first_x);
        a = -1 / slope;
        b = third_y - a * third_x;
  
        if(b >= 0){
            printf("The line: y = %lf * x + %lf\n", a, b);
        }
        else{
            printf("The line: y = %lf * x - %lf\n", a, -b);
        }
     }
    
    return 0;
}
