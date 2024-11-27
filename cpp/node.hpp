#ifndef _NODE_
#define _NODE_

class Node
{
private:
public:
    int data;
    Node *nextNode;
    Node *prevNode;
    Node(int data);
    ~Node();
};

Node::Node(int data)
{
    this->data = data;
    this->nextNode = nullptr;
    this->prevNode = nullptr;
}

Node::~Node()
{
}

#endif