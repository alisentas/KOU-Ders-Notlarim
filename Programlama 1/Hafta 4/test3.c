#include <stdio.h>

int main()
{
    double a, b, c, fark;
    a = 3.6;
    b = 4.6;
    c = (b - 1);
    printf(("\n"));
    printf("a = %.20f\n", a);
    printf("c = %.20f\n\n", c);

    if (a < c)
        fark = c - a;
    else
        fark = a - c;


    if (fark < 0.0000000001)
    {
        printf("3.6 ile (4.6 - 1) esit\n");
    }
    else
    {
        printf("3.6 ile (4.6 - 1) esit degil\n");
    }

    return 0;

}
