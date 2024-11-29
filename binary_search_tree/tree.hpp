#ifndef _TREE_HPP_
#define _TREE_HPP_

#include "node.hpp"
#include <iostream>

using namespace std;

class Tree
{
private:
    Node *root;

public:
    Tree();

    void InsertNode();

    ~Tree();
};

Tree::Tree()
{
}

Tree::~Tree()
{
}

#endif