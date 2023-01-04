#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "division.h"

void division( uint8_t **ppQuotient , uint8_t *pQuotientSize ,
               uint8_t **ppRemainder , uint8_t *pRemainderSize ,
               uint8_t *pX, uint8_t xSize , uint8_t *pY, uint8_t ySize ){
    
    uint8_t digit = 0;
    uint8_t len = 0;
    
    if(xSize < ySize){
        *pQuotientSize = 1;
        *pRemainderSize = xSize;
        
        memory_alloc(ppQuotient, *pQuotientSize);
        memory_alloc(ppRemainder, *pRemainderSize);
        
        change(pX, pY, xSize, ySize);
        
        **ppQuotient = 0;
        
        for(int32_t i=0 ; i<xSize ; i++){
            *(*ppRemainder+i) = *(pX+i);
        }
        
        return;
    }
    
    if(*pX > *pY){
        *pQuotientSize = xSize - ySize + 1;
        memory_alloc(ppQuotient, *pQuotientSize);
    }
    else{
        *pQuotientSize = xSize - ySize;
        memory_alloc(ppQuotient, *pQuotientSize);
    }

    change(pX, pY, xSize, ySize);
    
    len = xSize - ySize;
    
    for(int32_t i=xSize-1 ; i>=0 ; i--){
        if(i >= len){
            *(pY+i) = *(pY+i-len);
        }
        else{
            *(pY+i) = 0;
        }
    }
    
    ySize = xSize;
    digit = xSize;

    int32_t state = 0;
    int32_t temp = 0;
    
    temp = judge(pX, pY, xSize, ySize);
    
    if(temp < 0){
                for(int32_t j=0 ; j<ySize-1 ; j++){
                    *(pY+j) = *(pY+j+1);
                }
                
                *(pY+ySize-1) = 0;
                
                ySize = ySize - 1;
                
                state = 1;
    }

    for(int32_t i=0 ; i<*pQuotientSize; i++){
        *(*ppQuotient+i) = 0;
        while(1){                
            temp = judge(pX, pY, xSize, ySize);     

            printf("before:pX:%u %u %u %u %u\n", *(pX+4), *(pX+3), *(pX+2), *(pX+1), *pX);
            printf("before:pY:%u %u %u %u %u\n", *(pY+4), *(pY+3), *(pY+2), *(pY+1), *pY);     
            
            if(temp < 0 ){
                for(int32_t j=0 ; j<ySize-1 ; j++){
                    *(pY+j) = *(pY+j+1);
                }
                
                *(pY+ySize-1) = 0;
                
                ySize = ySize - 1;
                
                break;
            } 

            minus(pX, pY, xSize, ySize, &digit);
                        
            *(*ppQuotient+i) = *(*ppQuotient+i) + 1;
            printf("%d plus %u %u\n", i, xSize, ySize);

            xSize = digit;

            while(xSize < ySize){
                ySize = ySize - 1;
                printf("%u %u\n", xSize, ySize);

                for(int32_t j=0 ; j<ySize-1 ; j++){
                    *(pY+j) = *(pY+j+1);
                }
                
                *(pY+ySize-1) = 0;
                
            }

//            if(xSize < ySize && *(pY+ySize-1) == 0){
//                ySize = xSize;

//            }
            printf("%u %u\n", xSize, ySize);
        }
    }
    
    change(pX, pY, xSize, ySize);
    
    *pRemainderSize = xSize;
    memory_alloc(ppRemainder, *pRemainderSize);
    
    for(int32_t i=0 ; i<xSize ; i++){
        *(*ppRemainder+i) = *(pX+i);
    }

    return;
}
 
void minus(uint8_t *x, uint8_t *y, uint8_t x_len, uint8_t y_len, uint8_t *digit){
    for(int32_t i=0 ; i<x_len ; i++){
        if(*(x+i) < *(y+i)){
            *(x+i) = *(x+i) + 10 - *(y+i);
            
            uint8_t n = 1;
            
            while(*(x+i+n) == 0){
                n = n + 1;
            }
            
            *(x+i+n) = *(x+i+n) - 1;
            
            for(int32_t j=1 ; j<n ; j++){
                *(x+i+j) = 9;
            }
        }
        else{
            *(x+i) = *(x+i) - *(y+i);
        }        
    }
    
    for(int32_t i=x_len-1 ; i>=0 ; i--){
        if(*(x+i) != 0){
            *digit = i + 1;
            
            break;
        }
    }
    
    return;
}

void change(uint8_t *x, uint8_t *y, uint8_t x_len, uint8_t y_len){
    uint8_t x_temp[x_len];
    uint8_t y_temp[y_len];
    
    for(int32_t i=0 ; i<x_len ; i++){
        x_temp[i] = *(x+i);
    }
    for(int32_t i=0 ; i<x_len ; i++){
        *(x+i) = x_temp[x_len-i-1];
    }
    
    for(int32_t i=0 ; i<y_len ; i++){
        y_temp[i] = *(y+i);
    }
    for(int32_t i=0 ; i<y_len ; i++){
        *(y+i) = y_temp[y_len-i-1];
    }
    
    return;
}

void memory_alloc(uint8_t **ptr, size_t s){
    *ptr = calloc(sizeof(uint8_t), s);

    return;
}

int32_t judge(uint8_t *x, uint8_t *y, uint8_t x_len, uint8_t y_len){
    if(x_len < y_len){
        return -1;
    }
    else if(x_len == y_len){
        for(int32_t i=x_len-1 ; i>=0 ; i--){
            if(*(x+i) == *(y+i)){
                continue;
            }
            else if(*(x+i) > *(y+i)){
                return 1;
            }
            else if(*(x+i) < *(y+i)){
                return -1;
            }
        }
        
        return 0;
    }

    return 1;
}