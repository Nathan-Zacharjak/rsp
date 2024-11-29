#ifndef TREE_HPP
#define TREE_HPP

// #include "tree_node.hpp"
enum class TreePrintOrder
{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER
};

struct TreeNode
{
    int data = 0;
    TreeNode *parent = nullptr;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

class Tree
{
private:
    TreeNode *root = nullptr;

    void InsertNodeHelper(int data, TreeNode *currentNode, TreeNode *currentParent);

public:
    Tree() = default;

    void InsertNode(int data);
    void PrintTree(TreePrintOrder order = TreePrintOrder::IN_ORDER);
    TreeNode *SearchTree(int data);
    void DeleteNode(int data);

    virtual ~Tree() = default;
};

#endif