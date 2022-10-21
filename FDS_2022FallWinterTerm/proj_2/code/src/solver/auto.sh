#! /bin/bash

# This file is used to automate the build and run work in debug workings.
# It might be useless in your environment.

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

cd $workDir
bash _setup.sh
bash _test.sh

cd $curDir