#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir

# setup
echo "Initializing..."
sh ./dataMaker/_setup.sh
sh ./solver/_setup.sh
mkdir -p ./judger/test_data || true
echo "Success!"

# make data
echo "Making test data..."
bash ./dataMaker/_run.sh
mv ./dataMaker/test_data/* ./judger/test_data/
echo "Success!"

# test
echo "Testing..."
cd ./solver
for section in A
do  
    echo " - Testing in secontion $section..."
    ./run.exe < $workDir/judger/test_data/$section.in > $workDir/judger/test_data/$section.out
    echo " - Accept!"
done

cd $curDir