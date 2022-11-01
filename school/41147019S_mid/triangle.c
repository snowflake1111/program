#include <stdio.h>
#include <stdint.h>

double x_1 = 0;
double y_1 = 0;
double x_2 = 0;
double y_2 = 0;
double x_3 = 0;
double y_3 = 0;
double slope_12 = 0;
double slope_13 = 0;
double slope_23 = 0;

int set_point_1( double x, double y){
    x_1 = x;
    y_1 = y;
}

int set_point_2( double x, double y){
    x_2 = x;
    y_2 = y;
}

int set_point_3( double x, double y){
    x_3 = x;
    y_3 = y;
}

int check( void ){
    if((x_1 == x_2 && y_1 == y_2) || (x_2 == x_3 && y_2 == y_3) || (x_1 == x_3 && y_1 == y_3)){
        return 0;
    }
    if(x_1 != x_2 && x_1 != x_3 && x_2 != x_3){
        slope_12 = (y_1 - y_2) / (x_1 - x_2);
        slope_13 = (y_1 - y_3) / (x_1 - x_3);
        slope_23 = (y_2 - y_3) / (x_2 - x_3);    
    }
    else{
        
    }
}

double get_perimeter( void );

double get_degree_1( void );
double get_degree_2( void );
double get_degree_3( void );

double get_incircle_area( void );