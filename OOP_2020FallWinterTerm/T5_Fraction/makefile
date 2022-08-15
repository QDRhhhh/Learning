run.exe : ./src/main.o ./src/fractionClass.o
	g++ -o run.exe ./src/main.o ./src/fractionClass.o
main.o : ./src/main.cpp ./src/fractionClass.h
	g++ -c ./src/main.cpp ./src/fractionClass.h -o ./src/main.o
fractionClass.o : ./src/fractionClass.cpp ./src/fractionClass.h
	g++ -c ./src/fractionClass.cpp ./src/fractionClass.h -o ./src/fractionClass.o
clean :
	rm ./src/main.o ./src/fractionClass.o run.exe