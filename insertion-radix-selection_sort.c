#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void insertion(int iSort[100], int len);
void radix(int rSort[100], int len);
void selection(int sSort[100], int len);

int main(){
    int sort[100]; //siralanacak liste
    int len;
    int randNum, i, secim;
    printf("Dizi kac elemanli olacak? (En fazla 100) > ");
    scanf("%d", &len);
    printf("%d elemanli rastgele liste olusturuluyor...\n\n", len);
    // Rastgele liste oluşturma
    // Switch ile diziye rastgele 1, 2 3 ya da 4 basamakli sayilar ekleniyor.
    srand(time(NULL));
    for(i = 0; i < len; i++){
        randNum = rand() % 4 + 1;
        switch(randNum){
            case 1:
                sort[i] = rand() % 10;
                break;
            case 2:
                sort[i] = rand() % 100;
                break;
            case 3:
                sort[i] = rand() % 1000;
                break;
            case 4:
                sort[i] = rand() % 10000;
                break;
        }
    }
    // Sirali olmayan listeyi yazdir
    printf("Siralanmamis:\t");
    for(i = 0; i < len; i++){
        printf("%d, ", sort[i]);
    }

    printf("\n\nInsertion sort icin 1, radix sort icin 2, selection sort icin 3 giriniz > ");
    scanf("%d", &secim);
    if(secim == 1){
        printf("Insertion sort kullanilacak..\n\n");
        insertion(sort, len);
    }else if(secim == 2){
        printf("Radix sort kullanilacak..\n\n");
        radix(sort, len);
    }else if(secim == 3){
        printf("Selection sort kullanilacak..\n\n");
        selection(sort, len);
    }

    return 0;
}

void insertion(int iSort[100],int len){
    /**
    *  Insertion Sort
    *   Algoritmanin mantigi dizideki her sayiyi ait oldugu
    *   yeri bulana kadar basa dogru kaydirmak
    */
    // Siralama kismi
    int i, j, temp;
    for(i = 1; i < len; i++){
        j = i;
        while(iSort[j] < iSort[j-1] && j > 0){
            temp = iSort[j-1];
            iSort[j-1] = iSort[j];
            iSort[j] = temp;
            j--;
        }
    }
    // Yazdirma kismi
    printf("Insertion sort:\t ");
    for(i = 0; i < len; i++){
        printf("%d, ", iSort[i]);
    }
    printf("\n\n");
}

void radix(int rSort[100], int len){
    /**
    *  Radix sort
    *   Algoritmanin mantigi sayilari basamak degerlerine gore
    *   siralamak. Ilk once birler basamagina gore, sonra onlar, yuzler...
    */
    int i, j, num, digit, digitMax = 0, digitNow, temp, a, b;
    // Dizideki en buyuk elemanin kac basamakli oldugunu bulma
    for(i = 0; i < len; i++){
        digitNow = 0;
        num = rSort[i];
        while(num > 0){
            digitNow += 1;
            num /= 10;
        }
        if(digitNow > digitMax)
            digitMax = digitNow;
    }
    // Siralama kismi
    for(digit = 1; digit <= digitMax + 1; digit++){
        for(i = 0; i < len; i++){
            for(j = 1; j < len - i; j++){
                a = (int)(rSort[j]/pow(10, digit - 1)) % 10; // sayinin o anki basamak degeri
                b = (int)(rSort[j-1]/pow(10, digit - 1)) % 10; // bir oncekinin basamak degeri
                if(a < b){
                    // yer degisimi
                    temp = rSort[j-1];
                    rSort[j-1] = rSort[j];
                    rSort[j] = temp;
                }
            }
        }
    }
    // Siralaman elementleri yazdir
    printf("Radix sort:\t ");
    for(i = 0; i < len; i++){
        printf("%d, ", rSort[i]);
    }
    printf("\n\n");
}

void selection(int sSort[100], int len){
    int i, j, minIndex, temp, smallest;
    for(i = 0; i < len; i++){
        smallest = sSort[i];
        minIndex = i;
        for(j = i + 1; j < len; j++){
            if(sSort[j] < smallest){
                smallest = sSort[j];
                minIndex = j;
            }
        }
        if(minIndex > i){
            sSort[minIndex] = sSort[i];
            sSort[i] = smallest;
        }
    }

    printf("Selection sort:\t ");
    for(i = 0; i < len; i++){
        printf("%d, ", sSort[i]);
    }
    printf("\n\n");
}
