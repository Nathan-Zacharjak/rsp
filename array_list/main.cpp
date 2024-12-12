#include "array_list.h"
#include <iostream>
#include <print>

int main(int argc, char const *argv[])
{
    array_list list;
    for (int i = 0; i < 9; i++)
    {
        list.insert(i);
    }

    // list.insert(1);
    list.at(0) = 9;
    // std::cout << list.at(0) << std::endl;

    for (int i = 0; i < 9; i++)
    {
        std::println("Index: {} = {}", i, list.at(i));
    }

    // std::println("Second arg: {1}, First arg: {0}", list.at(0), 2);

    return 0;
}
