#include <stdio.h>
#include <stdint.h>

void first_line(int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2);
int upper_part(int64_t i, int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2);
int middle_line(int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2);
int lower_part(int64_t i, int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2);
void last_line(int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2);

int main(){
    int64_t length = 0;
    int64_t width = 0;
    int64_t height = 0;
    int64_t amount = 0;
    int64_t count = 0;
    int64_t count2 = 0;
    int64_t num = 80;
    int64_t count3 = 0;
    
    printf("Welcome to Cuboid Super Infinity Exporter!\n");
    printf("Please enter Length, Width, and Height of the cuboid\n");
    
    printf("Length: ");
    scanf("%lld", &length);
    
    printf("Width: ");
    scanf("%lld", &width);
    
    printf("Height: ");
    scanf("%lld", &height);

    printf("How many cuboids do you want to generate?\n");
    printf("Amount: ");
    scanf("%lld", &amount);

    if((width + length * 2 -1) > 80){
        printf("Error");  
        return 0;
    }

    if(length < 4 || width < 4 || height < 4 || amount < 0){
        printf("Error");  
        return 0;
    }
    
    if((81 % (width + 2 * length)) == 0){
        count3 = 80 / (width + 2 * length) + 1;
    }
    else{
        count3 = 80 / (width + 2 * length);
    }
    
    for(int64_t n=amount ; n>=count3 ; n=n-count3){  
        amount = amount - count3;

        for(int64_t i=0 ; i<count3 ; i++){
            first_line(length, width, height, amount, count, count2);

            if(i < count3 - 1){
                printf(" ");
            }
        }

        printf("\n");

        for(int64_t i=0 ; i<(width-2) ; i++){
            for(int64_t j=0 ; j<count3 ; j++){
                if(j < count3 - 1){
                    upper_part(i, length, width, height, amount, count, count2);
                    printf(" ");
                }
                else{
                    count2 = upper_part(i, length, width, height, amount, count, count2);
                }
            } 
            if(i != (width-2) - 1){
                printf("\n");
            }
        }            

        printf("\n");

        for(int64_t i=0 ; i<count3 ; i++){
            if(i < count3 - 1){
                middle_line(length, width, height, amount, count, count2);
                printf(" ");
            }
            else{
                count2 = middle_line(length, width, height, amount, count, count2);
            }
        }      
      
        printf("\n");   

        for(int64_t i=0 ; i<(height-2) ; i++){    
            for(int64_t j=0 ; j<count3 ; j++){     
                if(j < count3 - 1){
                    lower_part(i, length, width, height, amount, count, count2);
                    printf(" ");
                }
                else{
                    count2 = lower_part(i, length, width, height, amount, count, count2);
                }
            } 

            if(i != (height-2) - 1){
                printf("\n");
            }    
        }
        
        printf("\n");

        for(int64_t i=0 ; i<count3 ; i++){
            last_line(length, width, height, amount, count, count2);
            if(i < count3 - 1){
                printf(" ");
            }
        }
        if(n > count3){
            printf("\n\n");
        }

        count2 = 0;   
    }

    if(amount != 0){  
        for(int64_t i=0 ; i<amount ; i++){
            first_line(length, width, height, amount, count, count2);

            if(i < amount - 1){
                printf(" ");
            }
        }

        printf("\n");

        for(int64_t i=0 ; i<(width-2) ; i++){
            for(int64_t j=0 ; j<amount ; j++){
                if(j < amount - 1){
                    upper_part(i, length, width, height, amount, count, count2);
                    printf(" ");
                }   
                else{
                    count2 = upper_part(i, length, width, height, amount, count, count2);
                }
            }
            if(i != (width-2) - 1){
                printf("\n");
            }
        }

        printf("\n");

        for(int64_t i=0 ; i<amount ; i++){
            if(i < amount - 1){
                middle_line(length, width, height, amount, count, count2);
                printf(" ");
            }
            else{
                count2 = middle_line(length, width, height, amount, count, count2);
            }
        }
        
        printf("\n");   

        for(int64_t i=0 ; i<(height-2) ; i++){    
            for(int64_t j=0 ; j<amount ; j++){     
                if(j < amount - 1){
                    lower_part(i, length, width, height, amount, count, count2);
                    printf(" ");
                }
                else{
                    count2 = lower_part(i, length, width, height, amount, count, count2);
                }
            } 

            if(i != (height-2) - 1){
                printf("\n");
            }   
        }
        
        printf("\n");

        for(int64_t i=0 ; i<amount ; i++){
            last_line(length, width, height, amount, count, count2);
   
            if(i < amount - 1){
                printf(" ");
            }
        }  
    }
    printf("\n");

    return 0;
}

void first_line(int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2){
    for(int64_t j=0 ; j<(width - 1) ; j++){
        printf(" ");
    }

    for(int64_t j=0 ; j<(2 * length) ; j++){
        printf("#");
    }

    return;
}

int upper_part(int64_t i, int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2){
    for(int64_t k=0 ; k<(width - 2 - i) ; k++){
        printf(" ");
        count = count + 1;
    }

    printf("#");
    count = count + 1;
        
    for(int64_t k=0 ; k<(length*2-2) ; k++){
        printf("\033[47m \033[0m");
        count = count + 1;
    }
        
    printf("#");
    count = count + 1;

    if((i+2) <= height){
        while(count < (width + 2 * length - 2)){
            printf("\033[46m \033[0m");
            count = count + 1;
        }

        printf("#");
    }
    else{
        count2 = count2 + 1;

        while(count < (width + 2 * length - 2 - count2)){
            printf("\033[46m \033[0m");
            count = count + 1;
        }

        printf("#");

        for(int64_t k=0 ; k<count2 ; k++){
            printf(" ");
        }
    }
    count = 0;

    return count2;
}

int middle_line(int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2){
    for(int64_t j=0 ; j<(2 * length) ; j++){
        printf("#");
        count = count + 1;
    }

    if(width <= height){
        while(count < (width + 2 * length - 2)){
            printf("\033[46m \033[0m");
            count = count + 1;
        }

        printf("#");
    }
    else{
        count2 = count2 + 1;

        while(count < (width + 2 * length - 2 - count2)){
            printf("\033[46m \033[0m");
            count = count + 1;
        }

        printf("#");

        for(int64_t k=0 ; k<count2 ; k++){
            printf(" ");
        }
    }

    count = 0;

    return count2;
}

int lower_part(int64_t i, int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2){
    printf("#");
    count = count + 1;

    for(int64_t k=0 ; k<(length*2-2) ; k++){
        printf("\033[43m \033[0m");
        count = count + 1;
    }

    printf("#");
    count = count + 1;


    if((i+width+1) <= height){
        while(count < (width + 2 * length - 2)){
            printf("\033[46m \033[0m");
            count = count + 1;
        }

        printf("#");
    }
    else{
        count2 = count2 + 1;

        while(count < (width + 2 * length - 2 - count2)){
            printf("\033[46m \033[0m");
            count = count + 1;
        }

        printf("#");

        for(int64_t k=0 ; k<count2 ; k++){
            printf(" ");
        }
    }

    count = 0;
    
    return count2;
}

void last_line(int64_t length, int64_t width, int64_t height, int64_t amount, int64_t count, int64_t count2){
    for(int64_t j=0 ; j<(2 * length) ; j++){
        printf("#");
        count = count + 1;
    }

    for(int64_t j=count ; j<(width + 2 * length - 1) ; j++){
        printf(" ");
    }

    return;
}
