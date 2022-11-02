#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "hanoi.h"

void step1(int32_t n, int32_t from, int32_t mid, int32_t to){
    if(n == 1){
        printf("move disk %d to %d\n", n, to);
    }
    else {
        step1(n-1, from, to, mid);
        printf("move disk %d to %d\n", n, to);
        step1(n-1, mid, from, to);
    }

    return;
}

void step2(int32_t n){
    int32_t disk = 0;
    int32_t count = 0;
    int32_t place[25] = {0};

    for(int32_t i=1 ; i<=n ; i++){
        place[i] = 1;
    }

    for(int32_t i=0 ; i<(pow(2, n)-1) ; i++){
        for(int32_t j=i+1 ; j%2==0 ; j=j/2){
            count = count + 1;
        }

        disk = count + 1;
        
        if((disk % 2 == 0) && (n % 2 == 0)){
            if(place[disk] == 1){
                place[disk] = 2;
            }
            else if(place[disk] == 2){
                place[disk] = 3;
            }
            else{
                place[disk] = 1;
            }
        }
        else if((disk % 2 != 0) && (n % 2 == 0)){
            if(place[disk] == 1){
                place[disk] = 3;
            }
            else if(place[disk] == 2){
                place[disk] = 1;
            }
            else{
                place[disk] = 2;
            }
        }
        else if((disk % 2 == 0) && (n % 2 != 0)){
            if(place[disk] == 1){
                place[disk] = 3;
            }
            else if(place[disk] == 2){
                place[disk] = 1;
            }
            else{
                place[disk] = 2;
            }
        }
        else{
            if(place[disk] == 1){
                place[disk] = 2;
            }
            else if(place[disk] == 2){
                place[disk] = 3;
            }
            else{
                place[disk] = 1;
            }
        }

        printf("move disk %d to %d\n", disk, place[disk]);

        count = 0;
    }

    return;
}