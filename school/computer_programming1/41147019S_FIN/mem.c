#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mem.h"

int32_t mymem_alloc( uint8_t **ptr, size_t size ){
    *ptr = calloc(sizeof(int32_t), size);

    return 0;
}

int32_t mymem_set( uint8_t *ptr, size_t idx, uint8_t value ){
    if(ptr == NULL || idx < 0){
        return -1;
    }
    
    *(ptr+idx) = value;
    
    return 0;
}

int32_t mymem_set_array( uint8_t *ptr, size_t start , uint8_t array[], size_t n ){
    if(ptr == NULL){
        return -1;
    }

    for(int32_t i=0 ; i<n ; i++){
        *(ptr+start+i) = array[i];
    } 

    return 0;
}

int32_t mymem_rellocate( uint8_t **ptr, size_t new_size ){
    if(ptr == NULL){
        return -1;
    }

    *ptr = calloc(sizeof(int32_t), new_size);

    return 0;
}

void mymem_free( uint8_t *ptr ){
    if(ptr != NULL){
        free(ptr);
    }

    return;
}