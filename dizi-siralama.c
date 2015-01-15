#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ali SENTAS	2015

#define LIMIT 25 //Dizinin boyutu

int main(){
    int dizi[LIMIT], buffer, i, j;
    // buffer: for dongusunde yer degisimi icin dizinin o anki degeri
    srand(time(NULL));

    for(i = 0; i < LIMIT; i++){
        dizi[i] = rand() % 1000;
    }
    // rastgele sayilardan olusan bir dizi yaptık

    for(i = 0; i < LIMIT; i++){
        for(j = 0; j < LIMIT; j++){
            // Dizinin eleman sayisinin karesi kadar kere donguyu devam ettiriyoruz
            // Her defasında yaptigimiz islem i'nci terim ile i + 1'inci terimi karsilastirip
            //   eger ilk terim daha buyukse ikisinin yerini degistirmek
            if(dizi[j] > dizi[j+1]){
                buffer = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j + 1] = buffer;
            }
        }
    }

    for(i = 0; i < LIMIT; i++){
        // Diziyi yazdirma
        printf("%d\n", dizi[i]);
    }
    printf("\n\n");

    return 0;
}
