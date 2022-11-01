#include <stdio.h>
#include <stdint.h>
#include <math.h>

void money(double money);

int main(){
    int64_t year = 0;
    int64_t month = 0;
    int64_t loan_price = 0;
    int64_t loan_term = 0;
    int64_t interest_rate = 0;
    int64_t property_tax = 0;
    int64_t insurance = 0;
    int64_t additional_payment = 0;
    int64_t month_payment = 0;
    double month_principal = 0;
    double month_interest_rate = 0;
    double month_interest = 0;
    double remaining = 0;
    int64_t principal_and_interest = 0;

    printf("Loan Date: ");
    scanf("%lld.%lld", &year, &month);

    printf("Loan Price: ");
    scanf("%lld", &loan_price);

    printf("Loan Term (yrs): ");
    scanf("%lld", &loan_term);

    printf("Interest Rate (%%): ");
    scanf("%lld", &interest_rate);

    printf("Property Tax (/m): ");
    scanf("%lld", &property_tax);

    printf("Insurance (/m): ");
    scanf("%lld", &insurance);

    printf("Additional Payment (/m): ");
    scanf("%lld", &additional_payment);
    
    if(year < 0 || month < 1 || month > 12 || loan_price < 0 || interest_rate < 0 || interest_rate > 99 || property_tax < 0 || insurance < 0 || additional_payment < 0){
        printf("Error");
        return 0;
    }
    
    if(loan_term != 10 && loan_term != 15 && loan_term != 20 && loan_term != 30){
        printf("Error");
        return 0;
    }

    remaining = loan_price;
    month_interest_rate = (double) interest_rate / 1200;
    principal_and_interest = (int64_t) ((loan_price * month_interest_rate * pow((1 + month_interest_rate), loan_term*12)) / (pow((1 + month_interest_rate), loan_term*12) - 1));  
    month_interest = (double) ((int64_t) ((loan_price * month_interest_rate) * 100 + 0.5)) / 100;
    month_principal = (double) ((int64_t) ((principal_and_interest - month_interest) * 100 + 0.5)) / 100 + additional_payment;
    month_payment = principal_and_interest + property_tax + insurance + additional_payment;

    printf("--- Output ---\n");
    printf("Total monthly payment: %lld\n", month_payment);

    for(int64_t i=0 ; i<(loan_term * 12 - 1) ; i++){
        if(month == 12){
            month = 1;
            year = year + 1;
        }
        else{
            month = month + 1;
        }

        month_interest = (double) ((int64_t) ((remaining * month_interest_rate) * 100 + 0.5)) / 100;
        month_principal = (double) ((int64_t) ((principal_and_interest - month_interest) * 100 + 0.5)) / 100 + additional_payment;
   
        if(remaining - month_principal > 0){
            remaining = (double) ((int64_t) ((remaining - month_principal) * 100 + 0.5)) / 100;

            printf("%lld.%02lld) Principal: $", year, month);
            money(month_principal);
            printf(", Interest: $");
            money(month_interest);
            printf(", Remaining: $");
            money(remaining);
            printf("\n");
        }
        else{
            month_principal = remaining;
            remaining = 0;
            
            printf("%lld.%02lld) Principal: $", year, month);
            money(month_principal);
            printf(", Interest: $");
            money(month_interest);
            printf(", Remaining: $");
            money(remaining);
            printf("\n");

            return 0;
        }
    }
    
    if(month == 12){
        month = 1;
        year = year + 1;
    }
    else{
        month = month + 1;
    }

    month_interest = (double) ((int64_t) ((remaining * month_interest_rate) * 100 + 0.5)) / 100;
    month_principal = remaining;
    remaining = 0;
    
    printf("%lld.%02lld) Principal: $", year, month);
    money(month_principal);
    printf(", Interest: $");
    money(month_interest);
    printf(", Remaining: $");
    money(remaining);
    printf("\n");
    
    return 0;
}

void money(double money){
    int64_t count = 0;
    int64_t temp1 = (int64_t) money / 1;
    int64_t temp2 = (int64_t) (money * 100 + 0.5) % 100;
    
    for(int64_t j=temp1 ; j>=1000 ; j=j/1000){
        count = count + 1;
    }
    
    if(count != 0){
        printf("%lld", temp1 / (int64_t) pow(1000, count));
        printf(",");
    }
    
    for(int64_t j=1 ; j<count ; j++){
        printf("%03lld", (temp1 / (int64_t) pow(1000, (count - j))) % 1000);
        printf(",");
    }

    if(count != 0){
        printf("%03lld", temp1 % 1000);
        printf(".");
        printf("%02lld", temp2);
    }
    else{
        printf("%lld", temp1 % 1000);
        printf(".");
        printf("%02lld", temp2);
    }

    return;
}



