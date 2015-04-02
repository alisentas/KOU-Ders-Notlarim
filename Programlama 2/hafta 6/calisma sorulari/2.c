#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char kelime[50];
    char ek[10];

    printf("kelime girin: "); fgets(kelime, 50, stdin);
    printf("kontrol edilecek eki girin: "); fgets(ek, 10, stdin);

    int onek = 1, sonek = 1, i;

    for(i = 0; i < strlen(ek) - 1; i++){
        if(kelime[i] != ek[i])
            onek = 0;
    }

    for(i = 0; i < strlen(ek); i++){
        if(kelime[strlen(kelime) - 1 - i] != ek[strlen(ek) - 1 - i])
            sonek = 0;
    }

    if(onek)
        printf("on ektir\n");
    if(sonek)
        printf("son ektir\n\n");

    return 0;
}
