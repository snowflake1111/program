#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int main(){
    double distance = 12.3;
    double hare_speed = 0;
    double tortoise_speed = 0.3;
    double nap = 0;
    double run_hare = 0;
    double run_tortoise = 0;
    
    srand(time(0));

    printf("The Hare Speed (m/turn): ");
    scanf("%lf", &hare_speed);
    
    printf("The Nap Probability (0-1): ");
    scanf("%lf", &nap);
    
    printf("Turn 0) Tortoise: 0.000000, Hare: 0.000000\n");   

    for(int32_t i=1 ; run_hare <= 12.3 && run_tortoise <= 12.3 ; i++){
        run_tortoise = run_tortoise + 0.3;
        nap = rand() % 2;

        printf("Turn %d) Tortoise: %f, Hare: %f");

        if(run_hare > 12.3 && run_tortoise > 12.3){
            printf("Turn %d) Tortoise: %f, Hare: %f");
        }

    }


    return 0;
}