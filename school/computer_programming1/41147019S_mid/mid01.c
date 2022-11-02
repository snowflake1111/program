#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    double p1_x = 0;
    double p2_x = 0;
    double p3_x = 0;
    double p4_x = 0;
    double p_x = 0;
    double p1_y = 0;
    double p2_y = 0;
    double p3_y = 0;
    double p4_y = 0;
    double p_y = 0;
    double a = 0;
    double b = 0;
    double m_x = 0;
    double m_y = 0;

    printf("P1(x,y): ");
    scanf("%lf,%lf", &p1_x, &p1_y);
    
    printf("P2(x,y): ");
    scanf("%lf,%lf", &p2_x, &p2_y);

    printf("P3(x,y): ");
    scanf("%lf,%lf", &p3_x, &p3_y);

    printf("P4(x,y): ");
    scanf("%lf,%lf", &p4_x, &p4_y);

    printf("P1(x,y): ");
    scanf("%lf,%lf", &p_x, &p_y);

    if(((p1_x == p2_x) && (p1_y == p2_y)) || ((p1_x == p3_x) && (p1_y == p3_y)) || ((p1_x == p4_x) && (p1_y == p4_y)) ||
           ((p2_x == p3_x) && (p2_y == p3_y)) || ((p2_x == p4_x) && (p2_y == p4_y)) || ((p3_x == p4_x) && (p3_y == p4_y))){
        printf("Error");
        return 0;
    }
    
    if(((p1_x - p2_x) != (p4_x - p3_x)) || ((p1_y - p2_y) != (p4_y - p3_y)) ||
           ((p1_x - p4_x) != (p2_x - p3_x)) || ((p1_y - p4_y) != (p2_y - p3_y))){
        printf("Error");
        return 0;
    }

    m_x = (p1_x + p3_x) / 2;
    m_y = (p1_y + p3_y) / 2;
    
    if(p_x == m_x){
        printf("Line: x = %.2f\n", p_x);
    }
    else{
        a = (p_y - m_y) / (p_x - m_x);
        b = p_y - a * p_x;   

        if(b >= 0){
            printf("Line: y = %.2f * x + %.2f\n", a, b);
        }
        else{
            printf("Line: y = %.2f * x - %.2f\n", a, -1*b);
        }
    }

    return 0;
}