#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tahta[3][3] = {
    {'.', '.', '.'},
    {'.', '.', '.'},
    {'.', '.', '.'}
};
int bitis = 0; // Kontrol fonksiyonu 1 dondurdugunde oyun biter.
int khamle = 1;
int bhamle = 1; //Kullanici ve bilgisayarin o anki hamle sayisi

void yaz();
void giris();
void bilgisayar_hamlesi();
int kontrol(char x);

int main()
{
    srand(time(NULL));
    //printf("===============================================================================\n==                                XOX Oyunu                                  ==\n==                              yapan: Ali Sentas                            ==\n===============================================================================\n\n");
    printf("================================================================================\n");
    printf("████████╗██╗ ██████╗    ████████╗ █████╗  ██████╗    ████████╗ ██████╗ ███████╗\n");
    printf("╚══██╔══╝██║██╔════╝    ╚══██╔══╝██╔══██╗██╔════╝    ╚══██╔══╝██╔═══██╗██╔════╝\n");
    printf("   ██║   ██║██║            ██║   ███████║██║            ██║   ██║   ██║█████╗  \n");
    printf("   ██║   ██║██║            ██║   ██╔══██║██║            ██║   ██║   ██║██╔══╝  \n");
    printf("   ██║   ██║╚██████╗       ██║   ██║  ██║╚██████╗       ██║   ╚██████╔╝███████╗\n");
    printf("   ╚═╝   ╚═╝ ╚═════╝       ╚═╝   ╚═╝  ╚═╝ ╚═════╝       ╚═╝    ╚═════╝ ╚══════╝\n");
    printf("================================================================================\n\n");
    printf("Tic-Tac-Toe oyununa hosgeldiniz, siz X karakterini kullanacaksiniz. Giris yaparken koordinatlari arada bir bosluk birakip tek satirda girebilirsiniz. Ornegin: '2 1' gibi.\nBasarilar\n\n");

    while(!bitis){
        yaz();
        giris();
        if(!bitis) khamle++;
        if(khamle == 6){
            printf("\nOyun berabere...\n\n");
            bitis = 1;
        }
        if(!bitis){
            yaz();
            bilgisayar_hamlesi();
            bhamle++;
        }
    }

    return 0;
}

/**
 * yaz fonksiyonu tahtayi ve koordinat numaralarini ekrana yazdiriyor
 */
