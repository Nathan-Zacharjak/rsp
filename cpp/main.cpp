#include "linked_list.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList list;

    for (int i = 1; i <= 5; i++)
    {
        int value = i * 2;
        cout << "Inserting " << value << endl;
        list.InsertEnd(value);
    }
    list.PrintForwards();

    cout << "Inserting 99 at index 0:" << endl;
    list.InsertAtIndex(99, 0);
    list.PrintForwards();

    return 0;
}