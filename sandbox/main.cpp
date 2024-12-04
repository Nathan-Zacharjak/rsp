#include <iostream>
#include "node.hpp"

using std::cout, std::endl, std::string;

int main(int argc, char const *argv[])
{
    string hello = "hello!";
    Node node(1, 2, 3);

    cout << hello << "\n";

    const auto [x, y, z] = node.Get();
    const auto coords = node.Get();

    cout << coords.x << "\n";
    cout << x << " " << y << " " << z << "\n";

    return 0;
}
