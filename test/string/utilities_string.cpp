#include <gtest/gtest.h>
#include <tstring/tstring.h>
#include <string>

std::string string_input3 = "Hello";

TEST(OPERATOR_STRING, FRONT_BACK_TEST1) {
    tlib::tstring input1("Hello");
    ASSERT_EQ(input1.back(), string_input3.back());
    ASSERT_EQ(input1.front(), string_input3.front());
}

TEST(OPERATOR_STRING, EMPTY_TEST1) {
    tlib::tstring input1("Hello");
    ASSERT_FALSE(input1.empty());
}

TEST(OPERATOR_STRING, EMPTY_TEST2) {
    tlib::tstring input1;
    ASSERT_TRUE(input1.empty());
}