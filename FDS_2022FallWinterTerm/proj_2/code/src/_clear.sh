#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir

bash ./dataMaker/_clear.sh
bash ./solver/_clear.sh
bash ./judger/_clear.sh

cd $curDir