#ifndef _NODE_HPP_
#define _NODE_HPP_

using namespace std;

class Node
{
private:
public:
    int m_data;
    Node *m_left = nullptr;
    Node *m_right = nullptr;
    Node *m_parent = nullptr;

    Node(int data) : m_data(data) {};
};

#endif