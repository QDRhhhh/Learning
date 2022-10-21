#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

# run and move the data
for section in A
do
    cd $workDir/section_$section
    ./section_$section.exe 1 4 4
    mv ./test_data.in $workDir/test_data/A.in
    mv ./test_data.info $workDir/test_data/A.info
done

cd $curDir