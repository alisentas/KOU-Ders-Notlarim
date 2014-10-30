#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi;

    printf("Sayi giriniz: "); scanf("%d", &sayi);

    if (sayi % 2 == 0)
        printf("%d cift sayidir.\n", sayi);
    else
        printf("%d tek sayidir.\n", sayi);

    return 0;
}
