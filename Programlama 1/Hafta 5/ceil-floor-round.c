#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sayi;

    printf("Sayi girin: ");
    scanf("%f", &sayi);
    printf("\n");

    printf("floor(%.3f) = %.3f\n", sayi, floor(sayi));
    printf("ceil(%.3f) = %.3f\n", sayi, ceil(sayi));
    printf("round(%.3f) = %.3f\n\n", sayi, round(sayi));

    return 0;
}
