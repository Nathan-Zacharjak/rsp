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

TreeNodePtr Tree::SearchTree(int data)
{
    TreeNodePtr currentNode = this->root;

    if (currentNode == nullptr)
    {
        cout << "Tried to search an empty tree!" << endl;
        return nullptr;
    }

    while (currentNode != nullptr)
    {
        if (currentNode->data == data)
        {
            cout << "Found node with data: " << currentNode->data << endl;

            if (currentNode != this->root)
            {
                cout << " and parent: " << currentNode->parent->data << endl;
            }

            return currentNode;
        }
        else if (data < currentNode->data)
        {
            if (currentNode->left != nullptr)
            {
                cout << "Traversing tree left from " << currentNode->data << " to " << currentNode->left->data << endl;
            }

            currentNode = currentNode->left;
        }
        else
        {
            if (currentNode->right != nullptr)
            {
                cout << "Traversing tree right from " << currentNode->data << " to " << currentNode->right->data << endl;
            }

            currentNode = currentNode->right;
        }
    }

    cout << "Couldn't find node with data: " << data << endl;
    return nullptr;
}