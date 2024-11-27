#include <linked_list.hpp>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList<int> *list = new LinkedList<int>;

    list->Push(1);
    list->Push(2);
    list->Push(3);
    list->Push(4);
    list->Push(5);

    list->Print();

    Node<int> *foundNode = list->Find(3);
    cout << "Found node 3: " << foundNode->data << endl;
    list->Remove(3);

    foundNode = list->Find(3);
    cout << "Found node 3: " << foundNode->data << endl;

    list->Print();
    list->Remove(3);
    list->Print(true);

    Node<int> *poppedNode = list->Pop();
    cout << "Popped node: " << poppedNode->data << " Next: " << poppedNode->nextNode << " Prev: " << poppedNode->prevNode << endl;
    list->Pop();
    list->Pop();
    list->Pop();
    list->Pop();

    delete list;

    return 0;
}