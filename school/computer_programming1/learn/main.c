#include <stdio.h>
//#include "myfunction.h"
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void sort(int32_t array[], size_t n);
void mean(const int32_t array[], size_t n);
void median(const int32_t array[], size_t n);

int main(){
    int32_t array[100] = {0};
    int32_t n = 0;

    srand(time(0));

    scanf("%d", &n);

    for(int32_t i=0 ; i<n ; i++){
        array[i] = rand() % 10 + 1;
        printf("%d ", array[i]);
    }

    printf("\n");

    sort(array, n);
    
    for(int32_t i=0 ; i<n ; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
    
    mean(array, n);
    median(array, n);

    return 0;
}

void sort(int32_t array[], size_t n){
    for(int32_t i=0 ; i<n ; i++){
        for(int32_t j=i+1 ; j<n ; j++){
            if(array[j] < array[i]){
                int32_t temp = 0;

                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void median(const int32_t array[], size_t n){
    if(n % 2 == 0){
        printf("median: %lf\n", (double) (array[n/2-1] + array[n/2]) / 2);    
    }
    else{
        printf("median: %lf\n", (double) array[(n+1)/2-1]);
    }

    return;
}

void mean(const int32_t array[], size_t n){
    int64_t sum = 0;
    
    for(int32_t i=0 ; i<n ; i++){
        sum = sum + array[i];
    }

    printf("mean: %lf\n", (double) sum / n);
    
    return;
}