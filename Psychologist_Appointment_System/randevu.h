/**
 * @file randevu.h 
 * @description Psikologun randevularini bir dosyaya kaydedip psikologun randevularini dosyaya girmesini,
 * dosyadan randevu sorgulamasini ve randevu silmesi gibi temel islemleri yapmasini saglar
 * @assignment Odev 2
 * @date 21.12.2019
 * @author Abdusamet KACI
 */
#ifndef RANDEVU_H
#define RANDEVU_H

typedef struct{ // psikolgun hasta deftarinde tutacagi hastalarin iceridgi bilgiler
    char ad[100];
    int gun;
    int saat;
}Hasta;

int showAppointments(Hasta); // randevulari gosterir
int findHasta(char *, Hasta); //istenilen hastayi bulur
int findDays(int, Hasta); // istenilen gundeki hastalari bulur
int findDayAndHour(int, int, Hasta); //istenilen gun ve saatte hasta olup olmadigini bulur
int getAppointment(Hasta); // randevu verir
int deleteAppointment(char *, Hasta); //istenilen addaki randevuyu siler

#endif
