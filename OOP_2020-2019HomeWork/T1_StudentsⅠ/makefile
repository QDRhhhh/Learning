run.exe : main.o studentsClass.o
	g++ -o run.exe main.o studentsClass.o
main.o : main.cpp studentsClass.h
	g++ -c main.cpp
studentsClass.o : studentsClass.cpp studentsClass.h
	g++ -c studentsClass.cpp
clean :
	rm main.o studentsClass.o run.exe