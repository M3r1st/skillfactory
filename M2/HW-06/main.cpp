#include <iostream>
#include <string>
#include <vector>

#include "TrieNode.h"

int main()
{
    TrieNode* root = new TrieNode();
    std::vector<std::string> words;
    {
        std::cout << "Enter dictionary: " << std::endl;
        int n;
        std::cin >> n;
        std::string s;
        for (int i = 0; i < n; i++) {
            std::cin >> s;
            words.push_back(s);
        }
    }

    for (const std::string& s : words) {
        root->insertKey(root, s);
    }

    while (true) {
        std::cout << "Enter your word: " << std::endl;
        std::string s;
        std::cin >> s;
        for (char c : s) {
            if (!('a' <= c && c <= 'z')) {
                return 0;
            }
        }
        std::cout << "Suggested words: " << std::endl;
        root->completeKey(root, s);
        std::cout << std::endl;
    }

    return 0;
}
