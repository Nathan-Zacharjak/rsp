#include "tree.hpp"
#include <iostream>
#include <bits/shared_ptr.h>

using namespace std;

void Tree::InsertNodeHelper(int data, TreeNodePtr currentNode, TreeNodePtr currentParent, bool isLeftOfParent)
{
    if (currentNode == nullptr)
    {
        auto newNode = make_shared<TreeNode>(data, currentParent);

        if (this->root == nullptr)
        {
            this->root = move(newNode);
        }
        else if (isLeftOfParent)
        {
            currentParent->left = newNode;
        }
        else
        {
            currentParent->right = newNode;
        }

        return;
    }

    if (data < currentNode->data)
    {
        this->InsertNodeHelper(data, currentNode->left, currentNode, true);
    }
    else
    {
        this->InsertNodeHelper(data, currentNode->right, currentNode, false);
    }
}

void Tree::InsertNode(int data)
{
    this->InsertNodeHelper(data, this->root, nullptr, false);
}

void Tree::PrintTreeHelper(TreeNodePtr currentNode)
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
    this->PrintTreeHelper(this->root);
}