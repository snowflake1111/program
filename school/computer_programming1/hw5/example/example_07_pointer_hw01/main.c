#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

void shuffle( int32_t [] );
void deal( int32_t [] );
void sort_array( int32_t [], size_t );

int main()
{
    int32_t cards[52] = {0};

    for( size_t i = 0 ; i < 52 ; i++ )
    {
        cards[i] = i;
    }

    shuffle( cards );
    deal( cards );

    return 0;
}

void shuffle( int32_t cards[] )
{
    srand( time( 0 ) );

    for( size_t i = 0 ; i < 10000 ; i++ )
    {
        int32_t c01 = rand() % 52;
        int32_t c02 = rand() % 52;

        int32_t tmp = cards[c01];
        cards[c01] = cards[c02];
        cards[c02] = tmp;
    }

    return;
}

void deal( int32_t cards[] )
{
    int32_t hands[13] = {0};

    for( size_t i = 0 ; i < 13 ; i++ )
    {
        hands[i] = cards[i];
    }

    sort_array( hands, 13 );

    int32_t suit = -1;
    int32_t hcp = 0;

    for( size_t i = 0 ; i < 13 ; i++ )
    {
        if( hands[i] / 13 > suit )
        {
            printf( "\n" );
            switch ( hands[i] / 13 )
            {
                case 0:
                    printf( "Spade:   " );
                    break;
                case 1:
                    printf( "Heart:   " );
                    break;
                case 2:
                    printf( "Diamond: " );
                    break;
                case 3:
                    printf( "Club:    " );
                    break;
                default:
                    break;
            }
            suit = hands[i] / 13;
        }

        if( hands[i] % 13 >= 10 )
        {
            hcp += hands[i] % 13 - 9;
            switch( hands[i] % 13 )
            {
                case 10:
                    printf( " J " );
                    break;
                case 11:
                    printf( " Q " );
                    break;
                case 12:
                    printf( " K " );
                    break;
                default:
                    break;
            }
        }
        else if( hands[i] % 13 == 0 )
        {
            hcp += 4;
            printf( " A " );
        }
        else
        {
            printf( "%2d ", hands[i] % 13 + 1 );
        }
    }

    printf( "\nHCP: %d points.\n", hcp );
    return;
}

void    sort_array( int32_t b[], size_t size )
{
    for( size_t i = 0 ; i < size ; i++ )
    {
        for( size_t j = i ; j < size ; j++ )
        {
            if( b[i] > b[j] )
            {
                int32_t tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
}
