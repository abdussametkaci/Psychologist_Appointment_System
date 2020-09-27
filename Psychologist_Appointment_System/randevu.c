/**
 * @file randevu.c 
 * @description Psikologun randevularini bir dosyaya kaydedip psikologun randevularini dosyaya girmesini,
 * dosyadan randevu sorgulamasini ve randevu silmesi gibi temel islemleri yapmasini saglar
 * @assignment Odev 2
 * @date 21.12.2019
 * @author Abdusamet KACI
 */
#include "randevu.h"
#include <stdio.h>
#include "myStringControl.h"

char *days[] = {"pazartesi", "sali", "carsamba", "persembe", "cuma", "cumartesi", "pazar"}; // gunleri ekrana bastirmak icin tanimlandi

typedef enum
{ 
    pazartesi = 1,
    sali,
    carsamba,
    persembe,
    cuma,
    cumartesi,
    pazar
} Gun;

int showAppointments(Hasta hasta)
{
    int hasAppointment = 1; // randevu var mi
    FILE *file;
    if ((file = fopen("randevular.txt", "r+")) == NULL) // dosya acilir, acilmazsa hata verir
    {
        printf("file could not be opened\n");
    }
    else
    {
        while (!feof(file))
        {
            fscanf(file, "%[^,],%d,%d\n", hasta.ad, &hasta.gun, &hasta.saat); // dosyadan istenilen formatta veri okunur ve girilen parametreye atanir
            if(hasta.saat == 0){ // eger saat 0 ise dosyada kayit yoktur
                return 0;
            }
            printf("%s %s %d:00\n", hasta.ad, days[hasta.gun - 1], hasta.saat); // hastanin bilgileri ekrana bastirilir
            
        }
        fclose(file); // dosya kapatilir
    }
    
    return hasAppointment;
}

int findHasta(char *hastaAd, Hasta hasta)
{
    int foundedHasta = 0; // hasta bulundu mu
    FILE *file;
    if ((file = fopen("randevular.txt", "r+")) == NULL)
    {
        printf("file could not be opened\n");
    }
    else
    {
        while (!feof(file))
        {
            fscanf(file, "%[^,],%d,%d\n", hasta.ad, &hasta.gun, &hasta.saat);
            if (isSame(hastaAd, hasta.ad)) // ayni ada sahip bir hasta varsa hasta bulunur onun bilgileri batirilir
            {
                foundedHasta = 1;
                printf("%s %s %d:00\n", hasta.ad, days[hasta.gun - 1], hasta.saat);
                break;
            }
        }
        fclose(file);
    }
    return foundedHasta;

}

int findDays(int day, Hasta hasta)
{
    int foundedDay = 0; // o gunde randevu var mi
    FILE *file;
    if ((file = fopen("randevular.txt", "r+")) == NULL)
    {
        printf("file could not be opened\n");
    }
    else
    {
        while (!feof(file))
        {
            fscanf(file, "%[^,],%d,%d\n", hasta.ad, &hasta.gun, &hasta.saat);
            if (hasta.gun == day) // eger o gunde randevu varsa
            {
                foundedDay = 1;
                printf("%s %s %d:00\n", hasta.ad, days[hasta.gun - 1], hasta.saat); // o gundaki hastalarin bilgileri ekrana bastirilir
            }
        }
        fclose(file);
    }
    return foundedDay;

}

int findDayAndHour(int day, int hour, Hasta hasta)
{
    int foundedDay = 0;
    FILE *file;
    if ((file = fopen("randevular.txt", "r+")) == NULL)
    {
        printf("file could not be opened\n");
    }
    else
    {
        while (!feof(file))
        {
            fscanf(file, "%[^,],%d,%d\n", hasta.ad, &hasta.gun, &hasta.saat);
            if (hasta.gun == day && hasta.saat == hour) // o gun ve saatte bir randevu varsa 
            {
                foundedDay = 1;
                printf("%s %s %d:00\n", hasta.ad, days[hasta.gun - 1], hasta.saat);
                break;
            }
        }
        fclose(file);
    }
    return foundedDay;

}

int getAppointment(Hasta hasta)
{
    int givenAppointment = 0;
    FILE *file;

    if ((file = fopen("randevular.txt", "a")) == NULL)
    {
        printf("file could not be opened\n");
    }
    else
    {
        fprintf(file, "%s,%d,%d\n", hasta.ad, hasta.gun, hasta.saat); // dosyaya randvu verilmek istenilen hastanin bilgileri formatli bir sekilde yazilir
        givenAppointment = 1;
        fclose(file);
    }
    return givenAppointment;
}

int deleteAppointment(char *name, Hasta hasta)
{
    int deletedAppointment = 0;
    FILE *copyFile;

    if ((copyFile = fopen("randevular_copy.txt", "w")) == NULL) // silinecek randevu haricindeki tum randevularin kaydedilecegi dosya acilir
    {
        printf("fdosya acilamadi\n");
    }
    FILE *file;

    if ((file = fopen("randevular.txt", "r+")) == NULL)
    {
        printf("dosya acilamadi\n");
    }
    else
    {
        while (!feof(file))
        {
            fscanf(file, "%[^,],%d,%d\n", hasta.ad, &hasta.gun, &hasta.saat);
            if (isSame(name, hasta.ad)) // girilen ad ile hastanin adi ayniysa kaydetmeyip bir sonraki hastayi okur
            {
                deletedAppointment = 1;
                continue;
            }
            fprintf(copyFile, "%s,%d,%d\n", hasta.ad, hasta.gun, hasta.saat); // hastalari copy dosyaya kaydeder
        }

        fclose(file);
        fclose(copyFile);
        remove("randevular.txt"); // randevular dosyasi silinir
        rename("randevular_copy.txt", "randevular.txt"); // olusturdugumuz copy dosyanin adi bir onceki dosya olan randevular olarak degistirilir
        
    }
    
    return deletedAppointment;
}
