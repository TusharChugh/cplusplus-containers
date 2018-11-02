cmake_minimum_required(VERSION 2.8)
project(container)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES string/String.cpp)
add_library(container STATIC ${SOURCE_FILES})