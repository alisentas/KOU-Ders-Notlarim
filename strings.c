#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int karakter_sayisi(const char *s){
    int i = 0;
    while(s[i] != '\0') i++;
    return i;
}

int karakter_say(const char *s, char c){
    int tane = 0, i = 0;
    while(s[i] != '\0'){
        if(s[i] == c)
            tane++;
        i++;
    }
    return tane;
}

int string_arama(const char *s, const char *k){
    int i, j, is, js;
    is = karakter_sayisi(s);
    js = karakter_sayisi(k);

    printf("is: %d, js: %d\n", is, js);

    for(i = 0; i < is - js; i++){
        for(j = 0; j < js; j++)
            if(s[i+j] != k[j]) break;

        if(j == js)
            return i;
    }

    return -1;
}

int main()
{
    char ad[20];

    printf("İsmi girin > ");
    scanf("%s", ad);

    char soyad[] = "Sentas";
    const char *ders = "programlama";

    printf("%s %s, %s dersine giriyor.\n\n", ad, soyad, ders);

    int k1 = karakter_sayisi(ad);
    int k2 = karakter_sayisi(soyad);
    int k3 = karakter_sayisi(ders);

    printf("%s: %d, %s: %d, %s: %d\n\n", ad, k1, soyad, k2, ders, k3);

    printf("karakter_say(\"programlama\", a): %d\n\n", karakter_say(ders, 'a'));

    printf("string_arama(\"programlama\", \"ram\"): %d\n\n", string_arama(ders, "ram"));

    char k;
    printf("Bir karakter girin > ");
    scanf(" %c", &k);

    if(isalpha(k)){
        printf("%c bir harf.\n", k);
        if(isupper(k)){
            printf("%c buyuk harf.\n\n", k);
        }else if(islower(k)){
            printf("%c kucuk harf.\n\n", k);
        }
    }else if(isdigit(k)){
        printf("%c bir sayi.\n\n", k);
    }else if(ispunct(k)){
        printf("%c bir noktalama isareti.\n\n", k);
    }

    return 0;
}
