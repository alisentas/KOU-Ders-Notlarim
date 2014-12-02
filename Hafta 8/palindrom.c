#include <stdio.h>
#include <stdlib.h>

int is_pal(int num){
    int uzunluk = 0, ilk = 0, son = 0, i, sayi = num, deger;
    while(sayi != 0){
        sayi /= 10;
        uzunluk++;
    }
    deger = 1;
    for(i = 1; i <= uzunluk / 2; i++){
        ilk += (num % 10) * deger;
        num /= 10;
        deger *= 10;
    }
    if(uzunluk % 2 != 0){
        num /= 10;
    }
    deger /= 10;
    for(i = 1; i <= uzunluk / 2; i++){
        son += (num % 10) * deger;
        num /= 10;
        deger /= 10;
    }
    return ilk == son;
}

int main()
{
    int sayi;

    while(1){
        printf("Sayi giriniz: "); scanf("%d", &sayi);
        if(is_pal(sayi))
            printf("Sayi palindrom...\n\n");
        else
            printf("Sayi palindrom degil. :(\n\n");
    }

    return 0;
}
