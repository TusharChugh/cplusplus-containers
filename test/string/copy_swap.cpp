#include <gtest/gtest.h>
#include <string/String.h>
#include <string>

std::string string_ = "Hello";

TEST(COPYSTRING, COPYSTRING_COPY_CONSTRUCTOR_Test) {
    STLContainer::String input1("Hello");
    STLContainer::String input2(input1);
    ASSERT_STREQ(string_.c_str(), input2.c_str());
    ASSERT_STREQ(input2.c_str(), input1.c_str());
}

TEST(STRING_SWAP, STRING_SWAP_ASSIGNMENT_Test) {
    STLContainer::String input1("Hello");
    STLContainer::String input2 = input1;
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), input1.c_str());
}

TEST(STRING_SWAP, STRING_SWAP_NON_EMPTY_ASSIGNMENT_Test) {
    STLContainer::String input1("Hello");
    STLContainer::String input2("World");
    input2 = input1;
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), "Hello");
}

TEST(STRING_SWAP, STRING_CONCAT_OPERATOR_TEST1) {
    STLContainer::String input1("Hello");
    STLContainer::String input2("World");
    input2 += input1;
    //Check if the input1 has not been modified
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), "WorldHello");
}

TEST(STRING_SWAP, STRING_CONCAT_OPERATOR_TEST3) {
    STLContainer::String input1("Hello");
    STLContainer::String input2("World");
    input2 = input1 + input2;
    //Check if the input1 has not been modified
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), "HelloWorld");
}

TEST(STRING_SWAP, STRING_CONCAT_OPERATOR_TEST2) {
    STLContainer::String input1;
    STLContainer::String input2("Hello");
    input2 += input1;
    //Check if the input1 has not been modified
    ASSERT_STREQ(NULL, input1.c_str());
    ASSERT_STREQ(input2.c_str(), "Hello");
}

TEST(STRING_SWAP, STRING_CONCAT_OPERATOR_TEST4) {
    STLContainer::String input1("Hello");
    STLContainer::String input2;
    input2 += input1;
    //Check if the input1 has not been modified
    ASSERT_STREQ(string_.c_str(), input1.c_str());
    ASSERT_STREQ(input2.c_str(), "Hello");
}

TEST(STRING_SWAP, STRING_SWAP_TEST) {
    STLContainer::String input1("Hello");
    STLContainer::String input2("World");
    using std::swap;
    swap(input1, input2);
    ASSERT_STREQ(input1.c_str(), "World");
    ASSERT_STREQ(input2.c_str(), "Hello");
}

TEST(STRING_SWAP, STRING_ACCESS_OPERATOR_TEST) {
    STLContainer::String input1("Hello");
    for(int i = 0; i < string_.length(); i++)
        ASSERT_EQ(string_[i], input1[i]);
}
