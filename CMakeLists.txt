cmake_minimum_required(VERSION 2.8)
project(container)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/.travis/cmake)

include_directories(include)
add_subdirectory(src)
target_link_libraries(container)

add_subdirectory(test)