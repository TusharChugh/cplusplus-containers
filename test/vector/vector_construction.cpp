#include"vector/Vector.h"
#include<gtest/gtest.h>

TEST(VECTOR, EMPTY_TEST){
    STLContainer:: Vector<int> input;
    ASSERT_TRUE(input.empty());
    ASSERT_EQ(0, input.size());
    //ASSERT_EQ(input.begin(), input.end());
}

TEST(VECTOR, PUSH_BACK){
    STLContainer::Vector<int> input;
    input.push_back(11);
    input.push_back(3);
    input.push_back(4);
    input.push_back(9);
    input.push_back(12);
    ASSERT_EQ(11, *input.begin());
    ASSERT_EQ(12, *(--input.end()));
    ASSERT_EQ(5, input.size());
    std::vector<int> refer_input = {11,3,4,9,12};
    size_t ref_index = 0;
    for(const auto& num: input) {
        ASSERT_EQ(refer_input[ref_index++], num);
    }
}

TEST(VECTOR, POP_BACK){
    STLContainer::Vector<int> input = {11, 3, 4, 9, 12};
    input.pop_back();
    std::vector<int> refer_input = {11,3,4,9};
    size_t ref_index = 0;
    for(const auto& num: input) {
        ASSERT_EQ(refer_input[ref_index++], num);
    }
}

TEST(VECTOR, COPY_CONSTRUCT){
    STLContainer::Vector<int> input1;
    input1.push_back(11);
    input1.push_back(3);
    input1.push_back(4);
    input1.push_back(9);
    input1.push_back(12);
    std::vector<int> refer_input = {11,3,4,9,12};
    STLContainer::Vector<int> input2 (input1);
    size_t ref_index = 0;
    for(const auto& num: input2) {
        ASSERT_EQ(refer_input[ref_index++], num);
    }
}

TEST(VECTOR, CONSTRUCT_COUNT_VALUES){
    STLContainer::Vector<int> input(5,11);
    std::vector<int> refer_input = {11, 11, 11, 11, 11};
    size_t ref_index = 0;
    for(const auto& num: input) {
        ASSERT_EQ(refer_input[ref_index++], num);
    }
}

TEST(VECTOR, INITIALIZER_LIST){
    STLContainer::Vector<int> input = {11, 3, 4, 9, 12};
    ASSERT_EQ(11, *input.begin());
    //ASSERT_EQ(12, *input.end());
    ASSERT_EQ(5, input.size());

    std::vector<int> refer_input = {11,3,4,9,12};
    size_t ref_index = 0;
    for(const auto& num: input) {
        ASSERT_EQ(refer_input[ref_index++], num);
    }
}

TEST(VECTOR, COPY_ASSIGMENT){
    STLContainer::Vector<int> input1;
    input1.push_back(11);
    input1.push_back(3);
    input1.push_back(4);
    input1.push_back(9);
    input1.push_back(12);
    std::vector<int> refer_input = {11,3,4,9,12};
    STLContainer::Vector<int> input2;
    input2 = input1;
    size_t ref_index = 0;
    for(const auto& num: input2) {
        ASSERT_EQ(refer_input[ref_index++], num);
    }
}

TEST(VECTOR, MOVE_CONSTRUCT){
    std::vector<int> refer_input = {11,3,4,9,12};
    STLContainer::Vector<int> input({11,3,4,9,12});
    size_t ref_index = 0;
    for(const auto& num: input) {
        ASSERT_EQ(refer_input[ref_index++], num);
    }
}

TEST(VECTOR, MOVE_ASSIGMENT){
    std::vector<int> refer_input = {11,3,4,9,12};
    STLContainer::Vector<int> input = {11,3,4,9,12};
    size_t ref_index = 0;
    for(const auto& num: input) {
        ASSERT_EQ(refer_input[ref_index++], num);
    }
}

TEST(VECTOR, ELEMENT_ACCESS){
    std::vector<int> refer_input = {11,3,4,9,12};
    STLContainer::Vector<int> input = {11,3,4,9,12};
    size_t ref_index = 0;
    while(ref_index< refer_input.size()) {
        ASSERT_EQ(refer_input[ref_index++], input[ref_index]);
    }
    ASSERT_EQ(11, input.front());
    ASSERT_EQ(12, input.back());
}

TEST(VECTOR, ITERATOR){
    std::vector<int> refer_input = {11,3,4,9,12};
    STLContainer::Vector<int> input = {11,3,4,9,12};
    STLContainer::Vector<int> input_compare = {11,3,4,9,12};
    ASSERT_EQ(*refer_input.begin(), *input.begin());
    ASSERT_EQ(*(++refer_input.begin()), *(++input.begin()));
    ASSERT_EQ(*(refer_input.begin()++), *(input.begin()++));
    ASSERT_EQ(*(--refer_input.end()), *(--input.end()));
    ASSERT_EQ(input.begin() == input.begin(), true);
    ASSERT_EQ(input.begin() != input.begin(), false);
    ASSERT_EQ(input.begin() == input_compare.begin(), false);
    ASSERT_EQ(input.begin() != input_compare.begin(), true);
}

TEST(VECTOR, CLEAR){
    std::vector<int> refer_input = {11,3,4,9,12};
    STLContainer::Vector<int> input = {11,3,4,9,12};
    input.clear();
    ASSERT_EQ(refer_input.capacity(), input.capacity());
}
