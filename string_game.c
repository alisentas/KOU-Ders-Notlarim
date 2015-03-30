#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alphabet = "abcdefghijklmnopqrstuvwxyz";

int getPos(char c){
    int i;
    for(i = 0; i < strlen(alphabet); i++){
        if(c == alphabet[i])
            break;
    }
    return i;
}

int main()
{
    char s1[50], s2[50];
    int i, step = 0;

    giris:
    printf("Herhangi bir kelime girin > ");
    fgets(s1, 50, stdin);
    printf("Donusturmek istediginiz kelimeyi girin (Uuzunluk ayni olmali) > ");
    fgets(s2, 50, stdin);

    if(strlen(s1) != strlen(s2)){
        printf("Uzunluklar ayni degil.\n\n");
        goto giris;
    }

    printf("Donusum uygulaniyor...\n\n\t%s", s1);

    for(i = 0; i < strlen(s1); i++){
        while(s1[i] != s2[i]){
            if(getPos(s1[i]) < getPos(s2[i])){
                s1[i]++;
            }else{
                s1[i]--;
            }
            step++;
            printf("%d:\t%s", i+1, s1);
        }
    }
    printf("\nDonusturulen kelime: %s", s1);
    printf("\n%d adimda cevrildi. \n\n", step);



    return 0;
}
