#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265359

//gezegenleri diziye atıyoruz. Güneşe yakından uzağa doğru
const char *gezegen_isimleri[] = {
    "Merkur", "Venus", "Dunya", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptun"
};

//fonksiyonları üstte tanımlayıp en altta yazıyoruz görüntü kirliliği olmaması için
void menu_yazdir();
double deger_kontrol(double val);
void serbest_dusme(double *g_ptr, int boyut);
void yukari_atis(double *g_ptr, int boyut);
void agirlik_hesapla(double *g_ptr, int boyut);
void potansiyel_enerji(double *g_ptr, int boyut);
void hidrostatik_basinc(double *g_ptr, int boyut);
void arsimet_kaldirma(double *g_ptr, int boyut);
void basit_sarkac(double *g_ptr, int boyut);
void ip_gerilmesi(double *g_ptr, int boyut);
void asansor_deneyi(double *g_ptr, int boyut);

int main() {
    char bilim_insani[100]; // bilim insanının adını alıyoruz
    printf("Bilim Insaninin Adini Giriniz: ");
    fgets(bilim_insani, sizeof(bilim_insani), stdin);
    bilim_insani[strcspn(bilim_insani, "\n")] = 0;

    double yercekimleri[] = {3.7, 8.87, 9.807, 3.721, 24.79, 10.44, 8.69, 11.15}; // gezegenlerin yerçekim ivmelerini sırasıyla bir diziye atıyoruz
    int gezegen_sayisi = 8;
    int secim = 0;

    printf("\nHosgeldiniz, Sayin %s.\n", bilim_insani);
    printf("Uzay Simulasyonu Hazirlaniyor...\n");

    while (secim != -1) {
        menu_yazdir(); // her deney sonrası tekrardan menüyü yazdırır
        printf("\nLutfen bir deney seciniz (Cikis icin -1 tuslayin) : ");
        scanf("%d", &secim);
//-1 girildiğinde program sonlanır
        if (secim == -1) {
            printf("Program sonlandiriliyor... \nIyi gunler %s.\n", bilim_insani);
            break;
        }

        switch (secim) {
            case 1: serbest_dusme(yercekimleri, gezegen_sayisi);
            break;
            case 2: yukari_atis(yercekimleri, gezegen_sayisi);
            break;
            case 3: agirlik_hesapla(yercekimleri, gezegen_sayisi);
            break;
            case 4: potansiyel_enerji(yercekimleri, gezegen_sayisi);
            break;
            case 5: hidrostatik_basinc(yercekimleri, gezegen_sayisi);
            break;
            case 6: arsimet_kaldirma(yercekimleri, gezegen_sayisi);
            break;
            case 7: basit_sarkac(yercekimleri, gezegen_sayisi);
            break;
            case 8: ip_gerilmesi(yercekimleri, gezegen_sayisi);
            break;
            case 9: asansor_deneyi(yercekimleri, gezegen_sayisi);
            break;
            default: printf("Gecersiz numara! Deneylerimiz 1-9 arasidir.\n"); //1-9 arası ve -1 harici sayı girilirse uyarı verip tekrar menüyü yazdırır
        }
    } return 0;
}

void menu_yazdir() {
    printf("\n--- DENEY LISTESI ---\n1. Serbest Dusme Deneyi\n2. Yukari Atis Deneyi\n3. Agirlik Deneyi\n4. Kutlecekimsel Potansiyel Enerji Deneyi\n5. Hidrostatik Basinc Deneyi\n6. Arsimet Kaldirma Kuvveti Deneyi\n7. Basit Sarkac Periyodu Deneyi\n8. Sabit Ip Gerilmesi Deneyi\n9. Asansor Deneyi\n");
}
//- değerleri + ya çevirmek için kullanılan fonksiyonumuz
double deger_kontrol(double val) {
    return (val < 0) ? -val : val;
}
// 1. Serbest Düşme Deneyi: h = 1/2 * g * t^2
void serbest_dusme(double *g_ptr, int boyut) {
    double t;
    int i;
    printf("\n--- Serbest Dusme Deneyi ---\n");
    printf("Sure (t) giriniz [sn]: ");
    scanf("%lf", &t);
    t = deger_kontrol(t);
    printf("\nSonuclar (Girilen Sure: %.2f sn):\n", t);
    printf("%-10s | %-15s\n", "Gezegen", "gidilen Yol (m)");
    printf("-------------------------------\n");

    for ( i = 0; i < boyut; i++) {

        double g = *(g_ptr + i);
        double h = 0.5 * g * t * t;
        printf("%-10s | %.2f m\n", *(gezegen_isimleri + i), h);
    }

}

