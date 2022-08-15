objects = main.o calculator.o myFunction.o

run.exe : $(objects)
	gcc -o run.exe $(objects) -lm

main.o : main.c calculator.h
	gcc -c main.c
calculator.o : calculator.c calculator.h 
	gcc -c calculator.c
myFunction.o : myFunction.c myFunction.h
	gcc -c myFunction.c

clean : 
	-rm *.h.gch *.o run.exe 