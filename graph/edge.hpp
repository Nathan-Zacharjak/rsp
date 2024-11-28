#ifndef _EDGE_HPP_
#define _EDGE_HPP_

#include <string>

using namespace std;

class Edge
{
private:
public:
    string label;
    int weight;
    Edge(string label, int weight);
    ~Edge();
};

Edge::Edge(string label, int weight)
{
    this->label = label;
    this->weight = weight;
}

Edge::~Edge()
{
}

#endif