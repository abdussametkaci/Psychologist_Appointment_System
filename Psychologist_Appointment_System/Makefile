#@file Makefile
#@description Psikologun randevularini bir dosyaya kaydedip psikologun randevularini dosyaya girmesini,
#dosyadan randevu sorgulamasini ve randevu silmesi gibi temel islemleri yapmasini saglar
#@assignment Odev 2
#@date 21.12.2019
#@author Abdusamet KACI

all: randevu run

randevu: main.o randevu.o myStringControl.o menu.o
	gcc main.o randevu.o myStringControl.o menu.o -o randevu

main.o: main.c
	gcc -c main.c

randevu.o: randevu.c randevu.h
	gcc -c randevu.c

myStringControl.o: myStringControl.c myStringControl.h
	gcc -c myStringControl.c

menu.o: menu.c menu.h
	gcc -c menu.c

clean:
	del *.o randevu.exe

run:
	randevu.exe
