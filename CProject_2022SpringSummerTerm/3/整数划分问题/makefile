run.exe	: main.o split.o
	gcc -o run.exe main.o split.o
main.o : ./src/main.c ./src/split.h
	gcc -c ./src/main.c
split.o : ./src/split.c ./src/split.h
	gcc -c ./src/split.c
clean :
	-rm *.o *.gch *.exe