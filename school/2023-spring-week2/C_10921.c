#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){
    char phone[50] = {0};
    
    while(scanf("%s", phone) != EOF){
        for(int32_t i=0 ; i<strlen(phone) ; i++){
            
            
            int32_t temp = phone[i] - 'A';
            
            if(0 <= temp && temp <= 2){
//                phone[i] = 2;
                printf("2");
            }
            else if(3 <= temp && temp <= 5){
        //        phone[i] = 3;
                printf("3");
            }
            else if(6 <= temp && temp <= 8){
        //        phone[i] = 4;
                printf("4");
            }
            else if(9 <= temp && temp <= 11){
        //        phone[i] = 5;
                printf("5");
            }
            else if(12 <= temp && temp <= 14){
      //          phone[i] = 6;
                printf("6");
            }
            else if(15 <= temp && temp <= 18){
    //            phone[i] = 7;
                printf("7");
            }
            else if(19 <= temp && temp <= 21){
  //              phone[i] = 8;
                printf("8");
            }
            else if(22 <= temp && temp <= 25){
//                phone[i] = 9;
                printf("9");
            }
            else if(phone[i] == '-'){
                printf("-");
            }
            else if(phone[i] == '0'){
                printf("0");
            }
            else if(phone[i] == '1'){
                printf("1");
            }
        }
        
        printf("\n");
        
 //       printf("%s\n", phone);
    }

    return 0;
}
