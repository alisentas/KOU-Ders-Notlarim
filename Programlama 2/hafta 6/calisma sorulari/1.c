#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cumle[100];
    char karakter;
    int i, bharf = 0, kharf = 0, rakam = 0, bosluk = 0;
    printf("yazi girin: ");
    fgets(cumle, 100, stdin);

    for(i = 0; i < strlen(cumle); i++){
        karakter = cumle[i];
        if(isalpha(karakter)){
            if(isupper(karakter))
                bharf++;
            else
                kharf++;
        }else if(isdigit(karakter))
            rakam++;
        else if(isblank(karakter))
            bosluk++;
    }
    printf("kucuk harf sayisi: %d\nbuyuk harf sayisi: %d\nrakam sayisi: %d\nbosluk sayisi: %d", kharf, bharf, rakam, bosluk);
    return 0;
}
