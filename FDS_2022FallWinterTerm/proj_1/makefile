method = N3

run.exe: main.o $(method).o
	gcc -o run.exe ./src/main.o ./src/$(method).o

main.o: ./src/main.c ./src/matrix_utils.h ./src/$(method).h
	gcc -c ./src/main.c -o ./src/main.o
$(method).o: ./src/$(method).c ./src/$(method).h ./src/matrix_utils.h ./src/helper/CNewbieHelper.h
	gcc -c ./src/$(method).c -o ./src/$(method).o
clean:
	- rm ./src/*.o ./*.exe

compile_data_maker:
	g++ ./data_maker/maker.cpp -o data_maker.exe