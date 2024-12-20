#include "trie.h"

int main(int argc, char const *argv[])
{
    Trie trie;

    trie.Insert("");
    trie.Insert("Hello");
    trie.Insert("Hello");
    trie.Insert("Helloo");
    trie.Insert("Hell");
    trie.Insert("HellNo");
    trie.Insert("Big");
    trie.Insert("Biggest");

    trie.Find("Hello");
    trie.Find("");
    trie.Find("H");
    trie.Find("Hell");
    trie.Find("Helloo");
    trie.Find("Hellooo");
    trie.Find("B");
    trie.Find("Big");
    trie.Find("Bigg");
    trie.Find("Biggu");
    trie.Find("Biggest");
    trie.Find("Biggestt");

    trie.FindPrefix("Hello");
    trie.FindPrefix("");
    trie.FindPrefix("H");
    trie.FindPrefix("E");
    trie.FindPrefix("HellN");
    trie.FindPrefix("B");
    trie.FindPrefix("Big");
    trie.FindPrefix("Biges");
    trie.FindPrefix("Bigges");
    trie.FindPrefix("Biggest");

    return 0;
}