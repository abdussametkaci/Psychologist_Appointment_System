/**
 * @file myStringControl.h
 * @description Psikologun randevularini bir dosyaya kaydedip psikologun randevularini dosyaya girmesini,
 * dosyadan randevu sorgulamasini ve randevu silmesi gibi temel islemleri yapmasini saglar
 * @assignment Odev 2
 * @date 21.12.2019
 * @author Abdusamet KACI abdussamet.kaci@stu.fsm.edu.tr
 */
#ifndef MYSTRINGCONTROL_H
#define MYSTRINGCONTROL_H

int hasCharacter(char *); //girilen sringte karakter var mi
int isAlpha(char *); //girilen stringte alfabetik karakter var mi
int strLen(char *str); //girilen stringin uzunlugu
int isSame(char *str1, char *str2); //girilen iki string ayni mi

#endif