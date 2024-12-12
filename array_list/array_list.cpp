#include <array>
#include <bits/unique_ptr.h>
#include "array_list.h"
#include <iostream>

using std::cout;

// template <typename T>
void array_list::insert(int newValue)
{
    if (_currentSize >= _capacity)
    {
        cout << "Capacity hit! " << _currentSize << " " << _capacity << "\n";
        _capacity *= _resizeFactor;
        // std::unique_ptr<std::array<int, _size>> newList{};
        // std::unique_ptr<std::array<int, _size>> newList = std::make_unique<std::array<int, _size>>;
        int *newList = new int[_capacity]{};

        for (int i = 0; i < _currentSize; i++)
        {
            newList[i] = _list[i];
        }

        delete[] _list;
        _list = newList;
        cout << "New size and capacity: " << _currentSize << " " << _capacity << "\n";
    }

    _list[_currentSize] = newValue;
    _currentSize++;
}

int &array_list::at(int index)
{
    return _list[index];
}

// template <typename T>
// T &array_list<T>::at(int index)
// {
// }

// template <typename T>
// void array_list<T>::remove(int index)
// {
// }
