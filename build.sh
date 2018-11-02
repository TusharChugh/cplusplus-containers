#!/bin/bash

echo "Environment: `uname -a`"
echo "Compiler: `$CXX --version`"


rm -r build
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=ON -DBUILD_TESTS=ON .. && make
make test
make string
cd ..
codecov -t 6cab29fe-1861-468f-903e-61e4fc96107e -X gcov