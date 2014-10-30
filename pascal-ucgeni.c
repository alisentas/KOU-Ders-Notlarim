#include <stdio.h>
#include <stdlib.h>

// Pascal ucgeni cizen program
// Ali SENTAS

int factorial(num){
	int i, fact;
	fact = 1;
	for(i = 2; i <= num; i++){
		fact = fact * i;
	}
	return fact;
}

int combination(base, value){
	if(value == 0 || value == base){
		return 1;
	}
	return factorial(base) / (factorial(value) * factorial(base - value));
}

int main()
{
	int j, k;
    printf("1\n1 1\n");
    for(j = 2; j <= 5; j++){
		for(k = 0; k <= j; k++){
			printf("%d ", combination(j, k));
		}
		printf("\n");
    }
    return 0;
}
