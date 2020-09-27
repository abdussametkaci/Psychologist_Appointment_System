/**
 * @file main.c 
 * @description Psikologun randevularini bir dosyaya kaydedip psikologun randevularini dosyaya girmesini,
 * dosyadan randevu sorgulamasini ve randevu silmesi gibi temel islemleri yapmasini saglar
 * @assignment Odev 2
 * @date 21.12.2019
 * @author Abdusamet KACI
 */
#include <stdio.h>
#include "randevu.h"
#include "myStringControl.h"
#include "menu.h"

int main()
{
    Hasta hasta; //dosyadaki hastalarin okunan bilgilerinin atildigi yer
    char girdi[100]; //kullanicinin girdigi verinin atilacagi yer

    while (1)
    {

        while (1)
        {
            showMenu(); // menu gosterilir
            gets(girdi); // kullanicidan girdi istenir
            if (hasCharacter(girdi)) // eger girdide karakter varsa uyari verilir
            {
                printf("lutfen sadece rakam giriniz\n");
                continue;
            }

            if (atoi(girdi) <= 0 && atoi(girdi) > 5) // girdide girilen rakam 1 ve 5 arasinda degilse uyari mesaji verilir
            {
                printf("gecersiz secim lutfen tekrar deneyiniz\ngirdiniz 1 ile 5 arasinda olmalidir\n");
                continue;
            }

            break;
        }
        //eger hicbir problem yoksa
        if (atoi(girdi) == 1) // menudeki 1 numarali islem secilirse
        {
            if (showAppointments(hasta) == 0) // eger dosyada hicbir kayit yoksa uyari verilir, varsa randevular ekrana basilir
            {
                printf("hicbir kayit bulunamamistir\n");
            }
        }
        else if (atoi(girdi) == 2) // menudeki 2 numarali islem seilmisse
        {
            while (1)
            {
                showAraMenu(); // ara manu gosterilir
                gets(girdi); //kullanicidan girdi istenir
                if (hasCharacter(girdi)) //girdide karakter varsa uyari mesaji basilir
                {
                    printf("lutfen sadece rakam giriniz\n");
                    continue;
                }

                if (atoi(girdi) <= 0 || atoi(girdi) > 3) // girdide girilen rakam 1 ile 3 arasinda degilse uyari mesaji verilir
                {
                    printf("gecersiz secim lutfen tekrar deneyiniz\ngirdiniz 1 ile 3 arasinda olmalidir\n");
                    continue;
                }

                if (atoi(girdi) == 1) // ara menude 1 numarali islem secilirse
                {
                    while (1)
                    {
                        printf("sorgulamak istediginiz adi giriniz: ");
                        gets(girdi); // kullanicidan sorgulanmak istenen ad istenir
                        if (!isAlpha(girdi)) // eger girdide alfabetik karakter yoksa
                        {
                            printf("ad icin sadece alfabedeki karakterleri kullaniniz\n");
                            continue;
                        }
                        break;
                    }

                    if (findHasta(girdi, hasta) == 0) // girdide girilen hastanin adi dosyada yoksa hata mesaji gosterilir, varsa ekrana bastirilir
                    {
                        printf("boyle bir hasta bulunamamistir\n");
                        continue;
                    }
                }
                else if (atoi(girdi) == 2) // ara menude 2 numarali islem secilirse
                {
                    int gunSorgu;
                    while (1)
                    {
                        showDays(); // haftanin gunleri bastirilir
                        printf("sorgulamak istediginiz gunu giriniz: ");
                        gets(girdi); // kullanicidan sorgulamak istedigi gun istenir
                        if (hasCharacter(girdi)) // girdide karakter bulunuyorsa uyari mesaji gosterilir
                        {
                            printf("lutfen sadece rakam giriniz\n");
                            continue;
                        }

                        if (atoi(girdi) <= 0 || !(atoi(girdi) >= 1 && atoi(girdi) <= 7)) // girilen gun 1 ile 7 arasinda degilse uyari gosterilir
                        {
                            printf("gunler 1 ile 7 arasindadir\nlutfen tekrar deneyiniz\n");
                            continue;
                        }

                        break;
                    }

                    gunSorgu = atoi(girdi);
                    if (findDays(gunSorgu, hasta) == 0) // eger girilen gunde bir randevu bulunmuyorsa hata mesaji verilir, varsa o gunde bulunan randevular yazilir
                    {
                        printf("girilen gunde kimsenin randevusu yok\n");
                        //break;
                    }
                    continue;
                }
                else if (atoi(girdi) == 3) // ara menude 3 numarali islem girilirse ara menuden cikilip, ana menuye donulur
                {
                    printf("ana menuye donuluyor...\n");
                    break;
                }
            }
        }
        else if (atoi(girdi) == 3) // ana menude 3 islemi secilirse
        {
            Hasta yeniHasta; // randevusu girilecek hasta
            int devamMi = 1; // ilerde istenilecek hasta adinin olup olmamasina gore devam edilip edilmeyeceginin bilgisini tutar
            while (1)
            {
                printf("lutfen ad giriniz: ");
                gets(yeniHasta.ad); // randevu alinacak hastanin adi istenir

                if (!isAlpha(yeniHasta.ad)) // eger alfabetik deger yoksa uyari mesaji verir
                {
                    printf("lutfen sadece alfabedeki karakterleri kullaniniz\n");
                    continue;
                }

                if (findHasta(yeniHasta.ad, hasta)) // eger girdide alinan ad dosyada bulunan adlardan biriyle ayniysa uyari verir ve devam edilmez 
                {
                    printf("bu hasta zaten randevu almis\n");
                    devamMi = 0;
                    break;
                }

                break;
            }

            if (devamMi) // eger problem yoksa devam eder
            {
                while (1)
                {
                    while (1)
                    {
                        showDays(); // gunler gosterilir
                        printf("lutfen gunu giriniz: ");
                        gets(girdi);
                        if (hasCharacter(girdi))
                        {
                            printf("lutfen sadece rakam kullaniniz\n");
                            continue;
                        }

                        if (atoi(girdi) <= 0 || !(atoi(girdi) >= 1 && atoi(girdi) <= 7)) // haftanin gunlerini asarsa uyari verilir
                        {
                            printf("gun sadece 1 ile 7 arasinda olabilir\n");
                            continue;
                        }
                        yeniHasta.gun = atoi(girdi); // problem yoksa gun degeri atanir
                        break;
                    }

                    while (1)
                    {
                        printf("lutfen saati giriniz:");
                        gets(girdi);

                        if (hasCharacter(girdi))
                        {
                            printf("lutfen sadece rakam giriniz\n");
                            continue;
                        }

                        if (atoi(girdi) <= 0 || !(atoi(girdi) >= 1 && atoi(girdi) <= 24))
                        {
                            printf("saat dilimi 1 ile 24 arasinda bir deger olabilir\n");
                            continue;
                        }

                        yeniHasta.saat = atoi(girdi);
                        break;
                    }

                    if (findDayAndHour(yeniHasta.gun, yeniHasta.saat, hasta)) // eger ayni gun ve saatte bir randevu varsa uyari verilir
                    {
                        printf("bu saatte baska hastanin randevusu var\nayni gun ve saatte baska hastaya randevu veremezsiniz\n");
                        break;
                    }

                    if (getAppointment(yeniHasta) == 1) // randevu verilir
                    {
                        printf("randevu verildi\n");
                    }
                    else
                    {
                        printf("uzgunum randevu verilemedi\n");
                    }

                    break;
                }
            }
        }
        else if (atoi(girdi) == 4)
        {
            char silinecekAd[100];
            while (1)
            {
                printf("silinecek kisinin adini giriniz: ");
                gets(silinecekAd);

                if (!isAlpha(silinecekAd))
                {
                    printf("lutfen sadece alfabedeki karakterleri kullaniniz\n");
                    continue;
                }

                if (findHasta(silinecekAd, hasta) == 0) // silinicek hasta bulunduysa silinir, bulunamadiysa uyari verilir
                {
                    printf("boyle bir hasta bulunamamistir\n");
                    break;
                }

                if (deleteAppointment(silinecekAd, hasta) == 1) // hasta silinir
                {
                    printf("hasta basariyla silindi\n");
                }
                else
                {
                    printf("uzgunum hasta silinemedi\n");
                }

                break;
            }
        }
        else if (atoi(girdi) == 5)
        {
            printf("program kapatiliyor..\n");
            break;
        }
        else
        {
            printf("gecersiz giris\ngirisler 1 ile 5 arasinda olmalidir\nlutfen tekrar deneyiniz\n");
        }
    }
    return 0;
}
