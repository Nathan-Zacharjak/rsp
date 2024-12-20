#include "trie.h"
#include <string>
#include <bits/unique_ptr.h>
#include <iostream>
#include <algorithm>

using std::string, std::cout;

TrieNode *Trie::InitSearch(string &word)
{
    if (word.empty())
    {
        std::cerr << "Tried to use empty word!" << '\n';
        return nullptr;
    }

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    return _root.get();
}

unsigned int Trie::GetIndex(const char letter)
{
    return letter - 'a';
}

TrieNode *Trie::GetChild(TrieNode *node, const char letter)
{
    return node->children.at(GetIndex(letter)).get();
}

void Trie::MakeChild(TrieNode *node, const char letter)
{
    node->children.at(GetIndex(letter)) = std::make_unique<TrieNode>();
}

void Trie::Insert(string word)
{
    cout << "=== Inserting: " << word << " ===\n";

    auto currentNode = InitSearch(word);

    if (currentNode == nullptr)
    {
        return;
    }

    for (const auto &letter : word)
    {
        auto childNode = GetChild(currentNode, letter);
        cout << letter << " " << letter - 'a' << "\n";

        if (childNode == nullptr)
        {
            MakeChild(currentNode, letter);
            currentNode = GetChild(currentNode, letter);
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

bool Trie::Find(string word)
{
    cout << "=== Finding: " << word << " ===\n";

    auto currentNode = InitSearch(word);

    if (currentNode == nullptr)
    {
        return false;
    }

    return false;
}