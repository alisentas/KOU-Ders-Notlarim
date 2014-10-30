#include <stdio.h>
#include <math.h>

int main()
{
	//secimi int yaptim cunku yalnizca 1, 2 ve ya 3 degerini tutuyor
	//sonucu float yapmak zorundasiniz cunku karekok ondalikli sayi cikabiliyor
	int secim;
	float sayi, sonuc;

	//Kullanicidan istenilen bilgileri al
    printf("Sayi giriniz: "); 	scanf("%f", &sayi);
    printf("Islem: "); 			scanf("%d", &secim);

	/*	secim	islem
		1			karekok
		2			kare
		3			mutlak deger
	*/
    switch(secim){
		case 1: {
				sonuc = sqrt(sayi);
				printf("Sonuc: %.5f\n", sonuc);
				break;
		}
		case 2: {
				sonuc = pow(sayi, 2);
				printf("Sonuc: %.2f\n", sonuc);
				break;
		}
		case 3: {
				//fabs kullandim cunku sayi float
				sonuc = fabs(sayi);
				printf("Sonuc: %.2f\n", sonuc);
				break;
		}
		default: {
			printf("Yanlis secim.\n");
		}
    }


    return 0;
}
