#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir

g++ ./main.cpp ./optimal_match/*.cpp ./../lib/meta_data.cpp --std=c++11 -O3 -o run.exe

cd $curDir