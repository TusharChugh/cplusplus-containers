#include <gtest/gtest.h>
#include "forward_list/Forward_list.h"
#include <forward_list>

TEST(FORWARD_LIST, ITERATOR) {
    STLContainer::forward_list<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);
    auto iterator_begin = int_list.begin();
    auto iterator_end = int_list.end();
    ASSERT_EQ(*iterator_begin, 2);
    ASSERT_EQ(*iterator_end, NULL);
}

TEST(FORWARD_LIST, CONST_ITERATOR) {
    STLContainer::forward_list<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);
    auto iterator_begin = int_list.begin();
    auto iterator_end = int_list.end();
    ASSERT_EQ(*iterator_begin, 2);
    ASSERT_EQ(*iterator_end, NULL);
}

TEST(FORWARD_LIST, ITERATOR_PLUS) {
    STLContainer::forward_list<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);

    std::forward_list<int> ref_int_list;
    ref_int_list.push_front(
    ref_int_list.push_front(2);

    STLContainer::forward_list<int>::iterator list_iterator = int_list.begin();
    std::forward_list<int>::iterator ref_list_iterator;
    for(ref_list_iterator = ref_int_list.begin();
        list_iterator != int_list.end() && ref_list_iterator != ref_int_list.end(); ++list_iterator, ++ref_list_iterator) {
        ASSERT_EQ(*ref_list_iterator, *list_iterator);
    }
}

TEST(FORWARD_LIST, ITERATOR_PLUS_POST) {
    STLContainer::forward_list<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);

    std::forward_list<int> ref_int_list;
    ref_int_list.push_front(1);
    ref_int_list.push_front(2);

    STLContainer::forward_list<int>::iterator list_iterator = int_list.begin();
    std::forward_list<int>::iterator ref_list_iterator;
    for(ref_list_iterator = ref_int_list.begin();
        list_iterator != int_list.end() && ref_list_iterator != ref_int_list.end(); list_iterator++, ref_list_iterator++) {
        ASSERT_EQ(*ref_list_iterator, *list_iterator);
    }
}

TEST(FORWARD_LIST, AUTO_ITERATOR_AU_Test) {
    STLContainer::forward_list<int> int_list;
    int_list.push_front(1);
    int_list.push_front(2);
    int_list.push_front(3);
    int_list.push_front(4);
    int_list.push_front(5);

    std::forward_list<int> ref_int_list;
    ref_int_list.push_front(1);
    ref_int_list.push_front(2);
    size_t ref_index = 0;

    for(auto element: int_list) {
        std::cout<<element<<" ";
    }std::cout<<std::endl;
}