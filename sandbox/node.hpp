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
    // Declare constructors as explicit input types, unless you very much want implicit type conversions...
    // Use initialiser lists rather than in-line member value declarations
    explicit Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};

    Coords Get(void);

    // Declare destructors as virtual, and use the "default" keyword when declaring empty constructors/destructors
    virtual ~Node() = default;
};

#endif