/**
 * @file menu.c 
 * @description Psikologun randevularini bir dosyaya kaydedip psikologun randevularini dosyaya girmesini,
 * dosyadan randevu sorgulamasini ve randevu silmesi gibi temel islemleri yapmasini saglar
 * @assignment Odev 2
 * @date 21.12.2019
 * @author Abdusamet KACI abdussamet.kaci@stu.fsm.edu.tr
 */
#include "menu.h"
#include <stdio.h>

void showMenu()
{
    printf("1. Randevulari goster\n");
    printf("2. Randevu ara\n");
    printf("3. Randevu ver\n");
    printf("4. Randevu sil\n");
    printf("5. Exit\n");
}

void showAraMenu()
{
    printf("    1. Ada gore\n");
    printf("    2. Gune gore\n");
    printf("    3. Geri don\n");
}

void showDays()
{
    printf("\n1-pazartesi\n");
    printf("2-sali\n");
    printf("3-carsamba\n");
    printf("4-persembe\n");
    printf("5-cuma\n");
    printf("6-cumartesi\n");
    printf("7-pazar\n");
}
