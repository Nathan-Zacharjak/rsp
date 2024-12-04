#include "node.hpp"

Coords Node::Get(void)
{
    Coords coords = {this->x, this->y, this->z};
    return coords;
}