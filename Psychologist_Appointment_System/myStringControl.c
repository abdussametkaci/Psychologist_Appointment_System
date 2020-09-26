/**
 * @file myStringControl.c 
 * @description Psikologun randevularini bir dosyaya kaydedip psikologun randevularini dosyaya girmesini,
 * dosyadan randevu sorgulamasini ve randevu silmesi gibi temel islemleri yapmasini saglar
 * @assignment Odev 2
 * @date 21.12.2019
 * @author Abdusamet KACI abdussamet.kaci@stu.fsm.edu.tr
 */
#include "myStringControl.h"
#include <stdio.h>

int hasCharacter(char *str)
{ //girilen degerin icinde karakter olup olmadigini kontrol eder
    int i = 0;
    while (*(str + i) != '\0') // null dan farkli oldugu muddetce bakar
    {
        if (!(*(str + i) >= '0' && *(str + i) <= '9')) // rakamlar arasinda degilse karakter icerir
        {
            return 1;
        }
        i++;
    }

    return 0;
}

int isAlpha(char *str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        // alfabedeki karakterler ve arasinda degilse (boslugu da kabul ettim cunku kabul etmezsem eger ilk kelimeyi alip diger kelimeye bakmiyor)
        if (!((*(str + i) >= 'A' && *(str + i) <= 'Z' || *(str + i) == ' ') || (*(str + i) >= 'a' && *(str + i) <= 'z' || *(str + i) == ' ')))
        {
            return 0;
        }
        i++;
    }

    return 1;
}

int strLen(char *str){ // string uzunlugunu bulur
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int isSame(char *str1, char *str2)
{ // iki string ayni mi diye kontrol eder
    if(strLen(str1) != strLen(str2)){
        return 0;
    }

    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
        i++;
    }

    return 1;
}