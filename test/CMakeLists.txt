include(${PROJECT_SOURCE_DIR}/cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

# we use this to get code coverage
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()


file(GLOB TEST_FILES
        ${PROJECT_SOURCE_DIR}/test/string/*.cpp
        ${PROJECT_SOURCE_DIR}/test/stack/*.cpp
        ${PROJECT_SOURCE_DIR}/test/bst/*.cpp
        ${PROJECT_SOURCE_DIR}/test/trie/*.cpp
        ${PROJECT_SOURCE_DIR}/test/vector/*.cpp
        ${PROJECT_SOURCE_DIR}/test/queue/*.cpp)
        ${PROJECT_SOURCE_DIR}/test/forward_list/*.cpp)


add_executable(unittest_container unit_tests.cpp ${TEST_FILES})
#add_executable(unittest_container string/unit_tests.cpp ${TEST_FILES})
target_link_libraries(unittest_container gtest_main container pthread)

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unittest_container
)
