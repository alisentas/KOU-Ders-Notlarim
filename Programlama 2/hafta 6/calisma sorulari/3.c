#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char yazi[100], ns[2] = { '1', '\0'};
    int i, toplam = 0;
    printf("yazi girin: ");
    fgets(yazi, 100, stdin);

    for(i = 0; i < strlen(yazi); i++){
        if(isdigit(yazi[i])){
            ns[0] = yazi[i];
            toplam += atoi(ns);
        }
    }
    printf("rakamlari toplami: %d", toplam);
    return 0;
}
