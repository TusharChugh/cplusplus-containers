#include "bst/Bst.h"
#include <gtest/gtest.h>

TEST( BST, EMPTY_TEST ) {
    STLContainer::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    ASSERT_EQ( input.begin(), input.end() );
}

TEST( BST, INSERT_ONE_ELEMENT ) {
    STLContainer::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    input.insert( 1 );
}

TEST( BST, INSERT_FIVE_ELEMENT ) {
    STLContainer::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    ASSERT_EQ( 3, *input.insert( 3 ).first );
    ASSERT_EQ( 2, *input.insert( 2 ).first );
    ASSERT_EQ( 5, *input.insert( 5 ).first );
    ASSERT_EQ( 4, *input.insert( 4 ).first );
    ASSERT_EQ( 1, *input.insert( 1 ).first );

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );

    auto it = input.begin();
    for ( auto val : {1, 2, 3, 4, 5} ) {
        ASSERT_EQ( val, *it++ );
    }
}

TEST( BST, INSERT_FIVE_ELEMENT_TRUE_INSERT ) {
    STLContainer::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    ASSERT_EQ( true, input.insert( 3 ).second );
    ASSERT_EQ( true, input.insert( 2 ).second );
    ASSERT_EQ( true, input.insert( 5 ).second );
    ASSERT_EQ( true, input.insert( 4 ).second );
    ASSERT_EQ( true, input.insert( 1 ).second );

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );

    auto it = input.begin();
    for ( auto val : {1, 2, 3, 4, 5} ) {
        ASSERT_EQ( val, *it++ );
    }
}

TEST( BST, FOR_EACH_TEST ) {
    STLContainer::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    input.insert( 3 );
    input.insert( 2 );
    input.insert( 5 );
    input.insert( 4 );
    input.insert( 1 );

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );
    std::vector<int> output = {1, 2, 3, 4, 5};
    auto output_iter        = output.begin();
    for ( auto& in : input ) {
        ASSERT_EQ( *output_iter++, in );
    }
}

TEST( BST, LVALUE_REF_TEST ) {
    STLContainer::bst<int> input;
    std::vector<int> input_ref = {3, 2, 5, 4, 1};

    for ( auto& in : input_ref ) {
        input.insert( in );
    }

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );
    std::vector<int> output = {1, 2, 3, 4, 5};
    auto output_iter        = output.begin();
    for ( auto& in : input ) {
        ASSERT_EQ( *output_iter++, in );
    }
}

TEST( BST, DUPLICATES_FIVE ) {
    STLContainer::bst<int> input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    ASSERT_EQ( 3, *input.insert( 3 ).first );
    ASSERT_EQ( 2, *input.insert( 2 ).first );
    ASSERT_EQ( 5, *input.insert( 5 ).first );
    ASSERT_EQ( 4, *input.insert( 4 ).first );
    ASSERT_EQ( 1, *input.insert( 1 ).first );

    ASSERT_EQ( 3, *input.insert( 3 ).first );
    ASSERT_EQ( 2, *input.insert( 2 ).first );
    ASSERT_EQ( 5, *input.insert( 5 ).first );
    ASSERT_EQ( 4, *input.insert( 4 ).first );
    ASSERT_EQ( 1, *input.insert( 1 ).first );

    ASSERT_EQ( false, input.insert( 3 ).second );
    ASSERT_EQ( false, input.insert( 2 ).second );
    ASSERT_EQ( false, input.insert( 5 ).second );
    ASSERT_EQ( false, input.insert( 4 ).second );
    ASSERT_EQ( false, input.insert( 1 ).second );

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );

    auto it = input.begin();
    for ( auto val : {1, 2, 3, 4, 5} ) {
        ASSERT_EQ( val, *it++ );
    }
}

TEST( BST, FIND_TEST ) {
    STLContainer::bst<int> input;
    std::vector<int> input_ref = {3, 2, 5, 4, 1};

    for ( auto& in : input_ref ) {
        input.insert( in );
    }

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input.find( val ) );
    }
}

TEST( BST, INITIALIZER_LIST ) {
    STLContainer::bst<int> input = {3, 2, 5, 4, 1};

    ASSERT_EQ( 1, *input.begin() );
    ASSERT_EQ( 5, input.size() );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input.find( val ) );
    }
}

TEST( BST, COPY_CONSTRUCTOR ) {
    STLContainer::bst<int> input = {3, 2, 5, 4, 1};

    auto input_copy( input );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input_copy.find( val ) );
    }
}

TEST( BST, MOVE_CONSTRUCTOR ) {
    STLContainer::bst<int> input = {3, 2, 5, 4, 1};

    auto input_copy( std::move( input ) );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input_copy.find( val ) );
    }
}

TEST( BST, COPY_ASSIGNMENT ) {
    STLContainer::bst<int> input = {3, 2, 5, 4, 1};

    auto input_copy = std::move( input );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input_copy.find( val ) );
    }
}

TEST( BST, MOVE_ASSIGNMENT ) {
    STLContainer::bst<int> input = {3, 2, 5, 4, 1};

    auto input_copy = std::move( input );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input_copy.find( val ) );
    }
}

TEST( BST, INORDER_TEST ) {
    STLContainer::bst<int> input        = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    std::vector<int> expected_output = {20, 30, 35, 40, 45, 50, 55, 60, 70};

    auto ex_out_it = expected_output.begin();

    for ( auto in_it : input ) {
        ASSERT_EQ( *( ex_out_it++ ), in_it );
    }
}