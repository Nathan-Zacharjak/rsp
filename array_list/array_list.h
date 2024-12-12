#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

// #include <array>
// #include <bits/unique_ptr.h>
#include <cstddef>

// template <typename T>
class array_list
{
private:
    // std::unique_ptr<std::array<int, 1>> _list{};
    int *_list{new int[1]};
    size_t _capacity{1};
    size_t _currentSize{0};
    unsigned int _resizeFactor{2};

public:
    array_list() = default;

    void insert(int value);
    int &at(int index);

    virtual ~array_list() = default;
};

#endif