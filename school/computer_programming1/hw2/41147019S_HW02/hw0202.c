#include <stdio.h>
#include <stdint.h>

int main(){
    int64_t start_day = 0;
    int64_t start_month = 0;
    int64_t start_year = 0;
    int64_t end_day = 0;
    int64_t end_month = 0;
    int64_t end_year = 0;
    int64_t month = 0;
    int64_t day = 0;
    
    printf("Start Date: ");
    scanf("%lld-%lld-%lld", &start_month, &start_day, &start_year);

    printf("End Date: ");
    scanf("%lld-%lld-%lld", &end_month, &end_day, &end_year);
    
    if(start_month == 4 || start_month == 6 || start_month == 9 || start_month == 11){
        if(start_day < 1 || start_day > 30){
            printf("Error\n");
            return 0;
        }
    }
    else if(start_month == 1 || start_month == 3 || start_month == 5 || start_month == 7 || start_month == 8 || start_month == 10 || start_month == 12){
        if(start_day < 1 || start_day > 31){
            printf("Error\n");
            return 0;
        }
    }
    else if(start_month == 2){
        if((start_year % 4 == 0 && start_year % 100 == 0 && start_year % 400 == 0) || (start_year % 4 == 0 && start_year % 100 != 0 && start_year % 400 != 0)){
            if(start_day < 1 || start_day > 29){
                printf("Error\n");
                return 0;
            }
        }    
        else{
            if(start_day < 1 || start_day > 28){
                printf("Error\n");
                return 0;
            }    
        }     
    }

    if(end_month == 4 || end_month == 6 || end_month == 9 || end_month == 11){
        if(end_day < 1 || end_day > 30){
            printf("Error\n");
            return 0;
        }
    }
    else if(end_month == 1 || end_month == 3 || end_month == 5 || end_month == 7 || end_month == 8 || end_month == 10 || end_month == 12){
        if(end_day < 1 || end_day > 31){
            printf("Error\n");
            return 0;
        }
    }
    else if(end_month == 2){
        if((end_year % 4 == 0 && end_year % 100 == 0 && end_year % 400 == 0) || (end_year % 4 == 0 && end_year % 100 != 0 && end_year % 400 != 0)){
            if(end_day < 1 || end_day > 29){
                printf("Error\n");
                return 0;
            }
        }    
        else{
            if(end_day < 1 || end_day > 28){
                printf("Error\n");
                return 0;
            }    
        }     
    }

    if(start_year > end_year || 
        (start_year == end_year && start_month > end_month) || 
          (start_year == end_year && start_month == end_month && start_day > end_day)){
        printf("Error\n");
        return 0;
    }


    for(int64_t i=start_year; i<=end_year ; i++){
        month = (i % 10) * 10 + i / 10 % 10;
        day = ((i / 100) % 10) * 10 + i / 1000; 
        
        if(i == start_year){
            if(month < start_month || (month == start_month && day < start_day)){
                continue;
            }
        }
        else if(i == end_year){
            if(month > end_month || (month == end_month && day > end_day)){
                continue;
            }
        }

        if(month == 4 || month == 6 || month == 9 || month == 11){
            if(day >= 1 && day <= 30){
                printf("%02lld-%02lld-%04lld\n", month, day, i);
            }
        }
        else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            if(day >= 1 && day <= 31){
                printf("%02lld-%02lld-%04lld\n", month, day, i);
            }
        }
        else if(month == 2){
            if((i % 4 == 0 && i % 100 == 0 && i % 400 == 0) || (i % 4 == 0 && i % 100 != 0 && i % 400 != 0)){
                if(day >= 1 && day <= 29){
                    printf("%02lld-%02lld-%04lld\n", month, day, i);
                }
            }    
            else{
                if(day >= 1 && day <= 28){
                    printf("%02lld-%02lld-%04lld\n", month, day, i);
                }    
            }     
        }
    }

    return 0;
}