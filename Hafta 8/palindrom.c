#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_pal(int num){
    // Finding the length of the number
    int len = 1, sayac;
    while((num % (int)pow(10, len) != 0) && (num >= (int)pow(10, len))){
        len++;
    }

    if(len == 1)
        return 1;

    //if(len % 2 == 0){
        for(sayac = 1; sayac <= len / 2; sayac++){
            if(num / (int)pow(10, sayac - 1) % 10 != ((num / (int)pow(10, len - sayac)) % (int)pow(10, sayac)) % 10){
                return 0;
            }
        }
    //}
    return 1;
}

int main()
{
    int sayi;

    while(1){
        printf("Sayi giriniz: "); scanf("%d", &sayi);
        if(is_pal(sayi))
            printf("Sayi palindromdur. \n\n");
        else
            printf("Sayi palindrom degildir. :( \n\n");
    }

    return 0;
}
