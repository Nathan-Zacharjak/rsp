#include "tree.hpp"
#include <iostream>
#include <bits/unique_ptr.h>

using namespace std;

void Tree::InsertNodeHelper(int data, Node *currentNode, Node *currentParent, bool isLeftOfParent)
{
    if (currentNode == nullptr)
    {
        auto newNode = make_unique<Node>(data, currentParent);

        if (this->root == nullptr)
        {
            this->root = move(newNode);
        }
        else if (isLeftOfParent)
        {
            currentParent->left = move(newNode);
        }
        else
        {
            currentParent->right = move(newNode);
        }

        return;
    }

    if (data < currentNode->data)
    {
        this->InsertNodeHelper(data, currentNode->left.get(), currentNode, true);
    }
    else
    {
        this->InsertNodeHelper(data, currentNode->right.get(), currentNode, false);
    }
}

void Tree::InsertNode(int data)
{
    this->InsertNodeHelper(data, this->root.get(), nullptr, false);
}

void Tree::PrintTreeHelper(Node *currentNode)
{
    if (currentNode == nullptr)
    {
        return;
    }

    this->PrintTreeHelper(currentNode->left.get());
    cout << currentNode->data << endl;
    this->PrintTreeHelper(currentNode->right.get());
}

void Tree::PrintTree(void)
{
    this->PrintTreeHelper(this->root.get());
}

Node *Tree::SearchTree(int data, bool findParent)
{
    Node *currentNode = this->root.get();

    if (currentNode == nullptr)
    {
        cout << "Tried to search an empty tree!" << endl;
        return nullptr;
    }

    while (currentNode != nullptr)
    {
        if (findParent)
        {
            if (currentNode->left != nullptr && currentNode->left->data == data)
            {
                cout << "Found node parent with data: " << currentNode->data << endl;
                return currentNode;
            }
            else if (currentNode->right != nullptr && currentNode->right->data == data)
            {
                cout << "Found node parent with data: " << currentNode->data << endl;
                return currentNode;
            }
        }

        if (currentNode->data == data)
        {
            cout << "Found node with data: " << currentNode->data << endl;

            if (currentNode != this->root.get())
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

            currentNode = currentNode->left.get();
        }
        else
        {
            if (currentNode->right != nullptr)
            {
                cout << "Traversing tree right from " << currentNode->data << " to " << currentNode->right->data << endl;
            }

            currentNode = currentNode->right.get();
        }
    }

    cout << "Couldn't find node with data: " << data << endl;
    return nullptr;
}

void Tree::Delete0ChildNode(NodePtr nodeToDelete)
{
    nodeToDelete.reset();
}

void Tree::Delete1ChildNode(NodePtr nodeToDelete)
{
}

void Tree::Delete2ChildNode(NodePtr nodeToDelete)
{
}

void Tree::DeleteNode(int data)
{
    Node *parent = this->SearchTree(data, true);

    if (parent == nullptr)
    {
        cout << "Couldn't find parent of node to delete with data: " << data << endl;
        return;
    }

    NodePtr nodeToDelete;
    if (parent->left != nullptr && parent->left->data == data)
    {
        nodeToDelete = move(parent->left);
    }
    else
    {
        nodeToDelete = move(parent->right);
    }

    if (nodeToDelete->left == nullptr && nodeToDelete->right == nullptr)
    {
        this->Delete0ChildNode(move(nodeToDelete));
    }
    else if (nodeToDelete->left != nullptr && nodeToDelete->right != nullptr)
    {
        this->Delete2ChildNode(move(nodeToDelete));
    }
    else
    {
        this->Delete1ChildNode(move(nodeToDelete));
    }
}