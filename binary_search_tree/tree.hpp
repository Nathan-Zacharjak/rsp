#ifndef TREE_HPP
#define TREE_HPP

// #include "tree_node.hpp"
#include <bits/unique_ptr.h>

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
    std::unique_ptr<TreeNode> root;

    TreeNode *GetRoot(void);
    void InsertNodeHelper(int data, TreeNode *currentNode, TreeNode *currentParent);
    void PrintTreeHelper(TreeNode *);

public:
    Tree() = default;

    void InsertNode(int data);
    void PrintTree(void);
    TreeNode *SearchTree(int data);
    void DeleteNode(int data);

    virtual ~Tree() = default;
};

#endif