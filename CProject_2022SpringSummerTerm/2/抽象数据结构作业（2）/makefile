run.exe : main.o linkedlist.o
	gcc -o run.exe main.o linkedlist.o
main.o : main.c linkedlist.h
	gcc -c main.c
linkedlist.o : linkedlist.c linkedlist.h
	gcc -c linkedlist.c

clean :
	rm run.exe *.o *.h.gch