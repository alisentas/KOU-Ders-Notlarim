#include <stdio.h>

/* a = 5 sayisinin yarisini bulmayla ilgili denemeler */

int main() {

 int a = 5;

 float sonuc_1 = a / 2; // Burada sonuc iki cikiyor cunku tam sayi / tam sayi = tam sayi

 float sonuc_2 = a / 2.0;

 float sonuc_3 = (float)a / 2;

 printf("sonuc_1: %f\n", sonuc_1);

 printf("sonuc_2: %f\n", sonuc_2);

 printf("sonuc_3: %f\n", sonuc_3);

 return 0;

}