void yaz(){
    int i, j;
    printf("\n  1 2 3\n");
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

void bilgisayar_hamlesi(){
    int x, y, xfound, x2found, dotfound, dot, ofound, o2found;
    printf("Bilgisayar hamlesini yapiyor...\n");
    if(bhamle == 1){
        if(tahta[1][1] == '.') // Eger tahtanin ortasi bossa oraya yerlestir
            tahta[1][1] = 'O';
        else{
            // Degilse rastgele bir yere
            x = rand() % 3;
            y = rand() % 3;
            while(tahta[y][x] != '.'){
                x = rand() % 3;
                y = rand() % 3;
            }
            tahta[y][x] = 'O';
        }
    }else if(bhamle == 2){
        if(tahta[1][1] == 'O'){
            for(x = 0; x < 3; x++){
                if(x == 1) continue;
                xfound = 0;
                x2found = 0;
                dotfound = 0;
                for(y = 0; y < 3; y++){
                    if(tahta[y][x] == 'X'){
                        if(!xfound) xfound++;
                        else x2found++;
                    }else if(tahta[y][x] == '.'){
                        dotfound++;
                        dot = y;
                    }
                }
                if(dotfound && xfound && x2found){
                    tahta[dot][x] = 'O';
                    goto control;
                }
            }
            for(y = 0; y < 3; y++){
                if(y == 1) continue;
                xfound = 0;
                x2found = 0;
                dotfound = 0;
                for(x = 0; x < 3; x++){
                    if(tahta[y][x] == 'X'){
                        if(!xfound) xfound++;
                        else x2found++;
                    }else if(tahta[y][x] == '.'){
                        dotfound++;
                        dot = x;
                    }
                }
                if(dotfound && xfound && x2found){
                    tahta[y][dot] = 'O';
                    goto control;
                }
            }
            x = rand() % 3;
            y = rand() % 3;
            while(tahta[y][x] != '.'){
                x = rand() % 3;
                y = rand() % 3;
            }
            tahta[y][x] = 'O';
        }else{
            for(x = 0; x < 3; x++){
                for(y = 0; y < 3; y++){
                    if(x == 1 && y == 1) continue;
                    if(tahta[y][x] == 'X'){
                        tahta[2 - y][2 - x] = 'O';
                    }
                }
            }
        }
    }else{
        // First check our win
        for(x = 0; x < 3; x++){
            ofound = 0;
            o2found = 0;
            dotfound = 0;
            for(y = 0; y < 3; y++){
                if(tahta[y][x] == 'O'){
                    if(!ofound) ofound++;
                    else o2found++;
                }else if(tahta[y][x] == '.'){
                    dotfound++;
                    dot = y;
                }
            }
            if(dotfound && ofound && o2found){
                tahta[dot][x] = 'O';
                goto control;
            }
        }
        for(y = 0; y < 3; y++){
            ofound = 0;
            o2found = 0;
            dotfound = 0;
            for(x = 0; x < 3; x++){
                if(tahta[y][x] == 'O'){
                    if(!ofound) ofound++;
                    else o2found++;
                }else if(tahta[y][x] == '.'){
                    dotfound++;
                    dot = x;
                }
            }
            if(dotfound && ofound && o2found){
                tahta[y][dot] = 'O';
                goto control;
            }
        }
        ofound = 0;
        o2found = 0;
        dotfound = 0;
        for(x = 0; x < 3; x++){
            if(tahta[x][x] == 'O'){
                if(!ofound) ofound++;
                else o2found++;
            }else if(tahta[x][x] == '.'){
                dotfound++;
                dot = x;
            }
        }
        if(dotfound && ofound && o2found){
            tahta[dot][dot] = 'O';
            goto control;
        }
        ofound = 0;
        o2found = 0;
        dotfound = 0;
        for(x = 0; x < 3; x++){
            if(tahta[x][2 - x] == 'O'){
                if(!ofound) ofound++;
                else o2found++;
            }else if(tahta[x][2 - x] == '.'){
                dotfound++;
                dot = 2 - x;
            }
        }
        if(dotfound && ofound && o2found){
            tahta[2 - dot][dot] = 'O';
            goto control;
        }
        // Check opponents win
        for(x = 0; x < 3; x++){
            xfound = 0;
            x2found = 0;
            dotfound = 0;
            for(y = 0; y < 3; y++){
                if(tahta[y][x] == 'X'){
                    if(!xfound) xfound++;
                    else x2found++;
                }else if(tahta[y][x] == '.'){
                    dotfound++;
                    dot = y;
                }
            }
            if(dotfound && xfound && x2found){
                tahta[dot][x] = 'O';
                goto control;
            }
        }
        for(y = 0; y < 3; y++){
            xfound = 0;
            x2found = 0;
            dotfound = 0;
            for(x = 0; x < 3; x++){
                if(tahta[y][x] == 'X'){
                    if(!xfound) xfound++;
                    else x2found++;
                }else if(tahta[y][x] == '.'){
                    dotfound++;
                    dot = x;
                }
            }
            if(dotfound && xfound && x2found){
                tahta[y][dot] = 'O';
                goto control;
            }
        }
        xfound = 0;
        x2found = 0;
        dotfound = 0;
        for(x = 0; x < 3; x++){
            if(tahta[x][x] == 'X'){
                if(!xfound) xfound++;
                else x2found++;
            }else if(tahta[x][x] == '.'){
                dotfound++;
                dot = x;
            }
        }
        if(dotfound && xfound && x2found){
            tahta[dot][dot] = 'O';
            goto control;
        }
        xfound = 0;
        x2found = 0;
        dotfound = 0;
        for(x = 0; x < 3; x++){
            if(tahta[x][2 - x] == 'O'){
                if(!xfound) xfound++;
                else x2found++;
            }else if(tahta[x][2 - x] == '.'){
                dotfound++;
                dot = 2 - x;
            }
        }
        if(dotfound && xfound && x2found){
            tahta[2 - dot][dot] = 'O';
            goto control;
        }
        // ikisi de yoksa rastgele oyna
        x = rand() % 3;
        y = rand() % 3;
        while(tahta[y][x] != '.'){
            x = rand() % 3;
            y = rand() % 3;
        }
        tahta[y][x] = 'O';
    }

    control:
    if(kontrol('O')){
        yaz();
        printf("Bilgisayar kazandi. :(\n\n");
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
