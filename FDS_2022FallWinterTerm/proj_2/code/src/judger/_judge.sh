#! /bin/bash

# get current direction
curDir=`pwd`
# get shell direction
workDir=$(cd "$(dirname "$0")";pwd)

# compile
cd $workDir

mkdir -p test_data || true

echo "  <<< Generating data... >>>"

for section in `cat .section_list`
do
    echo "   = Section [ $section ]..."
    # Generate data.
    ./$section.exe
    # Move data.
    mv test_data.in ./test_data/$section.in
    mv test_data.info ./test_data/$section.info
    echo "   = Done."
done

echo "  <<< Finish! >>>"

echo "  <<< Testing... >>>"

for section in `cat .section_list`
do
    echo "   = Section [ $section ]..."
    ./solver.exe < ./test_data/$section.in > ./test_data/$section.out
    
    if test `./judger.exe < $section` = "pass" then
        echo "   = Accept! OwO"
    else
        echo "   = Unaccept! QAQ"
        exit 0
    fi
done

echo "  <<< Finish! >>>"

cd $curDir