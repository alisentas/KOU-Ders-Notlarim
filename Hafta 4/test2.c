#include <stdio.h>

int main()
{
    float sayi;

    float sonuc;

    printf("sayiyi giriniz: ");

    scanf("%f", &sayi);

    sonuc = sayi * 0.3;

    printf("sayinin yuzde otuzu: %f\n", sonuc);

    return 0;
}
