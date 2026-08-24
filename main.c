#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
struct otel {
    char isim[25];
    char soyIsim[15];
    char telNo[15];
    int odaNo;
};
struct otel p;
struct otel *ptr=&p;
void musteribilgilerGir() {
    for(int i=0;i<n;i++) {
        printf("%d. musteri\n",i+1);
        printf("Isim giriniz: ");
        scanf("%s",(ptr+i)->isim);
        printf("Soy ısim giriniz: ");
        scanf("%s",(ptr+i)->soyIsim);
        printf("Tel no giriniz: ");
        scanf("%14s",(ptr+i)->telNo);
        printf("Oda no giriniz: ");
        scanf("%d",&(ptr+i)->odaNo);

    }
}
void rezervasyonAl() {
   char arananTelNo[15];
    int bulundu=0;
    printf("Rezervasyon almak icin aranan mevcut telefon numarasini giriniz: ");
    scanf("%14s",arananTelNo);
    for(int i=0;i<n;i++) {
        if(strcmp(arananTelNo,(ptr+i)->telNo)==0) {
            bulundu=1;
            printf("Arana telefon numarasi bulundu ve rezervasyon alindi\n");
            break;
        }
    }
    if(bulundu==0) {
        printf("Aranan telefon numarasi bulunamadi ve rezervasyon alinamadi\n");
    }
}
void listele() {
    for(int i=0;i<n;i++) {
        printf("Otel rezervasyon listemiz:%s %s %s %d\n",(ptr+i)->isim,(ptr+i)->soyIsim,(ptr+i)->telNo,(ptr+i)->odaNo);
    }
}
void odaNoAra() {
    int arananOdaNo;
    int bulundu=0;
    printf("Aranan mevcut oda numarasini giriniz: ");
    scanf("%d",&arananOdaNo);
    for(int i=0;i<n;i++) {
        if(arananOdaNo==(ptr+i)->odaNo) {
            bulundu=1;
            printf("Aranan mevcut oda numarasi bulundu\n");
            break;
        }
    }
    if(bulundu==0) {
        printf("Aranan mevcut oda numarasi bulunamadi\n");
    }
}
void bosOdaSayisi() {
    int sayac=0;
    int kapasite=250;
    int bosOdaSayisi;
    for(int i=0;i<n;i++) {
        sayac++;
    }
    bosOdaSayisi=kapasite-sayac;
    printf("Bos oda sayisi %d\n",bosOdaSayisi);
}
void rezervasyonIptal() {
    int bulundu=0;
    char arananIsim[25];
    printf("Rezervasyon iptali icin aranan mevcut ismi giriniz: ");
    scanf("%s",arananIsim);
    for(int i=0;i<n;i++) {
        if (strcmp(arananIsim,(ptr+i)->isim)==0) {
            bulundu=1;
            printf("Rezervasyon iptali icin aranan mevcut isim bulundu ve rezervasyon iptal edildi\n");
            break;
        }
    }
    if(bulundu==0) {
        printf("Rezervasyon iptali icin aranan mevcut numara bulunamdi ve rezervasyon alinamadi\n");
    }
}
void toplamUcret() {
    int toplamUcret=0;
    int ucret;
    int gunSayisi;
    printf("Yogunluktan dolayi en fazla 7 gune kadar rezervasyon verilebiliyor\n");
    printf("Otelde kalinacak gun sayisini giriniz: ");
    scanf("%d",&gunSayisi);
    if (gunSayisi<=1) {
        ucret=750;
    }
    else if (gunSayisi<=4) {
        ucret=2500;
    }
    else {
        ucret=4750;
    }
    for(int i=0;i<n;i++) {
        toplamUcret=gunSayisi*ucret;
    }
    printf("Toplam ucret %d",toplamUcret);
}
void yeniMusteriBilgileriAl() {
    n++;
    ptr=realloc(ptr,n * sizeof(*ptr));
    if(ptr==NULL) {
        printf("Bellek ayrilamadi\n");
        return;
    }
        printf("Isim giriniz: ");
        scanf("%s",(ptr+n-1)->isim);
        printf("Soy isimi giriniz: ");
        scanf("%s",(ptr+n-1)->soyIsim);
        printf("Telefon numarasini giriniz: ");
        scanf("%14s",(ptr+n-1)->telNo);
        printf("Oda numarasini giriniz: ");
        scanf("%d",&(ptr+n-1)->odaNo);
}
void cikis() {
    printf("Cikis yapildi.\n");
}
int main() {
    int sec;
    printf("Musteri sayisini giriniz: ");
    scanf("%d",&n);
    ptr=malloc(n * sizeof(*ptr));
    if(ptr==NULL) {
        printf("Bellek ayrilamadi\n");
        return 1;
    }
    do{
        printf("\n___<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("            Dinamik Otel Rezervasyon Sistemi            \n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>___\n");
        printf("1-Musteri bilgilerini Gir\n");
        printf("2-Rezervasyon Al\n");
        printf("3-Listele\n");
        printf("4-Oda numarasina gore ara\n");
        printf("5-Bos Oda Sayisi\n");
        printf("6-Rezervasyon Iptali\n");
        printf("7-Toplam Ucret\n");
        printf("8-Yeni musteri bilgisi ekle\n");
        printf("9-Cikis\n");
        printf("1-9 arasinda bir secim yapiniz lutfen: ");
        scanf("%d",&sec);
        switch(sec) {
            case 1:musteribilgilerGir();
                break;
            case 2:rezervasyonAl();
                break;
            case 3:listele();
                break;
            case 4:odaNoAra();
                break;
            case 5:bosOdaSayisi();
                break;
            case 6:rezervasyonIptal();
                break;
                case 7:toplamUcret();
                break;
                case 8:yeniMusteriBilgileriAl();
                break;
                case 9:cikis();
                break;
        }
    }while(sec!=9);
    free(ptr);
    return 0;
}