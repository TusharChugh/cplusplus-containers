#include <trie/Trie.h>

/** Initialize your data structure here. */
STLContainer::Trie::Trie(){
    startNode = std::make_unique<TrieNode>();
}

/** Inserts a word into the trie. */
void STLContainer::Trie::insert(std::string word) {
    auto node = startNode.get();
    for(auto letter : word) {
        if(node->_children.find(letter) == node->_children.end()) {
            auto child = new TrieNode;
            node->_children.emplace(letter, child);
        }
        node = node->_children.at(letter);
    }
    node->_is_word = true;
}

/** Returns if the word is in the trie. */
bool STLContainer::Trie::search(std::string word) {
    auto node = startNode.get();
    for(auto letter : word) {
        if(node->_children.find(letter) == node->_children.end())
            return false;
        node = node->_children.at(letter);
    }
    return node->_is_word;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool STLContainer::Trie::startsWith(std::string prefix) {
    auto node = startNode.get();
    for(auto letter : prefix) {
        if(node->_children.find(letter) == node->_children.end())
            return false;
        node = node->_children.at(letter);
    }
    return true;
}