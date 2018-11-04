#!/bin/bash

echo "Environment: `uname -a`"
echo "Compiler: `$CXX --version`"

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=ON -DBUILD_TESTS=ON .. && make
./bin/unittest_container
