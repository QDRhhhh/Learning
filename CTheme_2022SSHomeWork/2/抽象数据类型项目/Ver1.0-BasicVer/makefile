run.exe : main.o calculator.o
	gcc -o run.exe main.o calculator.o
main.o : main.c calculator.h
	gcc -c main.c
calculator.o : calculator.c calculator.h 
	gcc -c calculator.c
clean : 
	-rm *.h.gch *.o run.exe 