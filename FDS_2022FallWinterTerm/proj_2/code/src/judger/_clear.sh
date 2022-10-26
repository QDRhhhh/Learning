#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

# compile
cd $workDir

rm -r test_data
find . -name "*.o"  | xargs rm -f
find . -name "*.exe"  | xargs rm -f
echo "Clear judger!"

cd $curDir