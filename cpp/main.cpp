#include "linked_list.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Creating List" << endl;
    LinkedList<int> *list = new LinkedList<int>;

    cout << "Pushing 1" << endl;
    list->Push(1);
    cout << "Pushing 2" << endl;
    list->Push(2);
    list->Push(3);
    list->Push(4);
    list->Push(5);

    list->Print();

    cout << "Finding 3" << endl;
    Node<int> *foundNode = list->Find(3);
    cout << "Found node 3: " << foundNode->data << endl;
    cout << "Removing 3" << endl;
    list->Remove(3);

    cout << "Finding 3 again" << endl;
    foundNode = list->Find(3);
    cout << "Found node 3: " << foundNode << endl;

    cout << "Printing after finding 3" << endl;
    list->Print();
    cout << "Removing 3 again" << endl;
    list->Remove(3);
    cout << "Printing after removing 3 again" << endl;
    list->Print();

    // cout << "Popping node" << endl;
    // int *poppedNode = list->Pop();
    // cout << "Popped node: " << *poppedNode << endl;
    // list->Print();

    // cout << "Popping way too many times" << endl;
    // poppedNode = list->Pop();
    // cout << "Popped node: " << *poppedNode << endl;
    // list->Print();
    // poppedNode = list->Pop();
    // cout << "Popped node: " << *poppedNode << endl;
    // list->Print();
    // poppedNode = list->Pop();
    // cout << "Popped node: " << *poppedNode << endl;
    // list->Print();
    // poppedNode = list->Pop();
    // cout << "Popped node: " << *poppedNode << endl;
    // list->Print();

    cout << "Pushing again" << endl;
    list->Push(5);
    list->Push(4);
    list->Push(4);

    cout << "Printing before deleting list" << endl;
    list->Print();

    cout << "Deleting list" << endl;
    delete list;

    return 0;
}