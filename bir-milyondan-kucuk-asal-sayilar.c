#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Bir milyondan kucuk asal sayilari ekrana yazan program
//Ali SENTAS

int isprime(int num){
	int i;
	float kok;
	kok = sqrt(num);
	if(num % 2 == 0){
		return 0;
	}
	for(i = 3; i <= kok; i += 2){
		if(num % i == 0){
			return 0;
		}
	}
	return 1;
}

int main()
{
    int sayac;
    printf("2");

    for(sayac = 3; sayac <= 1000000; sayac++){
		if(isprime(sayac))
			printf("%d\n", sayac);
    }
    return 0;
}
