#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

# compile
cd $workDir

mkdir -p test_data || true

for section in `cat .section_list`
do
    g++ section_$section/maker.cpp ../lib/meta_data.cpp --std=c++11 -O3 -o $section.exe 
done

cd $curDir