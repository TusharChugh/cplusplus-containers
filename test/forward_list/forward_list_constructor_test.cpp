#include <forward_list>
#include "forward_list/Forward_list.h"
#include <gtest/gtest.h>

TEST(FORWARD_LIST, INTTEST) {
    STLContainer::forward_list<int> int_list;

    for (int i = 1; i <= 5; ++i){
        int_list.push_front(i);
        ASSERT_EQ(i, int_list.front());
    }
}
TEST(FORWARD_LIST, INTTEST1) {
    STLContainer::forward_list<int> int_list;
    int_list.push_front(2);
    int_list.push_front(1);
    ASSERT_EQ(1, int_list.front());
    int_list.pop_front();
    ASSERT_EQ(2, int_list.front());
}

TEST(FORWARD_LIST, STRINGTEST) {
        std::forward_list<std::string> ref_string_list;
        ref_string_list.push_front("Hello");
        ref_string_list.push_front("World");

        STLContainer::forward_list<std::string> string_list;
        string_list.push_front("Hello");
        string_list.push_front("World");

    for (int i = 1; i <= 2; ++i){
        ASSERT_EQ(ref_string_list.front(), string_list.front());
        string_list.pop_front();
        ref_string_list.pop_front();
    }
}
