#include <stdio.h>
#include <stdlib.h>

// Ali SENTAs @KOU

char tahta[14][14]; // Karakterlerin saklanacagi matris
// Oyun 10-10'luk duzlemde oynaniyor fakat kenarlarda iki birimlik bosluk var
// Bunun amaci oyuncu kenarlarda bir deger girdigi zaman ornegin 0 0 koordinatinda
// bir karakter girerse program tahta[-2][-2] yi kontrol etmek isteyecek
// Orda dizi sinirinin disina ciktigi icin hata verebilir.
// Oyuncu aslinda girdigi her degerin 2 fazlasini girmis oluyor.
// 0 0 girdigi zaman sanki 2 2 girmis gibi islem göroyur
int i, j; // Dongu terimleri
int oyuncu = 1; // O anki oyuncu, 1 ya da 2 oluyor
int puanlar[3] = {0, 0, 0}; // 1. oyuncunun puani 2. indis, digernin 3.
int bitis = 0; // Oynanacak kare kalmadiginda 1 oluyor

void yaz();
void hamle();
void bitis_kontrol();

int main()
{
    printf("================================================================================\n\n");
    printf("   ███████╗ ██████╗ ███████╗     ██████╗ ██╗   ██╗██╗   ██╗███╗   ██╗██╗   ██╗\n");
    printf("   ██╔════╝██╔═══██╗██╔════╝    ██╔═══██╗╚██╗ ██╔╝██║   ██║████╗  ██║██║   ██║\n");
    printf("   ███████╗██║   ██║███████╗    ██║   ██║ ╚████╔╝ ██║   ██║██╔██╗ ██║██║   ██║\n");
    printf("   ╚════██║██║   ██║╚════██║    ██║   ██║  ╚██╔╝  ██║   ██║██║╚██╗██║██║   ██║\n");
    printf("   ███████║╚██████╔╝███████║    ╚██████╔╝   ██║   ╚██████╔╝██║ ╚████║╚██████╔╝\n");
    printf("   ╚══════╝ ╚═════╝ ╚══════╝     ╚═════╝    ╚═╝    ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ \n\n");
    printf("================================================================================\n\n");
    printf("Amac SOS kelimesini yatay, dikey ya da carpraz olarak yazmak.\nOrnek bir hamle: '0 0 S'.\n");

    // Once butun karelerdeki degerleri '.' yapiyoruz.
    for(i = 0; i < 14; i++){
        for(j = 0; j < 14; j++){
            tahta[i][j] = '.';
        }
    }

    // Oyun bitmdigi surece yaz, hamle yap, kontrol et
    while(!bitis){
        yaz();
        hamle();
        bitis_kontrol();
    }

    printf("|n Oyun bitti. \n");

    if(puanlar[1] > puanlar[2]){
        printf("\n1. Oyuncu kazandi, tebrikler.. \n\n");
    }else{
        printf("\n2. Oyuncu kazandi, tebrikler.. \n\n");
    }

    return 0;
}

/**
 * Yaz fonksiyonu ekrana tahtayi ve puan durumunu yazdirir
 */
void yaz(){
    printf("\n  ");
    for(i = 0; i < 10; i++){
        printf(" %d", i);
    }
    printf("\n");
    for(i = 0; i < 10; i++){
        printf("%d ", i);
        for(j = 0; j < 10; j++){
            printf(" %c", tahta[i + 2][j + 2]);
            // +2 vermemin sebebi tahtanin kenarlarinda 2 birimlik bosluk olmasi
        }
        printf("\n");
    }
    printf("\nPuanlar: %d - %d\n\n", puanlar[1], puanlar[2]);
}
/**
 * Hamle fonksiyonu once kullaniciden x, y koordinatlarini ve karakteri aliyor
 * Koordinatlari, koordinat sinirlarini ve karakterin S ya d O olup olmagdigini kontrol ediyor
 * Oyuncunun SOS sozcugunu yazip yazamadigini, kac tane yazdigini kontrol edip puani ona gore
 * artiriyor ve eger puan degismediyse oynayan oyuncuyu degistiriyor
 */

void hamle(){
    int x, y; //Oyuncunun girecegi x-y degerleri
    char c; // S ya da O'yu tutan degisken
    int onceki_puan = puanlar[oyuncu]; // Eer oyuncunun ilk puani degisirse bir tane daha hamle yapma sansi
    // oluyor, puanin degisip degismedigini kontrol edebiliriz.
    printf("%d. oyuncunun hamlesini girin > ", oyuncu);
    scanf("%d %d %c", &x, &y, &c);
    if(c != 'O' && c !='S'){
        printf("Buyuk harfle S ya da O girin.\n");
        hamle();
    }else if(x < 0 || x > 9 || y < 0 || y > 9){
        printf("Koordinatlar sinirin disinda.\n");
        hamle();
    }else if(tahta[y + 2][x + 2] != '.'){
        printf("O kare dolu, baska bir yere hamle yapin.\n");
        hamle();
    }
    x += 2;
    y += 2; // +2'nin sebeni kenardaki bosluklar
    tahta[y][x] = c;
    // Kontrol kısmı
    if(c == 'S'){
        // Carpraz, dikey ve yatay kontrol ederek SOS kelimesini atiyor
        if(tahta[y - 2][x - 2] == 'S' && tahta[y - 1][x - 1] == 'O') puanlar[oyuncu]++;
        if(tahta[y + 2][x + 2] == 'S' && tahta[y + 1][x + 1] == 'O') puanlar[oyuncu]++;
        if(tahta[y - 2][x + 2] == 'S' && tahta[y - 1][x + 1] == 'O') puanlar[oyuncu]++;
        if(tahta[y + 2][x - 2] == 'S' && tahta[y + 1][x - 1] == 'O') puanlar[oyuncu]++;
        if(tahta[y][x + 2] == 'S' && tahta[y][x + 1] == 'O') puanlar[oyuncu]++;
        if(tahta[y][x - 2] == 'S' && tahta[y][x - 1] == 'O') puanlar[oyuncu]++;
        if(tahta[y + 2][x] == 'S' && tahta[y + 1][x] == 'O') puanlar[oyuncu]++;
        if(tahta[y - 2][x] == 'S' && tahta[y - 1][x] == 'O') puanlar[oyuncu]++;
    }else if(c == 'O'){
        if(tahta[y + 1][x + 1] == 'S' && tahta[y - 1][x - 1] == 'S') puanlar[oyuncu]++;
        if(tahta[y + 1][x - 1] == 'S' && tahta[y - 1][x + 1] == 'S') puanlar[oyuncu]++;
        if(tahta[y][x + 1] == 'S' && tahta[y][x - 1] == 'S') puanlar[oyuncu]++;
        if(tahta[y + 1][x] == 'S' && tahta[y - 1][x] == 'S') puanlar[oyuncu]++;
    }
    if(onceki_puan == puanlar[oyuncu]){
        // Eger oyuncunun puani sabit kalimssa oyuncuyu degistiriyor
        if(oyuncu == 1){
            oyuncu = 2;
        }else{
            oyuncu = 1;
        }
    }
}

/**
 * bitis_kontrol fonksiyonu icerigi '.' olan kareleri sayiyor, eger sifira esitse
 * bitis = 1 yaparak oyunu bitiriyor
 */
void bitis_kontrol(){
    int bosluk = 0;
    for(i = 2; i < 12; i++){
        for(j = 2; j < 12; j++){
            if(tahta[i][j] == '.') bosluk++;
        }
    }
    if(bosluk == 0) bitis = 1;
}
