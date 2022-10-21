#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

# compile
cd $workDir/utils
g++ -c ./*.cpp --std=c++11
cd $workDir

mkdir -p test_data || true

for section in A
do
    cd $workDir/section_$section/src
    g++ -c ./*.cpp --std=c++11
    cd $workDir/section_$section
    g++ -o section_$section.exe $workDir/section_$section/src/*.o $workDir/utils/*.o
done

cd $curDir