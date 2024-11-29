#ifndef _NODE_HPP_
#define _NODE_HPP_

using namespace std;

class Node
{
private:
public:
    int m_data;
    Node *m_left;
    Node *m_right;
    Node *m_parent;

    Node(int data);
    ~Node();
};

Node::Node(int data)
{
    m_data = data;
    m_left = nullptr;
    m_right = nullptr;
    m_parent = nullptr;
}

Node::~Node()
{
}

#endif