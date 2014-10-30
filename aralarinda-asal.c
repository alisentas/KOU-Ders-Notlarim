#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Aralarinda asal sayilari bulan program
// Ali SENTAS

int main()
{
    int sayi1, sayi2, i, asal;

    printf("Sayi 1 > ");
    scanf("%d", &sayi1);

    printf("Sayi 2 > ");
    scanf("%d", &sayi2);

    asal = 1;

	printf("\nOrtak bolenler: ");
    for(i = 2; i <= sayi1; i++){
		if(sayi1 % i == 0){
			if(sayi2 % i == 0 || sayi2 % (sayi1 / i) == 0){
				printf("%d, ", i);
				asal = 0;
			}
		}
    }

    if(asal){
		printf("\n\n%d ve %d sayilari aralarinda asal.\n\n", sayi1, sayi2);
    }else{
		printf("\n\n%d ve %d sayilari aralarinda asal degil.\n\n", sayi1, sayi2);
    }

    return 0;
}
