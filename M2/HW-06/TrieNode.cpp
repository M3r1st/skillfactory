#include "TrieNode.h"

#include <iostream>

TrieNode::TrieNode()
{
    bEOW = false;
    for (int i = 0; i < 26; i++) {
        child[i] = nullptr;
    }
}

void TrieNode::insertKey(TrieNode* root, const std::string& key) {
    TrieNode* node = root;

    for (char c : key) {
        if (node->child[c - 'a'] == nullptr) {
            TrieNode* newNode = new TrieNode();
            node->child[c - 'a'] = newNode;
        }
        node = node->child[c - 'a'];
    }

    node->bEOW = true;
}

void TrieNode::completeKey(TrieNode* root, const std::string& key, const int limit) {

    TrieNode* node = root;

    for (char c : key) {
        if (!('a' <= c && c <= 'z') || node->child[c - 'a'] == nullptr)
            return;

        node = node->child[c - 'a'];
    }

    int temp = 0;
    std::string newKey = key;
    completeKeyRecursive(node, newKey, limit, temp);
}

void TrieNode::completeKeyRecursive(TrieNode* node, std::string &key, const int limit, int& cnt) {
    if (node->bEOW) {
        cnt++;
        std::cout << key << std::endl;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        if (node->child[i - 'a'] != nullptr && cnt < limit) {
            key += (char)(i);
            completeKeyRecursive(node->child[i - 'a'], key, limit, cnt);
            key.pop_back();
        }
    }
}
