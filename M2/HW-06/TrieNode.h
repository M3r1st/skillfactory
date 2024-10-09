#pragma once

#include <string>

struct TrieNode {
    TrieNode* child[26];
    bool bEOW;

    TrieNode();
    void insertKey(TrieNode* root, const std::string& key);
    void completeKey(TrieNode* root, const std::string& key, const int limit = 10);
private:
    void completeKeyRecursive(TrieNode* node, std::string &key, const int limit, int& cnt);
};