// 2. Yukarı Atış Deneyi: h_max = v0^2 / (2g)
void yukari_atis(double *g_ptr, int boyut) {
    double v0;
    int i;
    printf("\n--- Yukari Atis Deneyi ---\n");
    printf("Firlatma hizi (v0) giriniz [m/s]: ");
    scanf("%lf", &v0);
    v0 = deger_kontrol(v0);
    printf("\nSonuclar (Hiz: %.2f m/s):\n", v0);
    printf("%-10s | %-15s\n", "Gezegen", "Max Yukseklik (m)");
    printf("-------------------------------\n");

    for ( i = 0; i < boyut; i++) {
        double g = *(g_ptr + i);
        double h_max = (v0 * v0) / (2 * g);
        printf("%-10s | %.2f m\n", *(gezegen_isimleri + i), h_max);
    }
}

// 3. Ağırlık Deneyi: G = m * g
void agirlik_hesapla(double *g_ptr, int boyut) {
    double m;
    int i;
    printf("\n--- Agirlik Deneyi ---\n");
    printf("Cismin kutlesini (m) giriniz [kg]: ");
    scanf("%lf", &m);
    m = deger_kontrol(m);
    printf("\nSonuclar (Kutle: %.2f kg icin):\n", m);
    printf("%-10s | %-15s\n", "Gezegen", "Agirlik (N)");
    printf("-------------------------------\n");

    for (i = 0; i < boyut; i++) {
        double g = *(g_ptr + i);
        double agirlik = m * g;
        printf("%-10s | %.2f N\n", *(gezegen_isimleri + i), agirlik);
    }
}

// 4. Potansiyel Enerji Deneyi: Ep = m * g * h
void potansiyel_enerji(double *g_ptr, int boyut) {
    double m, h;
    int i;
    printf("\n--- Kutlecekimsel Potansiyel Enerji Deneyi ---\n");
    printf("Kutle (m) giriniz [kg]: ");
    scanf("%lf", &m);
    printf("Yukseklik (h) giriniz [m]: ");
    scanf("%lf", &h);
    m = deger_kontrol(m);
    h = deger_kontrol(h);
    printf("\nSonuclar (m: %.2f kg, h: %.2f m):\n", m, h);
    printf("%-10s | %-15s\n", "Gezegen", "Enerji (Joule)");
    printf("-------------------------------\n");
    for (i = 0; i < boyut; i++) {
        double g = *(g_ptr + i);
        double ep = m * g * h;
        printf("%-10s | %.2f J\n", *(gezegen_isimleri + i), ep);
    }
}

// 5. Hidrostatik Basınç Deneyi: P = rho * g * h
void hidrostatik_basinc(double *g_ptr, int boyut) {
    double rho, h;
     int i;
    printf("\n--- Hidrostatik Basinc Deneyi ---\n");
    printf("Sivinin yogunlugu (rho) [kg/m^3]: ");
    scanf("%lf", &rho);
    printf("Derinlik (h) [m]: ");
    scanf("%lf", &h);
    h = deger_kontrol(h);
    printf("\nSonuclar (rho: %.2f, h: %.2f):\n", rho, h);
    printf("%-10s | %-15s\n", "Gezegen", "Basinc (Pascal)");
    printf("-------------------------------\n");
    for (i = 0; i < boyut; i++) {
        double g = *(g_ptr + i);
        double P = rho * g * h;
        printf("%-10s | %.2f Pa\n", *(gezegen_isimleri + i), P);
    }
}

