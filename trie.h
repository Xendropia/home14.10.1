#ifndef TRIE_H
#define TRIE_H


#include <iostream>
#include <vector>
#include <string>

struct TrieNode {
    TrieNode* children[26];  // Для английского алфавита
    bool isEndOfWord;
};

TrieNode* createNode();
void insertWord(TrieNode* root, const std::string& word);
void searchWords(TrieNode* root, const std::string& prefix, std::vector<std::string>& suggestions);
void findAllWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions);


#endif //TRIE_H
