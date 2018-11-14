#include "bst/Bst_simple.h"
#include <gtest/gtest.h>

TEST( BST_SIMPLE, EMPTY_TEST ) {
    STLContainer::bst input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
  //  ASSERT_EQ( input.begin(), input.end() );
}

TEST( BST_SIMPLE, INSERT_ONE_ELEMENT ) {
    STLContainer::bst input;
    ASSERT_TRUE( input.empty() );
    ASSERT_EQ( 0, input.size() );
    input.insert( 1 );
}

TEST( BST_SIMPLE, INSERT_FIVE_ELEMENT ) {
    STLContainer::bst input;
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

TEST( BST_SIMPLE, INSERT_FIVE_ELEMENT_TRUE_INSERT ) {
    STLContainer::bst input;
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

TEST( BST_SIMPLE, FOR_EACH_TEST ) {
    STLContainer::bst input;
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

TEST( BST_SIMPLE, LVALUE_REF_TEST ) {
    STLContainer::bst input;
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

TEST( BST_SIMPLE, DUPLICATES_FIVE ) {
    STLContainer::bst input;
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

TEST( BST_SIMPLE, FIND_TEST ) {
    STLContainer::bst input;
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

//TEST( BST_SIMPLE, INITIALIZER_LIST ) {
//    STLContainer::bsts input = {3, 2, 5, 4, 1};
//
//    ASSERT_EQ( 1, *input.begin() );
//    ASSERT_EQ( 5, input.size() );
//
//    std::vector<int> output = {1, 2, 3, 4, 5};
//    for ( auto& val : output ) {
//        ASSERT_EQ( val, *input.find( val ) );
//    }
//}

TEST( BST_SIMPLE, COPY_CONSTRUCTOR ) {
    STLContainer::bst input = {3, 2, 5, 4, 1};

    auto input_copy( input );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input_copy.find( val ) );
    }
}

TEST( BST_SIMPLE, MOVE_CONSTRUCTOR ) {
    STLContainer::bst input = {3, 2, 5, 4, 1};

    auto input_copy( std::move( input ) );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input_copy.find( val ) );
    }
}

TEST( BST_SIMPLE, COPY_ASSIGNMENT ) {
    STLContainer::bst input = {3, 2, 5, 4, 1};

    auto input_copy = std::move( input );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input_copy.find( val ) );
    }
}

TEST( BST_SIMPLE, MOVE_ASSIGNMENT ) {
    STLContainer::bst input = {3, 2, 5, 4, 1};

    auto input_copy = std::move( input );

    std::vector<int> output = {1, 2, 3, 4, 5};
    for ( auto& val : output ) {
        ASSERT_EQ( val, *input_copy.find( val ) );
    }
}

TEST( BST_SIMPLE, INORDER_TEST ) {
    STLContainer::bst input        = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    std::vector<int> expected_output = {20, 30, 35, 40, 45, 50, 55, 60, 70};

    auto ex_out_it = expected_output.begin();

    for ( auto in_it : input ) {
        ASSERT_EQ( *( ex_out_it++ ), in_it );
    }
}


//TEST( BST_SIMPLES, EARSE) {
//    STLContainer::bsts input  = {50, 40, 60, 30, 45, 55, 70, 20, 35};
//    std::vector<int> expected_output = {40, 30, 20, 35};
//
//    for ( auto in_it = input.begin(); in_it!= input.end();) {
//        if(*in_it >= 42)
//            input.erase(in_it);
//        ++in_it;
//    }
//
//    for ( auto in_it : input ) {
//        std::cout<< in_it<<std::endl;
//    }
//
//    auto ex_out_it = expected_output.begin();
//    for ( auto in_it : input ) {
//        ASSERT_EQ( *( ex_out_it++ ), in_it );
//    }
//}

TEST( BST_SIMPLE, ERASE_LEAF) {
    STLContainer::bst input  = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    input.erase(input.find(45));

//    for ( auto in_it : input ) {
//        std::cout<< in_it<<std::endl;
//    }
    std::vector<int> expected_output = {20, 30, 35, 40, 50, 55, 60, 70};

    auto ex_out_it = expected_output.begin();

    for ( auto in_it : input ) {
        ASSERT_EQ( *( ex_out_it++ ), in_it );
    }
}

TEST( BST_SIMPLE, ERASE_LSUB_RSUB) {
    STLContainer::bst input  = {50, 40, 60, 30, 45, 55, 70, 20, 35};
    input.erase(input.find(40));

    std::vector<int> expected_output = {20, 30, 35, 45, 50, 55, 60, 70};

    auto ex_out_it = expected_output.begin();

    for ( auto in_it : input ) {
        ASSERT_EQ( *( ex_out_it++ ), in_it );
    }
}

TEST( BST_SIMPLE, ERASE_LEFTRIGHT) {
    STLContainer::bst input  = {50, 40, 60, 30, 45, 55, 58, 70, 20, 35};
    input.erase(input.find(55));

    std::vector<int> expected_output = {20, 30, 35, 40, 45, 50, 58, 60, 70};

    auto ex_out_it = expected_output.begin();

    for ( auto in_it : input ) {
        ASSERT_EQ( *( ex_out_it++ ), in_it );
    }
}

TEST( BST_SIMPLE, ERASE_RIGHTRIGHT) {
    STLContainer::bst input  = {50, 40, 60, 30, 45, 55, 70, 80, 20, 35};
    input.erase(input.find(70));

    std::vector<int> expected_output = {20, 30, 35, 40, 45, 50, 55, 60, 80};

    auto ex_out_it = expected_output.begin();

    for ( auto in_it : input ) {
        ASSERT_EQ( *( ex_out_it++ ), in_it );
    }
}

TEST( BST_SIMPLE, ERASE_RIGHTLEFT) {
    STLContainer::bst input  = {50, 40, 60, 30, 45, 42, 55, 70, 20, 35};
    input.erase(input.find(45));

    std::vector<int> expected_output = {20, 30, 35, 40, 42, 50, 55, 60, 70};

    auto ex_out_it = expected_output.begin();

    for ( auto in_it : input ) {
        ASSERT_EQ( *( ex_out_it++ ), in_it );
    }
}

TEST( BST_SIMPLE, ERASE_LEFTLEFT) {
    STLContainer::bst input  = {50, 40, 60, 30, 45, 55, 70, 20, 35, 12};
    input.erase(input.find(20));
    
    std::vector<int> expected_output = {12, 30, 35, 40, 45, 50, 55, 60, 70};

    auto ex_out_it = expected_output.begin();

    for ( auto in_it : input ) {
        ASSERT_EQ( *( ex_out_it++ ), in_it );
    }
}