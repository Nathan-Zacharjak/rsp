#ifndef TREE_HPP
#define TREE_HPP

// #include "tree_node.hpp"
#include <bits/shared_ptr.h>

struct TreeNode
{
    int data = 0;
    std::shared_ptr<TreeNode> parent = nullptr;
    std::shared_ptr<TreeNode> left = nullptr;
    std::shared_ptr<TreeNode> right = nullptr;
};

typedef std::shared_ptr<TreeNode> TreeNodePtr;

class Tree
{
private:
    TreeNodePtr root = nullptr;

    void InsertNodeHelper(int data, TreeNodePtr currentNode, TreeNodePtr currentParent, bool isLeftOfParent);
    void PrintTreeHelper(TreeNodePtr);

public:
    Tree() = default;

    void InsertNode(int data);
    void PrintTree(void);
    TreeNodePtr SearchTree(int data);
    void DeleteNode(int data);

    virtual ~Tree() = default;
};

#endif