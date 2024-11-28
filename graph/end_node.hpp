#ifndef _END_NODE_HPP_
#define _END_NODE_HPP_

#include <string>

using namespace std;

class EndNode
{
private:
public:
    string label;
    int weight;
    EndNode(string label, int weight);
    ~EndNode();
};

EndNode::EndNode(string label, int weight)
{
    this->label = label;
    this->weight = weight;
}

EndNode::~EndNode()
{
}

#endif