#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ilkNufus = 106000;
    int suankiNufus = ilkNufus;
    int istenilenNufus = 190000;
    int artisYuzdesi = 2;
    int yillar = 0;

    do{
        suankiNufus += (suankiNufus) * (artisYuzdesi) / 100;
        yillar++;
    }while(suankiNufus < istenilenNufus);

    printf("%d nufusunun, %%%d artis yuzdesiyle, %d sayisini gormesi %d yil alir.\n\n", suankiNufus, artisYuzdesi, istenilenNufus, yillar);
}
