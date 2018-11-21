#include "queue/Queue.h"
#include <gtest/gtest.h>

TEST( QUEUE, PUSH) {
    STLContainer::queue<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    input.push(17);
    input.push(16);
    input.push(15);
    input.push(14);
    input.push(13);
    input.push(12);
    input.push(11);
    for ( auto val : {17, 16, 15, 14, 13, 12, 11} ) {
        ASSERT_EQ( val, input.front());
        input.pop();
    }
}

TEST( QUEUE, CONSTRUCT) {
    STLContainer::queue<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    input.push(17);
    input.push(16);
    input.push(15);
    input.push(14);
    input.push(13);
    input.push(12);
    input.push(11);
    for ( auto val : {17, 16, 15, 14, 13, 12, 11} ) {
        ASSERT_EQ( val, input.front());
        input.pop();
    }
}

TEST( QUEUE, CONSTRUCT_COPY) {
    STLContainer::queue<int> input;
    input.push(17);
    input.push(16);
    input.push(15);
    input.push(14);
    input.push(13);
    input.push(12);
    input.push(11);
    STLContainer::queue<int> input_copy(input);
    for ( auto val : {17, 16, 15, 14, 13, 12, 11} ) {
        ASSERT_EQ( val, input_copy.front());
        input_copy.pop();
    }
}

TEST( QUEUE, CONSTRUCT_COPY_ASSIGMENT) {
    STLContainer::queue<int> input;
    input.push(17);
    input.push(16);
    input.push(15);
    input.push(14);
    input.push(13);
    input.push(12);
    input.push(11);
    STLContainer::queue<int> input_copy = input;
    for ( auto val : {17, 16, 15, 14, 13, 12, 11} ) {
        ASSERT_EQ( val, input_copy.front());
        input_copy.pop();
    }
}

TEST( QUEUE, CONSTRUCT_ADAPTIVE) {
    std::deque<std::string> dq = {"this", "is", "a", "test","!"};
    STLContainer::queue<std::string> input(dq);
    for ( auto word : dq ) {
        ASSERT_EQ( word, input.front());
        input.pop();
    }
}

TEST( QUEUE, CONSTRUCT_MOVE) {
    std::deque<std::string> dq = {"this", "is", "a", "test","for", "move","constructor"};
    STLContainer::queue<std::string> input_move_from(dq);

    STLContainer::queue<std::string> input_move_to(std::move(input_move_from));

    for ( auto word : dq ) {
        ASSERT_EQ( word, input_move_to.front());
        input_move_to.pop();
    }
}

TEST( QUEUE, SWAP) {
    std::deque<std::string> dq_left = {"this", "is", "left", "side","!"};
    std::deque<std::string> dq_right = {"this", "is", "right", "side","!"};
    STLContainer::queue<std::string> input_left(dq_left);
    STLContainer::queue<std::string> input_right(dq_right);

    input_left.swap(input_right);

    for ( auto word : dq_right ) {
        ASSERT_EQ( word, input_left.front());
        input_left.pop();
    }
}

TEST( QUEUE, EMPLACE) {
    STLContainer::queue<int> input;
    input.emplace(17);
    input.emplace(16);
    input.emplace(15);
    for ( auto val : {17, 16, 15} ) {
        ASSERT_EQ( val, input.front());
        input.pop();
    }
}

TEST( QUEUE, BACK) {
    STLContainer::queue<int> input;
    input.emplace(17);
    input.emplace(16);
    input.emplace(15);
    ASSERT_EQ( 15, input.back());
}