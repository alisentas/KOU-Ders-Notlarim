#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, x = 0, y = 52, z = 103, t = 154, k = 205;
    for(i = 0; i <= 51; i++){
        printf("%d : %c \t %d : %c \t %d : %c \t %d : %c \t %d : %c", x, x, y, y, z, z, t, t, k, k);
        x++;
        y++;
        z++;
        t++;
        k++;
        printf("\n");
    }
    printf("\n\nEnter a number in range [0, 255] > "); scanf("%d", &i);
    printf("\n\nCharacter is: \"%c\"\n\n", i);
    return 0;
}
