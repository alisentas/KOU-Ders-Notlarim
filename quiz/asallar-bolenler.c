#include <stdio.h>
#include <stdlib.h>

// Bolen ve asal sayi bulma quizi
// Ali SENTAS

int main()
{
    int sayi, sayac, asalmi;
    asalmi = 1;
    sayac = 2;

    printf("Pozitif bir tam sayi girin > ");
    scanf("%d", &sayi);

    if(sayi < 2){
		printf("Hatali giris...");
    }else{
		printf("Bolenler: \n");
		while(sayac < sayi){
			if(sayi % sayac == 0){
				if(asalmi){
					asalmi = 0;
				}
				printf("%d\n", sayac);
			}
			sayac = sayac + 1;
		}

		if(asalmi){
			printf("\n\n%d sayisi asaldir.\n\n", sayi);
		}else{
			printf("\n\n%d sayisi asal degildir.\n\n", sayi);
		}
    }


    return 0;
}