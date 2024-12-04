#ifndef NODE_HPP
#define NODE_HPP

struct Coords
{
    int x{0};
    int y{0};
    int z{0};
};

class Node
{
private:
    int x;
    int y;
    int z;

public:
    Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};

    Coords Get(void);

    virtual ~Node() = default;
};

#endif