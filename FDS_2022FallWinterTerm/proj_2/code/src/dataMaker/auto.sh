#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir/utils

bash _setup.sh
bash _run.sh

cd $curDir