#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char yazi[50];
    int karakterler[128] = {0};
    int i;
    printf("yazi girin: ");
    fgets(yazi, 50, stdin);

    for(i = 0; i < strlen(yazi) - 1; i++){
        karakterler[yazi[i]]++;
    }

    for(i = 0; i < 128; i++){
        if(karakterler[i] > 0){
            printf("%c: %d tane\n", i, karakterler[i]);
        }
    }

    return 0;
}
