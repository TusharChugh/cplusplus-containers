#pragma once

#include <unordered_map>
#include <string>
#include <memory>

namespace STLContainer {
    class Trie {
        struct TrieNode {
            bool _is_word;
            std::unordered_map<char, TrieNode *> _children;

            explicit TrieNode(bool is_word = false,
                              std::unordered_map<char, TrieNode *> children = std::unordered_map<char, TrieNode *> {}) :
                    _is_word(is_word), _children(std::move(children)) {}
        };

        std::unique_ptr<TrieNode> startNode;

    public:
        /** Initialize */
        Trie();

        /** Inserts a word into the trie. */
        void insert(std::string word);

        /** Returns if the word is in the trie. */
        bool search(std::string word);

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(std::string prefix);
    };
} //namespace