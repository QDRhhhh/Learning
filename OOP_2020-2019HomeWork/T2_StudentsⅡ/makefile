run.exe : ./src/main.o ./src/studentsClass.o
	g++ -o run.exe ./src/main.o ./src/studentsClass.o
main.o : ./src/main.cpp ./src/studentsClass.h
	g++ -c ./src/main.cpp -o ./src/main.o
studentsClass.o : ./src/studentsClass.cpp ./src/studentsClass.h
	g++ -c ./src/studentsClass.cpp -o ./src/studentsClass.o
clean :
	rm ./src/main.o ./src/studentsClass.o run.exe