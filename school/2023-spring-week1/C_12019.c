#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int32_t n = 0;
    int32_t m = 0;
    int32_t d = 0;
    char week[][10] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    int32_t day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int32_t *state = NULL;

    scanf("%d", &n);
    
    state = (int*) calloc(sizeof( int32_t ), n);

    for(int32_t i=0 ; i<n ; i++){
        int32_t count = 0;

        scanf("%d %d", &m, &d);
        
        for(int32_t j=0 ; j<m ; j++){
            count = count + day[j];
        }

        state[i] = (count+d) % 7;
    }

    for(int32_t i=0 ; i<n ; i++){
        printf("%s\n", week[state[i]]);
    }
    
    free(state);

    return 0;
}
