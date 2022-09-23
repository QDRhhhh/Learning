echo "You are supposed to run this scrips with bash!"

# =============================================================
# Compile and link the C codes.

echo "Start compiling algorithm codes!"

gcc -c ./src/main.c -o ./src/main.o

for METHOD in N3 N4 N6
do
    gcc -c ./src/$METHOD.c -o ./src/$METHOD.o
    gcc -o $METHOD.exe ./src/main.o ./src/$METHOD.o
done

echo "Done!"

# =============================================================
# Compile the data maker and generate the test data.

echo "Start generating test data!"

g++ ./data_maker/maker.cpp -o data_maker.exe -std=c++11

for SIZEN in 5 10 15 20 25 30 35 40 50 60 80 100
do
    ./data_maker.exe $SIZEN $SIZEN
    mv test_data.txt ./data_maker/$SIZEN.in
done

echo "Done!"

# =============================================================
# Test the codes and store the necessary data.

echo "Start testing codes! Don't edit output.txt!"

rm output.txt || true
touch output.txt
rm output_details.txt || true
touch output_details.txt
rm ./data_maker/*.out || true

for SIZEN in 5 10 15 20 25 30 35 40 50 60 80 100
do
    for METHOD in N3 N4 N6
    do
        # Redirect the input and the output, store the output particularly.
        ./$METHOD.exe < ./data_maker/$SIZEN.in >> ./data_maker/$SIZEN.$METHOD.out
    done

    echo "Check out the answer while N = $SIZEN!"
    # Compare the three output and give the judgment.
    if diff ./data_maker/$SIZEN.N3.out ./data_maker/$SIZEN.N4.out; then
        if diff ./data_maker/$SIZEN.N3.out ./data_maker/$SIZEN.N6.out; then
            echo "Accept!"
        else 
            echo "Wrong Answer!"
            exit 0
        fi
    else 
        echo "Wrong Answer!"
        exit 0
    fi
done

# =============================================================
# Draw the figure.

echo "Start drawing figure!"

python ./analyzer/analyze.py

# =============================================================

echo "Every thing done!"