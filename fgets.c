#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[20];
    printf("Sayi girin > ");
    fgets(s, 20, stdin);

    int d;
    long l;
    double dob;

    d = atoi(s);
    l = atol(s);
    dob = atof(s);

    printf("%d, %ld, %lf", d, l, dob);
    return 0;
}
