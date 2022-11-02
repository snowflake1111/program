#include <stdio.h>
#include <stdint.h>

int main(){
    uint16_t n = 0;
    double GL = 0;
    double NS = 3;
    double pi = 3.14159265358979323846;
    double GL_diff = 0;
    double NS_diff = 0;

    printf("Please enter n (16-bits unsigned): ");
    scanf("%hu", &n);

    for(int16_t i=1 ; i<=n ; i++){
        if(i % 2 == 1){
            GL = GL + (double) 4 / (2*i-1); 
        }
        else{
            GL = GL - (double) 4 / (2*i-1);
        }

        if(i % 2 == 1 && (2*i-2) != 0){
            NS = NS - (double) 4 / ((2*i-2)*(2*i-1)*(2*i));  
        }
        else if(i % 2 == 0 && (2*i-2) != 0){
            NS = NS + (double) 4 / ((2*i-2)*(2*i-1)*(2*i));
        }

        GL_diff = GL - pi;
        NS_diff = NS - pi;
        
        if(GL_diff < 0){
            GL_diff = -1 * GL_diff;
        }
        if(NS_diff < 0){
            NS_diff = -1 * NS_diff;
        }

        printf("n = %d:\n", i);
        printf("    Gregory - Leibniz series: %.6f (%.6f)\n", GL, GL_diff);
        printf("    Nilakantha series: %.6f (%.6f)\n", NS, NS_diff);
    }

    return 0;
}
