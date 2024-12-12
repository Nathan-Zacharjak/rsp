#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <array>
#include <bits/unique_ptr.h>

template <typename T>
class array_list
{
private:
    std::unique_ptr<std::array<T, 2>> list{};

public:
    array_list() = default;

    void insert(T value);
    T &at(int index);
    void remove(int index);

    virtual ~array_list() = default;
};

#endif