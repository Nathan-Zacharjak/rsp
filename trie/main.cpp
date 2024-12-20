#include "trie.h"

int main(int argc, char const *argv[])
{
    Trie trie;

    trie.Insert("");
    trie.Insert("Hello");
    trie.Insert("Hello");
    trie.Insert("Helloo");
    trie.Insert("Hell");

    trie.Find("Hello");
    trie.Find("");
    trie.Find("H");
    trie.Find("Hell");
    trie.Find("Helloo");
    trie.Find("Hellooo");

    return 0;
}