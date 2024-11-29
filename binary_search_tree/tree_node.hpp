#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

class TreeNode
{
private:
public:
    int data = 0;
    TreeNode *parent = nullptr;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode() = default;
    TreeNode(int d) : data(d) {};
    virtual ~TreeNode() = default;
};

#endif