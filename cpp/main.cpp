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

    cout << "Deleting node with data: " << 6 << endl;
    list.DeleteByData(6);
    list.PrintForwards();
    cout << "Deleting node with data: " << 8 << endl;
    list.DeleteByData(8);
    list.PrintForwards();
    cout << "Deleting node with data: " << 4 << endl;
    list.DeleteByData(4);
    list.PrintForwards();
    cout << "Deleting node with data: " << 44 << endl;
    list.DeleteByData(44);
    list.PrintForwards();
    cout << "Deleting node with data: " << 10 << endl;
    list.DeleteByData(10);
    list.PrintForwards();
    cout << "Deleting node with data: " << 2 << endl;
    list.DeleteByData(2);
    list.PrintForwards();
    cout << "Deleting node with data: " << 1 << endl;
    list.DeleteByData(1);
    list.PrintForwards();

    return 0;
}