#include <trie/Trie.h>
#include <gtest/gtest.h>

TEST(TRIE_CONSTRUCTION, INSERT_SEARCH) {
    STLContainer::Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("cat");
    ASSERT_TRUE(trie.search("apple"));
    ASSERT_TRUE(trie.search("banana"));
    ASSERT_TRUE(trie.search("cat"));
    ASSERT_FALSE(trie.search("dog"));
    ASSERT_FALSE(trie.search("app"));
}

TEST(TRIE_STARTSWITH, STARTSWITH) {
    STLContainer::Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("cat");
    ASSERT_TRUE(trie.startsWith("apple"));
    ASSERT_TRUE(trie.startsWith("banana"));
    ASSERT_TRUE(trie.startsWith("cat"));
    ASSERT_FALSE(trie.startsWith("dog"));
    ASSERT_TRUE(trie.startsWith("app"));
    ASSERT_TRUE(trie.startsWith("a"));
    ASSERT_TRUE(trie.startsWith("b"));
    ASSERT_TRUE(trie.startsWith("c"));
    ASSERT_TRUE(trie.startsWith("ca"));
}