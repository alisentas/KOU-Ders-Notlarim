#include <stdio.h>
#include <stdlib.h>

// Kullanicinin girdigi sayi kadar uzunlukta bir uzgen cizen bir program
// Ali SENTAS - 2014

int main()
{
    int i, j, genislik, uzunluk, kalan;
	printf("Uzunluk degeri genislik degerinden buyuk fakat onun iki katindan kucuk olmali!\n");
	printf("Ucgenin genisligini girin: "); scanf("%d", &genislik);
	printf("Ucgenin uzunlugunu girin (Genislikten faazla olmali): "); scanf("%d", &uzunluk);

	for(i = 1; i <= genislik; i++){
		for(j = 1; j <= i; j++){
			//printf("i=%d, j=%d\n", i, j);
			printf("*");
		}
		printf("\n");
	}
	kalan = i - (uzunluk - genislik) - 1;
	for(i = genislik - 1; i >= kalan; i--){
		for(j = i; j >= 1; j--){
			//printf("i=%d, j=%d\n", i, j);
			printf("*");
		}
		printf("\n");
	}

    return 0;
}
