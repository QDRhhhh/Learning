#! /bin/sh

# This file is used to automate the build and run work in debug workings.
# It might be useless in your environment.

g++ ./main.cpp ./optimal_match/*.cpp --std=c++11
./a.out < 1.in