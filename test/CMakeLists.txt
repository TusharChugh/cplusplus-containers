cmake_minimum_required(VERSION 2.8)
project(container_test)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

file(GLOB TEST_FILES ${PROJECT_SOURCE_DIR}/test/string/*.cpp)

add_executable(container_test  unit_tests.cpp ${TEST_FILES})
target_link_libraries(container_test ${GTEST_LIBRARIES} container pthread)

include(CodeCoverage)
setup_target_for_coverage(container_coverage container_test coverage)
