#include <iostream>
#include "trie.h"

int main() {
    TrieNode* root = createNode();

    insertWord(root, "apple");
    insertWord(root, "application");
    insertWord(root, "apricot");
    insertWord(root, "ball");
    insertWord(root, "baby");
    insertWord(root, "bed");

    while (true) {
        std::vector<std::string> suggestions;
        std::string prefix;

        std::cout << "Enter a prefix (or type 'exit' to quit): ";
        std::cin >> prefix;

        if (prefix == "exit") {
            break;
        }

        searchWords(root, prefix, suggestions);

        std::cout << "Suggestions:" << std::endl;
        for (const std::string& word : suggestions) {
            std::cout << word << std::endl;
        }
    }
    return 0;
}
