run.exe : teach.o genlib.o exception.o strlib.o simpio.o graphics.o random.o
	gcc -o run.exe teach.o genlib.o exception.o strlib.o simpio.o graphics.o random.o -lm

teach.o : teach.c genlib.h strlib.h simpio.o
	gcc -c teach.c

genlib.o: genlib.c genlib.h exception.h gcalloc.h
	gcc -c genlib.c

exception.o: exception.c exception.h genlib.h
	gcc -c exception.c

strlib.o: strlib.c strlib.h genlib.h
	gcc -c strlib.c

simpio.o: simpio.c simpio.h strlib.h genlib.h
	gcc -c simpio.c

graphics.o: graphics.c graphics.h genlib.h
	gcc -c graphics.c

random.o: random.c random.h genlib.h
	gcc -c random.c

clean :
	rm *.o *.exe
