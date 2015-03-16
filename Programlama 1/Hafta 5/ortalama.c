#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi, devam_et, adet, toplam;
    float ortalama;
    devam_et = 1; //kullanici deam etmek istiyor mu?
    adet = 0; //girilen sayi adedi
    toplam = 0; //girilen sayiların toplami

    printf("Sayi giriniz : ");
    scanf("%d", &sayi);
    toplam += sayi;
    adet += 1;
    printf("\n");

    while(devam_et){
		printf("Sayi giriniz (sonlandirmak icin -1) : ");
		scanf("%d", &sayi);
		printf("\n");
		if(sayi != -1){
			toplam += sayi;
			adet += 1;
		}else{
			devam_et = 0;
		}
    }
    ortalama = toplam / adet;
    printf("Ortalama: %.2f\n\n", ortalama);

    return 0;
}
