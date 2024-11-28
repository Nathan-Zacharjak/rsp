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

    for (int i = 1; i <= 6; i++)
    {
        cout << "Deleting front node:" << endl;
        list.DeleteFront();
        list.PrintForwards();
    }

    return 0;
}