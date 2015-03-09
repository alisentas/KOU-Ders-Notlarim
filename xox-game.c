#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tahta[3][3] = {
    {'.', '.', '.'},
    {'.', '.', '.'},
    {'.', '.', '.'}
};
int bitis = 0; // Kontrol fonksiyonu 1 dondurdugunde oyun biter.

void yaz();
void giris();
void bilgisayar_hamlesi();
int kontrol(char x);

int main()
{
    srand(time(NULL));
    printf("XOX oyununa hosgeldiniz, siz X karakterini kullanacaksiniz. Giris yaparken koordinatlari arada bir bosluk birakip tek satirda girebilirsiniz. Ornegin: '2 1' gibi.\nBasarilar\n\n");

    while(!bitis){
        yaz();
        giris();
        if(!bitis){
            yaz();
            bilgisayar_hamlesi();
        }
    }

    return 0;
}

/**
 * yaz fonksiyonu tahtayi ve koordinat numaralarini ekrana yazdiriyor
 */
void yaz(){
    int i, j;
    printf("  1 2 3\n");
    for(i = 0; i < 3; i++){
        printf("%d", i + 1);
        for(j = 0; j < 3; j++){
            printf(" %c", tahta[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * giris fonksiyonu kullanicidan koordinat degerlerini alip tahtaya yaziyor
 */
void giris(){
    int x, y;
    printf("[x y] degerlerini giriniz > ");
    scanf("%d %d", &x, &y);

    if(tahta[y-1][x-1] == '.'){
        tahta[y-1][x-1] = 'X';
    }else{
        printf("O alan dolu.\nYeni ");
        giris();
    }

    // Kontrol fonksiyonu  dondurdugunde oyunu bitir.
    if(kontrol('X') == 1){
        yaz();
        printf("Tebrikler,  oyunu kazandiniz.\n");
        bitis = 1;
    }
}

/**
 * bilgisayar_hamlesi yapay zekanin devreye girdigi kisim
 * simdilik bir yapay zeka yok aslinda sadece bos buldugu rastgele bir yeri isaretliyor
 * bilgisayarin hamle yapacagi yeri secip isaretliyor
 */
void bilgisayar_hamlesi(){
    int x, y;
    x = rand() % 3;
    y = rand() % 3;
    while(tahta[x][y] != '.'){
        x = rand() % 3;
        y = rand() % 3;
    }
    tahta[y][x] = 'O';

    if(kontrol('O')){
        yaz();
        printf("Bilgisayar kazandi. :(");
        bitis = 1;
    }
}

/**
 * Kontrol fonksiyonu butun kazanma olasiliklarini kontrol ediyor.
 * @param x : char : kontrol edilecek deger
 * @return eger karakterden yanyana 3 tane bulursa 1, aksi halde 0
 */
int kontrol(char x){
    int i;
    // Yatay ve dikey kontrol
    for(i = 0; i < 3; i++){
        if(tahta[i][0] == x && tahta[i][1] == x && tahta[i][2] == x) return 1;
        if(tahta[0][i] == x && tahta[1][i] == x && tahta[2][i] == x) return 1;
    }
    // Carpraz kontrol
    // 2 olasilik var
    if(tahta[0][0] == x && tahta[1][1] == x && tahta[2][2] == x) return 1;
    if(tahta[0][2] == x && tahta[1][1] == x && tahta[2][0] == x) return 1;
    return 0;
}
