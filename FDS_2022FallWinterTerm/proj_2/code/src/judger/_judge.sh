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
    echo ./test_data/$section > cache
    python3  ./painter/painter.py < cache

done

rm cache

echo "  <<< Finish! >>>"

cd $curDir