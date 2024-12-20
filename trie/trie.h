#ifndef TRIE_H
#define TRIE_H

#include <bits/unique_ptr.h>
#include <string>
#include <array>

constexpr int ALPHABET_SIZE = 26;

struct TrieNode
{
    std::array<std::unique_ptr<TrieNode>, ALPHABET_SIZE> children{nullptr};
    bool wordEnd{false};
};

class Trie
{
private:
    std::unique_ptr<TrieNode> _root{std::make_unique<TrieNode>()};

    TrieNode *InitSearch(std::string &word);
    TrieNode *GetChild(TrieNode *node, const char letter);
    void MakeChild(TrieNode *node, const char letter);
    unsigned int GetIndex(const char letter);

public:
    Trie() = default;

    void Insert(std::string word);
    bool Find(std::string word);
    bool FindPrefix(std::string prefix);

    virtual ~Trie() = default;
};

#endif