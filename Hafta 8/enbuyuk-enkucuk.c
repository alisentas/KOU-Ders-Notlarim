#include <stdio.h>
#include <stdlib.h>

int main()
{
    int adet, enb, enk, sayac, sayi;

    printf("Girilecek sayi adedi: "); scanf("%d", &adet);

    for(sayac = 1; sayac <= adet ; sayac++){
        printf("%d. sayiyi giriniz: ", sayac); scanf("%d", &sayi);
        if(sayi > enb)
            enb = sayi;
        else if(sayi < enk)
            enk = sayi;
    }

    printf("En buyuk sayi: %d\n", enb);
    printf("En kucuk sayi: %d\n\n", enk);
}
