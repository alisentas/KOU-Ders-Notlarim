#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c, ortalama;

    printf("Birinci Sayi: "); scanf("%f", &a);
    printf("Ikinci Sayi: "); scanf("%f", &b);
    printf("Ucuncu Sayi: "); scanf("%f", &c);

    ortalama = (a + b + c) / 3;

    printf("Sonuc: %f\n", ortalama);

    return 0;
}
