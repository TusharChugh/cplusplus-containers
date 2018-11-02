#include <gtest/gtest.h>
#include <tstring/tstring.h>
#include <string>

std::string string_input2 = "Hello";

TEST(OPERATOR_STRING, EQUAL_OPERATOR_TEST1) {
    tlib::tstring input1("Hello");
    tlib::tstring input2("Hello");
    ASSERT_TRUE(input1 == input2);
}

TEST(OPERATOR_STRING, NOTEQUAL_OPERATOR_TEST1) {
    tlib::tstring input1("Hello");
    tlib::tstring input2("Hello");
    ASSERT_FALSE(input1 != input2);
}

TEST(OPERATOR_STRING, NOTEQUAL_OPERATOR_TEST2) {
    tlib::tstring input1("Hello");
    tlib::tstring input2("WORLD");
    ASSERT_TRUE(input1 != input2);
}

TEST(OPERATOR_STRING, GREATOR_EQUAL_OPERATOR_TEST1) {
    tlib::tstring input1("Hello");
    tlib::tstring input2("Hello");
    ASSERT_TRUE(input1 >= input2);
}

TEST(OPERATOR_STRING, LESS_EQUAL_OPERATOR_TEST1) {
    tlib::tstring input1("Hello");
    tlib::tstring input2("Hello");
    ASSERT_TRUE(input1 <= input2);
}

TEST(OPERATOR_STRING, GREATOR_OPERATOR_TEST1) {
    tlib::tstring input1("Hello");
    tlib::tstring input2("Hello");
    ASSERT_FALSE(input1 > input2);
}

TEST(OPERATOR_STRING, LESS_OPERATOR_TEST1) {
    tlib::tstring input1("Hello");
    tlib::tstring input2("Hello");
    ASSERT_FALSE(input1 < input2);
}

TEST(OPERATOR_STRING, GREATOR_OPERATOR_TEST2) {
    tlib::tstring input1("Aello");
    tlib::tstring input2("Hello");
    ASSERT_TRUE(input1 < input2);
    ASSERT_FALSE(input1 > input2);
}

TEST(OPERATOR_STRING, GREATOR_EQUAL_OPERATOR_TEST2) {
    tlib::tstring input1("Aello");
    tlib::tstring input2("Hello");
    ASSERT_TRUE(input1 <= input2);
    ASSERT_FALSE(input1 >= input2);
}

TEST(OPERATOR_STRING, ALL_OPERATOR_TEST1) {
    tlib::tstring input1("hello");
    tlib::tstring input2("Hello");
    ASSERT_FALSE(input1 <= input2);
    ASSERT_TRUE(input1 >= input2);
    ASSERT_FALSE(input1 < input2);
    ASSERT_TRUE(input1 > input2);
    ASSERT_FALSE(input1 == input2);
    ASSERT_TRUE(input1 != input2);
}

TEST(OPERATOR_STRING, ALL_OPERATOR_TEST2) {
    tlib::tstring input1("A");
    tlib::tstring input2("a");
    ASSERT_FALSE(input1 == input2);
    ASSERT_TRUE(input1 != input2);
    ASSERT_TRUE(input1 < input2);
    ASSERT_TRUE(input1 <= input2);
    ASSERT_FALSE(input1 > input2);
    ASSERT_FALSE(input1 >= input2);
}