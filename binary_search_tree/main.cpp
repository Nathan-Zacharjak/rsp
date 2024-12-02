#include "tree.hpp"
#include <iostream>
#include <bits/unique_ptr.h>

using namespace std;

int main(int argc, char const *argv[])
{
    Tree tree;

    tree.InsertNode(3);
    tree.InsertNode(1);
    tree.InsertNode(2);
    tree.InsertNode(0);
    tree.InsertNode(5);
    tree.InsertNode(6);
    tree.InsertNode(4);

    tree.PrintTree();
    tree.SearchTree(6);
    cout << "===Deleting Node===" << endl;
    tree.DeleteNode(3);
    cout << "===Finished Deleting===" << endl;
    tree.SearchTree(6);

    return 0;
}