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
    cout << "Finding node with data: " << data << endl;

    Node *currentNode = this->root.get();

    if (currentNode == nullptr)
    {
        cout << "Tried to search an empty tree!" << endl;
        return nullptr;
    }

    if (data == this->root->data && findParent)
    {
        cout << "Tried to search for the root's parent!" << endl;
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

void Tree::Delete1ChildNode(NodePtr nodeToDelete, bool leftChild)
{
    Node *parent = nodeToDelete->parent;
    NodePtr child = nullptr;

    if (nodeToDelete->left != nullptr)
    {
        child = move(nodeToDelete->left);
    }
    else
    {
        child = move(nodeToDelete->right);
    }

    child->parent = parent;

    if (parent == nullptr)
    {
        this->root = move(child);
        return;
    }

    if (leftChild)
    {
        parent->left = move(child);
    }
    else
    {
        parent->right = move(child);
    }
}

void Tree::Delete2ChildNode(Node *nodeToDelete, bool leftChild)
{
    Node *smallestSuccessor = nodeToDelete->right.get();

    while (smallestSuccessor->left != nullptr)
    {
        smallestSuccessor = smallestSuccessor->left.get();
    }

    int smallestSuccessorData = smallestSuccessor->data;
    this->DeleteNode(smallestSuccessorData);
    nodeToDelete->data = smallestSuccessorData;
}

void Tree::DeleteNode(int data)
{
    cout << "Deleting node with data: " << data << endl;
    bool deletingRoot = data == this->root->data;

    Node *parent = nullptr;
    if (!deletingRoot)
    {
        parent = this->SearchTree(data, true);
    }

    if (parent == nullptr && !deletingRoot)
    {
        cout << "Couldn't find parent of node to delete with data: " << data << endl;
        return;
    }

    Node *nodeToDelete = nullptr;
    bool leftChild = false;
    if (deletingRoot)
    {
        nodeToDelete = this->root.get();
    }
    else if (parent->left != nullptr && parent->left->data == data)
    {
        nodeToDelete = parent->left.get();
        leftChild = true;
    }
    else
    {
        nodeToDelete = parent->right.get();
        leftChild = false;
    }

    if (nodeToDelete->left != nullptr && nodeToDelete->right != nullptr)
    {
        cout << "Is a 2 child node." << endl;
        this->Delete2ChildNode(nodeToDelete, leftChild);
    }
    else if (nodeToDelete->left != nullptr || nodeToDelete->right != nullptr)
    {
        cout << "Is a 1 child node." << endl;
        if (deletingRoot)
        {
            this->Delete1ChildNode(move(this->root), leftChild);
        }
        else if (leftChild)
        {
            this->Delete1ChildNode(move(parent->left), leftChild);
        }
        else
        {
            this->Delete1ChildNode(move(parent->right), leftChild);
        }
    }
    else
    {
        cout << "Is a 0 child node." << endl;
        if (deletingRoot)
        {
            this->root.reset();
        }
        else if (leftChild)
        {
            parent->left.reset();
        }
        else
        {
            parent->right.reset();
        }
    }
}