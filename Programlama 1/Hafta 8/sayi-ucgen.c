#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayac = 1, i, j, satir;

    printf("Satir sayisini giriniz: "); scanf("%d", &satir);

    for(i = 1; i <= satir; i++){
        for(j = 1; j <= i; j++){
            printf("%d ", sayac);
            sayac++;
        }
        printf("\n");
    }
}
