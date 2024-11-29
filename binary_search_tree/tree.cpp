#include "tree.hpp"
#include <iostream>
#include <bits/unique_ptr.h>

using namespace std;

TreeNode *Tree::GetRoot(void)
{
    return this->root.get();
}

void Tree::InsertNodeHelper(int data, TreeNode *currentNode, TreeNode *currentParent)
{
    if (currentNode == nullptr)
    {
        auto newNode = make_unique<TreeNode>(data, currentParent);

        if (this->root == nullptr)
        {
            this->root = move(newNode);
        }

        return;
    }

    if (data < currentNode->data)
    {
        this->InsertNodeHelper(data, currentNode->left, currentNode);
    }
    else
    {
        this->InsertNodeHelper(data, currentNode->parent, currentNode);
    }
}

void Tree::InsertNode(int data)
{
    this->InsertNodeHelper(data, this->GetRoot(), nullptr);
}

void Tree::PrintTreeHelper(TreeNode *currentNode)
{
    if (currentNode == nullptr)
    {
        return;
    }

    this->PrintTreeHelper(currentNode->left);
    cout << currentNode->data << endl;
    this->PrintTreeHelper(currentNode->right);
}

void Tree::PrintTree(void)
{
    this->PrintTreeHelper(this->GetRoot());
}