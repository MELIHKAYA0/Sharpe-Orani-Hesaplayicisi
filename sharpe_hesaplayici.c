#include <stdio.h>

// Nicel Analiz (Kantitatif Analiz) Tanimi
void nicelAnalizGiris() {
    printf("\n--- Nicel Analiz (Kantitatif Analiz) Girisi ---\n");
    printf("Nicel analiz, yatirim kararlarini bilgilendirmek icin veri ve matematiksel tekniklerin kullanilmasina odaklanan bir finansal analiz dalidir.\n");
    printf("Bu program, finansal piyasalardaki onemli risk/getiri olcutlerinden biri olan Sharpe Oranini hesaplar.\n");
    printf("--------------------------------------------------\n\n");
}

// Ana Fonksiyon
int main() {
    double yatirim_getirisi; 
    double risksiz_faiz;     
    double standart_sapma;   
    double sharpe_orani;     

    nicelAnalizGiris(); 

    printf("--- Sharpe Orani Hesaplayici ---\n");

    printf("Yatirim Getirisini (ornegin 15.0%% icin 15.0) giriniz: ");
    if (scanf("%lf", &yatirim_getirisi) != 1) {
        printf("Hatali giris.\n");
        return 1;
    }

    printf("Risksiz Faiz Oranini (ornegin 5.0%% icin 5.0) giriniz: ");
    if (scanf("%lf", &risksiz_faiz) != 1) {
        printf("Hatali giris.\n");
        return 1;
    }

    printf("Standart Sapmayi (Risk) (ornegin 12.0%% icin 12.0) giriniz: ");
    if (scanf("%lf", &standart_sapma) != 1) {
        printf("Hatali giris.\n");
        return 1;
    }

    if (standart_sapma == 0) {
        printf("\nStandart sapma (risk) sifir olamaz. Lutfen gecerli bir deger giriniz.\n");
        return 1; 
    }

    // Hesaplama: S = (Rp - Rf) / Sigma
    sharpe_orani = (yatirim_getirisi - risksiz_faiz) / standart_sapma;
    

    printf("\n--- Hesaplama Sonucu ---\n");
    printf("Yatirim Getirisi (Rp):   %.2lf%%\n", yatirim_getirisi);
    printf("Risksiz Faiz Orani (Rf): %.2lf%%\n", risksiz_faiz);
    printf("Standart Sapma (Sigma):  %.2lf%%\n", standart_sapma);
    
    printf("\nSharpe Orani:            %.4lf\n", sharpe_orani);

    // Sonucu yorumlama
    printf("\n--- Yorum ---\n");
    if (sharpe_orani >= 3.0) {
        printf("Mukemmel Sharpe Orani (>= 3.0).\n");
    } else if (sharpe_orani >= 2.0) {
        printf("Cok Iyi Sharpe Orani (>= 2.0).\n");
    } else if (sharpe_orani >= 1.0) {
        printf("Iyi Sharpe Orani (>= 1.0).\n");
    } else if (sharpe_orani > 0) {
        printf("Pozitif Sharpe Orani (0 < S < 1.0). Risk almanin karsiligini risksiz getiriden daha fazla aliyorsunuz.\n");
    } else {
        printf("Negatif/Sifir Sharpe Orani (<= 0). Risk almak, risksiz getiriye gore fazladan bir fayda saglamiyor.\n");
    }

    return 0;
}
