#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cumle[100], deg_str[10], yeni_str[10];
    char yenicumle[200];
    int i, j, k;
    int found[100];
    memset(found, -1, sizeof(int)*100);

    printf("bir cumle girin: "); fgets(cumle, 100, stdin);
    printf("degistirilecek stringi girin: "); fgets(deg_str, 10, stdin);
    printf("yeni stringi girin: ");fgets(yeni_str, 10, stdin);
    deg_str[strlen(deg_str) - 1] = '\0';
    yeni_str[strlen(yeni_str) - 1] = '\0';

    char *ara_ptr = strstr(cumle, deg_str);
    i = 0;
    while(ara_ptr != NULL){
        found[i] = ara_ptr-cumle;
        i++;
        ara_ptr = strstr(ara_ptr+1, deg_str);
    }

    i = 0;
    j = 0;
    k = 0;
    yenicumle[0] = '\0';
    while(i < strlen(cumle) - 1){
        if(i == found[j]){
            j++;
            strcat(yenicumle, yeni_str);
            k += strlen(yeni_str);
            i += strlen(deg_str);
        }else{
            yenicumle[k] = cumle[i];
            k++;
            i++;
        }
    }

    yenicumle[k] = '\0';

    printf("\ndegistirildikten sonra:\n%s\n\n", yenicumle);

    return 0;
}
