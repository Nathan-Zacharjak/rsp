#include "trie.h"
#include <string>
#include <bits/unique_ptr.h>
#include <iostream>
#include <algorithm>

using std::string, std::cout;

void Trie::Insert(string word)
{
    cout << "=== Inserting: " << word << " ===\n";

    if (word.empty())
    {
        std::cerr << "Tried to insert empty word!" << '\n';
        return;
    }

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    TrieNode *currentNode = _root.get();

    for (const auto &letter : word)
    {
        int index = letter - 'a';

        auto childNode = currentNode->children.at(index).get();
        cout << letter << " " << index << "\n";

        if (childNode == nullptr)
        {
            currentNode->children.at(index) = std::make_unique<TrieNode>();
            currentNode = currentNode->children.at(index).get();
            cout << "Made new node!" << "\n";
        }
        else
        {
            currentNode = childNode;
            cout << "Traversing existing node" << "\n";
        }
    }

    currentNode->wordEnd = true;
}