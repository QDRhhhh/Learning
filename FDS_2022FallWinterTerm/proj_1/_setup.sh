echo "You are supposed to run this scrips with bash!"

echo "Start compiling algorithm codes!"

gcc -c ./src/main.c -o ./src/main.o

for METHOD in N3 N4 N6
do
    gcc -c ./src/$METHOD.c -o ./src/$METHOD.o
    gcc -o $METHOD.exe ./src/main.o ./src/$METHOD.o
done

echo "Done!"

echo "Start generating test data!"

g++ ./data_maker/maker.cpp -o data_maker.exe

for SIZEN in 5 10 20 30 40 50 60 70 80 90 100
do
    ./data_maker.exe $SIZEN $SIZEN
    mv test_data.txt ./data_maker/$SIZEN.in
done

echo "Done!"

echo "Start testing codes! Don't edit output.txt!"

rm output.txt || true
touch output.txt

for SIZEN in 5 10 20 30 40 50 60 70 80 90 100
do
    for METHOD in N3 N4 N6
    do
        ./$METHOD.exe < ./data_maker/$SIZEN.in
    done
done

python analyze.py

