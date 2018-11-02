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
codecov -t 029bebf0-142f-4f99-8449-ef1fd702274c -X gcov