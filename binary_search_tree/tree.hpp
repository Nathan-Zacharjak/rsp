#ifndef TREE_HPP
#define TREE_HPP

#include <bits/unique_ptr.h>

struct Node
{
    int data = 0;
    Node *parent;
    std::unique_ptr<Node> left = nullptr;
    std::unique_ptr<Node> right = nullptr;
};

typedef std::unique_ptr<Node> NodePtr;

class Tree
{
private:
    NodePtr root = nullptr;

    void InsertNodeHelper(int data, Node *currentNode, Node *currentParent, bool isLeftOfParent);
    void PrintTreeHelper(Node *currentNode);

    void Delete0ChildNode(NodePtr nodeToDelete);
    void Delete1ChildNode(NodePtr nodeToDelete);
    void Delete2ChildNode(NodePtr nodeToDelete);

public:
    Tree() = default;

    void InsertNode(int data);
    void PrintTree(void);
    Node *SearchTree(int data, bool findParent = false);
    void DeleteNode(int data);

    virtual ~Tree() = default;
};

#endif