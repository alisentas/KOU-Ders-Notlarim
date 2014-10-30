#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi, kontrol, secim;
	kontrol = 1;

	while(kontrol){
		printf("Sayi giriniz: "); scanf("%d", &sayi);
		(sayi % 2 == 0) ? printf("Sayi cifttir.\n") : printf("Sayi tektir.\n");
		printf("Tekrar calissin mi? (1: evet, varsayilan: hayir)");
		scanf("%d", &secim);
		printf("\n");
		if(secim != 1){
			kontrol = 0;
		}
	}
	printf("\n");

    return 0;
}
