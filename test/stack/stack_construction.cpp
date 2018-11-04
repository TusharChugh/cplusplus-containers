#include <stack/Stack.h>
#include <gtest/gtest.h>

TEST(STACK_TEST, THREE_ELEMENTS) {
    STLContainer::Stack<int> input;
    ASSERT_TRUE(input.empty());

    input.push(5);
    input.push(6);
    input.push(7);

    ASSERT_EQ(3, input.size());
    ASSERT_EQ(7, input.top());

    input.pop();

    ASSERT_EQ(2, input.size());
    ASSERT_EQ(6, input.top());

    input.pop();

    ASSERT_EQ(1, input.size());
    ASSERT_EQ(5, input.top());

    input.pop();

    ASSERT_EQ(0, input.size());
    ASSERT_TRUE(input.empty());
}