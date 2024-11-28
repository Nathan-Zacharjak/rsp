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

    cout << "Finding node with index 3: " << list.FindByIndex(3)->data << endl;
    cout << "Finding node with index 99: " << list.FindByIndex(-99) << endl;
    cout << "Finding node with index 99: " << list.FindByIndex(99) << endl;

    // list.InsertAtIndex(99, 3);
    // list.PrintForwards();

    return 0;
}