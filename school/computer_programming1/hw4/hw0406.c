#include <stdio.h>

int p(int i, int N){
    return (i <= N && printf("%d ", i) && printf(" %d\n", N) && !p(i + 1, N-1));
}

int main(){
    int i = 0;
    int N = 0;

    while(1){
        scanf("%d", &i);
        scanf("%d", &N);

        p(i, N);
    }
}
