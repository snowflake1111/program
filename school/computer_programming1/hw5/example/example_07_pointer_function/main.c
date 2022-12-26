#include <stdio.h>
#include <stdint.h>
#include <math.h>

void curve( double * );

int main()
{
    double  score = 60.0;

    printf("Before: %f\n", score );
    curve( &score );
    printf("After : %f\n", score );

    return 0;
}

void curve( double *score )
{
    *score = sqrt( *score ) * 10.0;
    return;
}
