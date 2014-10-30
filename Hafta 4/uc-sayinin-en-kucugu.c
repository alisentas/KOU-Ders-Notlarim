#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a, b, c;

	printf("Birinci Sayi: ");
	scanf("%f", &a);
	printf("Ikinci Sayi: ");
	scanf("%f", &b);
	printf("Ucuncu Sayi: ");
	scanf("%f", &c);
	printf("\n");

	if(a < b){
		if (b < c && a < c)
			printf("En kucuk sayi: %f\n", a);
		else
			printf("En kucuk sayi: %f\n", c);
	}else{
		if (b < c)
			printf("En kucuk sayi: %f\n", b);
		else
			printf("En kucuk sayi: %f\n", c);
	}

	return 0;
}
