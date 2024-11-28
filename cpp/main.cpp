#include "linked_list.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    LinkedList list;

    for (int i = 1; i <= 5; i++)
    {
        cout << "Inserting " << i << endl;
        list.InsertFront(i);
        list.PrintForwards();
    }

    return 0;
}