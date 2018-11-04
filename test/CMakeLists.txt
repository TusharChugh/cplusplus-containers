# we use this to get code coverage
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()


file(GLOB TEST_FILES ${PROJECT_SOURCE_DIR}/test/string/*.cpp)


add_executable(unittest_container unit_tests.cpp ${TEST_FILES})
#add_executable(unittest_container string/unit_tests.cpp ${TEST_FILES})
target_link_libraries(unittest_container gtest_main container pthread)

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unittest_container
)
