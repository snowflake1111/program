#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "division.h"
 
void division( uint8_t **ppQuotient , uint8_t *pQuotientSize ,
               uint8_t **ppRemainder , uint8_t *pRemainderSize ,
               uint8_t *pX, uint8_t xSize , uint8_t *pY, uint8_t ySize ){
    
    uint8_t digit = 0;
    uint8_t Q_temp[xSize];
    uint8_t len = 0;
    
    if(xSize < ySize){
        *pQuotientSize = 1;
        *pRemainderSize = xSize;
        
        memory_alloc(ppQuotient, *pQuotientSize);
        memory_alloc(ppRemainder, *pRemainderSize);
        
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

    for(int32_t i=ySize ; i<xSize ; i++){
        *(pY+i) = 0;
    }

    ySize = xSize;
    digit = xSize;

    for(int32_t i=0 ; i<*pQuotientSize ; i++){
        *(*ppQuotient+i) = 0;
        int32_t temp = 0;

        while(1){
            temp = judge(pX, pY, xSize, ySize);

            if(temp < 0 || digit < 0){
                break;
            }

            minus(pX, pY, xSize, ySize, &digit);

            *(*ppQuotient+i) = *(*ppQuotient+i) + 1;

            xSize = digit;

            if(xSize < ySize && *(pY+ySize-1) == 0){
                ySize = xSize;
            }
        }

        if(temp < 0){
            for(int32_t j=0 ; j<ySize-1 ; j++){
                *(pY+ySize-j-2) = *(pY+ySize-j-1);
            }
            
            *pY = 0;
            
            if(xSize < ySize){
                ySize = ySize - 1;
            }
        }
    }

    *pRemainderSize = xSize;
    memory_alloc(ppRemainder, *pRemainderSize);
    
    for(int32_t i=0 ; i<xSize ; i++){
        *(*ppRemainder+i) = *(pX+i);
    }




/*

    change(*ppQuotient, *ppRemainder, *pQuotientSize, *pRemainderSize);
    
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
    
    for(int32_t i=0 ; i<=len ; i++){
        int32_t temp = 0;
        Q_temp[len-i] = 0;
        
        while(1){
            temp = judge(pX, pY, xSize, ySize);
            
            if(temp < 0 || digit < 0){
                break;
            }
            
            minus(pX, pY, xSize, ySize, &digit);
            Q_temp[len-i] = Q_temp[len-i] + 1;
            xSize = digit;
            
            if(xSize < ySize && *(pY+ySize-1) == 0){
                ySize = xSize;
            }
        }
        
        if(temp < 0){
            for(int32_t j=0 ; j<ySize-1 ; j++){
                *(pY+j) = *(pY+j+1);
            }
            
            *(pY+ySize-1) = 0;
            
            if(xSize < ySize){
                ySize = ySize - 1;
            }
        }
    }

    *pRemainderSize = xSize;
    memory_alloc(ppRemainder, *pRemainderSize);
    
    for(int32_t i=0 ; i<xSize ; i++){
        *(*ppRemainder+i) = *(pX+i);
    }

    change(*ppQuotient, *ppRemainder, *pQuotientSize, *pRemainderSize);
*/
    return;
}
 
void minus(uint8_t *x, uint8_t *y, uint8_t x_len, uint8_t y_len, uint8_t *digit){
    for(int32_t i=x_len-1 ; i>=0 ; i++){
        if(*(x+i) < *(y+i)){
            *(x+i) = *(x+i) + 10 - *(y+i);
            *(x+i-1) = *(x+i-1) - 1;
        }
        else{
            *(x+i) = *(x+i) - *(y+i);
        }
    }
    for(int32_t i=0 ; i<x_len-1 ; i++){
        if(*(x+i)){
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
        for(int32_t i=0 ; i<x_len-1 ; i++){
            if(*(x+i) == *(y+i)){//對應位的數相等
                continue;
            }
            else if(*(x+i) > *(y+i)){//被除數 大於 除數，返回值爲1
                return 1;
            }
            else if(*(x+i) < *(y+i)){//被除數 小於 除數，返回值爲-1
                return -1;
            }
        }
        
        return 0;//被除數 等於 除數，返回值爲0
    }

    return 1;
}



/*
#include<stdio.h>
#include<string.h>
 
char a[100],b[100];//用兩個字符串用來輸入兩個大數
 
int x[100],y[100],z[100],m[100];//被除數  除數  商  餘數
 
int digit;  //大數的位數
 
void sub(int x[],int y[],int len1,int len2)//大數減法
{
    int i;
    for(i=0;i<len1;i++)
    {
        if(x[i]<y[i])
        {
            x[i]=x[i]+10-y[i];
            x[i+1]--;
        }
        else
            x[i]=x[i]-y[i];
    }
    for(i=len1-1;i>=0;i--)//判斷減法結束之後，被除數的位數
    {
        if(x[i])
        {
            digit=i+1;
            break;
        }
    }
}
int judge(int x[],int y[],int len1,int len2)
{
    int i;
    if(len1<len2)
        return -1;
    if(len1==len2)//若兩個數位數相等
    {
        for(i=len1-1;i>=0;i--)
        {
            if(x[i]==y[i])//對應位的數相等
                continue;
            if(x[i]>y[i])//被除數 大於 除數，返回值爲1
                return 1;
            if(x[i]<y[i])//被除數 小於 除數，返回值爲-1
                return -1;
        }
        return 0;//被除數 等於 除數，返回值爲0
    }
}
int main()
{
    int i,j=0,k=0,temp;
    int len1,len2,len;//len兩個大數位數的差值
 
    while(~scanf("%s %s",a,b))
    {
        len1=strlen(a);//被除數位數
        len2=strlen(b);//除數位數
 
        for(i=len1-1,j=0;i>=0;i--)//將字符串中各個元素倒序儲存在數組中
        {
            x[j++]=a[i]-'0';
        }
        for(i=len2-1,k=0;i>=0;i--)
        {
            y[k++]=b[i]-'0';
        }
 
        if(len1<len2)//當被除數位數 小於 除數位數時
        {
            printf("商是：0\n");
            printf("餘數是：");
            puts(a);
        }
        else //當被除數位數 大於或者等於 除數位數時
        {
            len=len1-len2;//兩個大數位數的差值
            for(i=len1-1;i>=0;i--)//將除數後補零，使得兩個大數位數相同。
            {
 
                if(i>=len)
                    y[i]=y[i-len];
                else
                    y[i]=0;
               
            }
            len2=len1;//將兩個大數數位相同
 
            digit=len1; //將原被除數位數賦值給digit
 
            for(j=0;j<=len;j++)
            {
                z[len-j]=0;
 
                while(((temp=judge(x,y,len1,len2))>=0)&&digit>=k)//判斷兩個數的大小以及被除數位數與除數原位數的關係
                {
                    sub(x,y,len1,len2); //大數減法函數
 
                    z[len-j]++;//儲存商的每一位
 
                    len1=digit;//重新修改被除數的長度
 
                    if(len1<len2&&y[len2-1]==0)
                        len2=len1;  //將len1長度賦給len2;
                }
 
                if(temp<0)//若被除數 小於 除數，除數減小一位。
                {
                    for(i=1;i<len2;i++)
                        y[i-1]=y[i];
                    y[i-1]=0;
                    if(len1<len2)
                        len2--;
                }
            }
 
            printf("商是：");
            for(i=len;i>0;i--)//去掉前綴0
            {
                if(z[i])
                    break;
            }
            for(;i>=0;i--)
                printf("%d",z[i]);
            printf("\n");
 
            printf("餘數是：");
            for(i=len1;i>0;i--)
            {
                if(x[i])
                    break;
            }
            for(;i>=0;i--)
                printf("%d",x[i]);
            printf("\n");
        }
    }
    return 0;
}
*/
