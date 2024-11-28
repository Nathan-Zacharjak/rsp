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

    int indexes[7] = {3, 5, 1, 2, 1, 1, 7};

    for (int i = 0; i < 7; i++)
    {
        cout << "Deleting by index :" << indexes[i] << endl;
        list.DeleteByIndex(indexes[i]);
        list.PrintForwards();
    }

    return 0;
}