// 6. Arşimet Kaldırma Kuvveti: Fk = rho * g * V
void arsimet_kaldirma(double *g_ptr, int boyut) {
    double rho, V;
    int i;
    printf("\n--- Arsimet Kaldirma Kuvveti Deneyi ---\n");
    printf("Sivinn yogunlugu (rho) [kg/m^3]: ");
    scanf("%lf", &rho);
    printf("Batan hacim (V) [m^3]: ");
    scanf("%lf", &V);
    V = deger_kontrol(V);
    printf("\nSonuclar (rho: %.2f, V: %.2f):\n", rho, V);
    printf("%-10s | %-15s\n", "Gezegen", "Kuvvet (N)");
    printf("-------------------------------\n");
    for (i = 0; i < boyut; i++) {
        double g = *(g_ptr + i);
        double Fk = rho * g * V;
        printf("%-10s | %.2f N\n", *(gezegen_isimleri + i), Fk);
    }
}

// 7. Basit Sarkaç Periyodu: T = 2 * pi * sqrt(L / g)
void basit_sarkac(double *g_ptr, int boyut) {
    double L;
     int i;
    printf("\n--- Basit Sarkac Periyodu deneyi ---\n");
    printf("Ip uzunlugu (L) giriniz [m]: ");
    scanf("%lf", &L);
    L = deger_kontrol(L);
    printf("\nSonuclar (Uzunluk: %.2f m):\n", L);
    printf("%-10s | %-15s\n", "Gezegen", "Periyot (s)");
    printf("-------------------------------\n");

    for (i = 0; i < boyut; i++) {
        double g = *(g_ptr + i);
        double T = 2 * PI * sqrt(L / g);
        printf("%-10s | %.2f s\n", *(gezegen_isimleri + i), T);
    }
}

// 8. Sabit İp Gerilmesi: T = m * g
void ip_gerilmesi(double *g_ptr, int boyut) {
    double m;
    int i;
    printf("\n--- Sabit Ip Gerilmesi Deneyi ---\n");
    printf("kutle (m) giriniz [kg]: ");
    scanf("%lf", &m);
    m = deger_kontrol(m);
    printf("\nSonuclar (Kutle: %.2f kg):\n", m);
    printf("%-10s | %-15s\n", "Gezegen", "Gerilme (N)");
    printf("-------------------------------\n");

    for (i = 0; i < boyut; i++) {
        double g = *(g_ptr + i);
        double T = m * g;
        printf("%-10s | %.2f N\n", *(gezegen_isimleri + i), T);
    }
}

// 9. Asansör Deneyi: N = m(g + a) veya m(g - a)
void asansor_deneyi(double *g_ptr, int boyut) {
    double m, a;
    int yon,i; //yon icin 1: Yukarı Hızlanan/Aşağı Yavaşlayan, 2: Aşağı Hızlanan/Yukarı Yavaşlayan


    printf("\n--- Asansor Deneyi ---\n");
    printf("Cismin kutlesi (m) [kg]: ");
    scanf("%lf", &m);
    printf("Asansor ivmesi (a) [m/s^2]: ");
    scanf("%lf", &a);
    printf("Hareket Yonu Seciniz:\n");
    printf("1. Yukari yonlu ivmelenerek HIZLANIYOR (veya asagi yavasliyor)\n");
    printf("2. Asagi yonlu ivmelenerek HIZLANIYOR (veya yukari yavasliyor)\n");
    printf("Seciminiz: ");
    scanf("%d", &yon);
    m = deger_kontrol(m);
    a = deger_kontrol(a); // İvmeyi pozitif alıp yönünü de kullanıcıdan aldım
    printf("\nSonuclar (m: %.2f kg, a: %.2f m/s^2):\n", m, a);
    printf("%-10s | %-15s\n", "Gezegen", "Etkin Agirlik (N)");
    printf("-------------------------------\n");

    for (i = 0; i < boyut; i++) {
        double g = *(g_ptr + i);
        double N = 0;
    // Formül seçimi
        if (yon == 1) {
             N = m * (g + a);
        } else {
             N = m * (g - a);
             if (N < 0) N = 0;
        }
        printf("%-10s | %.2f N\n", *(gezegen_isimleri + i), N);
    }
}
