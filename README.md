
[![Build Status](https://travis-ci.org/TusharChugh/cplusplus-containers.svg?branch=master)](https://travis-ci.org/TusharChugh/cplusplus-containers)


## update cmake
[help](https://www.claudiokuenzler.com/blog/755/install-upgrade-cmake-3.10.1-ubuntu-14.04-trusty-alternatives#.W9zw2XXwbCI)
1. wget https://cmake.org/files/v3.12/cmake-3.12.4.tar.gz
2. tar -xvzf cmake-3.12.4.tar.gz
3. cd cmake-3.12.4
4. ./configure
5. make
6. sudo make install
7. sudo update-alternatives --install /usr/bin/cmake cmake /usr/local/bin/cmake 1 --force
8. cmake --version