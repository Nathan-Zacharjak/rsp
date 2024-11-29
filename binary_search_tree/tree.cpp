#include "tree.hpp"
#include <iostream>
#include <bits/unique_ptr.h>

using namespace std;

void Tree::InsertNodeHelper(int data, TreeNode *currentNode, TreeNode *currentParent)
{
    if (currentNode == nullptr)
    {
        TreeNode *node = new TreeNode;

        auto var = make_unique<TreeNode>(5, node);

        cout << var->data << "\t" << var->parent->data << endl;
        return;
    }
}

void Tree::InsertNode(int data)
{
    this->InsertNodeHelper(data, this->root, nullptr);
    return;
}
