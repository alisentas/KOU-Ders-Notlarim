#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
    // f(x) = x^3 - 4x^2 + 22x - 5
    return (x*x*x) - 4*(x*x) + 22*x - 5;
}

int main()
{
    int bolunme = 1000000; //Bolunme ne kadar cok olursa o kadar net sonuc verir
    int ilkdeger = -100, sondeger = +100; //hangi degerden hangi degere
    float alan = 0;

    float aralik = fabs((float)(ilkdeger - sondeger) / bolunme);
    float parametre = ilkdeger;
    float anlikDeger;

    for(; bolunme >= 0; bolunme--){
        anlikDeger = f(parametre);
        alan += fabs(anlikDeger * aralik);
        parametre += aralik;
    }

    printf("%f", alan);

    return 0;
}
