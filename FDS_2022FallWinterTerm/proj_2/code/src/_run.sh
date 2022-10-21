#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir

# setup
echo "<<< Compiling solver... >>>"
bash ./solver/_setup.sh
echo "<<< Finish! >>>"

echo "<<< Compiling judger... >>>"
bash ./judger/_setup.sh
echo "<<< Finish! >>>"

echo "<<< Judging... >>>"

mv ./solver/run.exe ./judger/solver.exe
bash ./judger/_judge.sh

echo "<<< Finish! >>>"

cd $curDir