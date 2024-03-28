#include "trie.h"

using namespace std;


void findAllWords(TrieNode* node, const std::string& prefix, std::vector<std::string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            char c = 'a' + i;
            findAllWords(node->children[i], prefix + c, suggestions);
        }
    }
}

TrieNode* createNode() {
    TrieNode* node = new TrieNode;
    for (int i = 0; i < 26; i++) {
        node->children[i] = nullptr;
    }
    node->isEndOfWord = false;
    return node;
}

void insertWord(TrieNode* root, const std::string& word) {
    TrieNode* current = root;
    for (char c : word) {
        int index = c - 'a';  // Для английского алфавита
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

void searchWords(TrieNode* root, const std::string& prefix, std::vector<std::string>& suggestions) {
    TrieNode* current = root;
    for (char c : prefix) {
        int index = c - 'a';  // Для английского алфавита
        if (!current->children[index]) {
            return;  // Префикс не найден
        }
        current = current->children[index];
    }
    // Найден префикс, добавляем все слова с этим префиксом
    findAllWords(current, prefix, suggestions);
}

