#include <stdio.h>
#include <stdlib.h>

void fib_yaz(int N){
    int onceki = 1, ondan_onceki = 0, toplam;

    if(N == 1){
        printf("0");
    }else{
        printf("0 1 ");
        for(; N >= 3; N--){
            toplam = onceki + ondan_onceki;
            printf("%d ", toplam);
            ondan_onceki = onceki;
            onceki = toplam;
        }
    }
}

int main()
{
    int N;

    while(1){
        printf("N?: "); scanf("%d", &N);
        fib_yaz(N);
        printf("\n\n");
    }

    return 0;
}
