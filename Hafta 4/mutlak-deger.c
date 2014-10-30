#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sayi, m_deger;

    printf("Bir sayi girin: "); scanf("%f", &sayi);

    if(sayi > 0)
        printf("Mutlak deger = %f\n", sayi);
    else{
        m_deger = 0 - sayi;
        printf("Mutlak deger = %f\n", m_deger);
    }


    return 0;
}
