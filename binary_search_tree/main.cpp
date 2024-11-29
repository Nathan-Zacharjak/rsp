#include "tree.hpp"
#include <iostream>
#include <bits/unique_ptr.h>

using namespace std;

int main(int argc, char const *argv[])
{
    Tree tree;

    tree.InsertNode(1);

    TreeNode *node = new TreeNode(10);

    auto var = std::make_unique<TreeNode>(5, node);

    cout << var->data << "\t" << var->parent->data << endl;

    return 0;
}