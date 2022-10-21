#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir

g++ ./main.cpp ./optimal_match/*.cpp ./../lib/meta_data.cpp -o run.exe --std=c++11

cd $curDir