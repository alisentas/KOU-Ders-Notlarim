#include <stdio.h>
#include <stdlib.h>

void selection(int sSort[1000], int len){
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
}

/**
* Ikili arama algoritmasiyla eleman bulma
* @dizi : arama yapilacak dizi
* @N    : dizinin uzunlugu
* @ara  : aranacak eleman
*/
int ikiliarama(int dizi[1000], int N, int ara){
    int bas = 0;
    int son = N-1;
    int orta;

    while(bas <= son){
        orta = (son + bas) / 2;
        if(dizi[orta] == ara){
            return orta;
        }else if(dizi[orta] > ara){
            son = orta-1;
        }else{
            bas = orta+1;
        }
    }

    return -1;
}

int main()
{
    int d[1000], i, N, sonuc;

    printf("Dizi kac elemanli olacak > ");
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        printf("%d. eleman > ", (i + 1));
        scanf("%d", &d[i]);
    }

    printf("Aranacak elemani girin > ");
    scanf("%d", &i);

    selection(d, N);

    sonuc = ikiliarama(d, N, i);

    if(sonuc == -1){
        printf("Aradiginiz eleman dizide bulunamadi.\n");
    }else{
        printf("Aradiginiz elemannin indexi: %d\n.", sonuc);
    }

    return 0;
}
