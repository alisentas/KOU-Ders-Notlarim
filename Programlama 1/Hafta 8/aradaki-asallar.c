#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int num){
    if(num < 2) return 0;
    if(num == 2) return 1;
    if(num % 2 == 0) return 0;

    int sroot = (int)sqrt(num), sayac = 3;

    for(; sayac <= sroot; sayac += 2)
        if(num % sayac == 0)
            return 0;

    return 1;
}

int main()
{
    int sayi1, sayi2, i;

    while(1){
        printf("Sayi 1?: "); scanf("%d", &sayi1);
        printf("Sayi 2?: "); scanf("%d", &sayi2);

        for(i = sayi1; i <= sayi2; i++){
            if(is_prime(i))
                printf("%d ", i);
        }
        printf("\n\n");
    }

    return 0;
}
