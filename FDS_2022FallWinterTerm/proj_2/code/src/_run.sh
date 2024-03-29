#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir

# Judgement

echo "<<< Judging... >>>"

mv ./solver/run.exe ./judger/solver.exe
bash ./judger/_judge.sh

echo "<<< Finish! >>>"

cd $curDir