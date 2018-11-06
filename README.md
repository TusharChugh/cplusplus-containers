
[![Build Status](https://travis-ci.org/TusharChugh/cplusplus-containers.svg?branch=master)](https://travis-ci.org/TusharChugh/cplusplus-containers)
[![Coverage Status](https://coveralls.io/repos/github/TusharChugh/cplusplus-containers/badge.svg?branch=master)](https://coveralls.io/github/TusharChugh/cplusplus-containers?branch=master)

## Resolve Issues

### update cmake
[help](https://www.claudiokuenzler.com/blog/755/install-upgrade-cmake-3.10.1-ubuntu-14.04-trusty-alternatives#.W9zw2XXwbCI)
1. wget https://cmake.org/files/v3.12/cmake-3.12.4.tar.gz
2. tar -xvzf cmake-3.12.4.tar.gz
3. cd cmake-3.12.4
4. ./configure
5. make
6. sudo make install
7. sudo update-alternatives --install /usr/bin/cmake cmake /usr/local/bin/cmake 1 --force
8. cmake --version

### Update gcc
1. sudo add-apt-repository ppa:ubuntu-toolchain-r/test
2. sudo apt update
3. sudo apt install gcc-6
4. sudo apt install g++-6
5. sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-6 