#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir

bash ./src/_compile.sh
bash ./src/_run.sh

cd $curDir