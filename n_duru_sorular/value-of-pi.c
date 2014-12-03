#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_pi(int N){
    double value = 4.0;
    int divider = 3;
    int positive = -1;

    do {
        value += (4.0 / divider) * positive;
        divider += 2;
        positive *= -1;
    }while(--N >= 0);

    return value;
}

int main(){
    int sayi;
    double pi = 3.14159265358979323846, kpi;
    while(1){
        printf("Sayi giriniz: "); scanf("%d", &sayi);
        kpi = calculate_pi(sayi);
        printf("Ulasilan pi degeri:\t %.20f\n", kpi);
        printf("Gercek pi degeri:\t %.20f\n\n", pi);
    }
    return 0;
}
