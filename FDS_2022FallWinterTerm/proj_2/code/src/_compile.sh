#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir

# Setup

echo "<<< Compiling solver... >>>"
bash ./solver/_setup.sh
echo "<<< Finish! >>>"

echo "<<< Compiling judger... >>>"
bash ./judger/_setup.sh
echo "<<< Finish! >>>"

cd $curDir