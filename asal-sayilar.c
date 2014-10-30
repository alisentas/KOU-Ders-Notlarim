#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Asal sayi bulmaya yarayan program
// Ali SENTAS

int main()
{
    int sayi, i, asalmi;
    /**
     * sayi = kullanicinin girecegi sayi
	 * i = dongude kullanacagimiz sayac
	 * asalmi = sayi asal ise 1, asal degilse 0, dogru yanlis gibi
	 */
    float kok; //sayinin koku tam sayi cikmayabilir o yuzden float

    printf("1'den buyuk bir tam sayi girin > ");
    scanf("%d", &sayi);
    printf("\n");

    kok = sqrt(sayi);
    asalmi = 1; //basta sayi asalmis gibi kabul edip dongude yanlislamaya calisacagiz
    // ornegin sayi asal degilse dongude bu asalmi degiskeni 0'a donusecek
    // asalsa 1 kalicak
    printf("Bolenler: ");
    for(i = 2; i < kok; i++){
		if(sayi % i == 0){
			printf("%d, %d", i, sayi / i); //i bolen oluyor, onu yazdir yani
			// (sayi / i) de bolen oluyor, mesela 15'in bolenleri 3 ve 5 gibisinden
			asalmi = 0; //sayinin boleni var, asal olamaz
		}
    }
    if(asalmi){
		printf("\n\nBu sayi asal..\n\n");
    }else{
		printf("\n\nDostum bu sayi asal degil, olamaz, imkansiz bir sey.\n\n");
    }

    return 0;
}
