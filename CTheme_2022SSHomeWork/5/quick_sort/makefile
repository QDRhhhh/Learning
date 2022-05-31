run.exe : main.o myAlgorithm.o
	gcc -o run.exe main.o myAlgorithm.o
main.o : main.c myAlgorithm.h
	gcc -c main.c
myAlgorithm.o : myAlgorithm.c myAlgorithm.h
	gcc -c myAlgorithm.c

clean :
	-rm run.exe *.o *.gch