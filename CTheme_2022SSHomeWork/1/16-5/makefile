run.exe : main.o rational.o
	gcc -o run.exe main.o rational.o
main.o : main.c
	gcc -c main.c
rational.o : rational.c rational.h 
	gcc -c rational.c rational.h
clean : 
	rm main.o rational.o rational.h.gch run.exe