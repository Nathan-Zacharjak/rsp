#ifndef _NODE_
#define _NODE_

template <typename T>
class Node
{
private:
public:
    T *data;
    Node *nextNode;
    Node *prevNode;
    Node();
    ~Node();
};

template <typename T>
Node<T>::Node()
{
    this->data = nullptr;
    this->nextNode = nullptr;
    this->prevNode = nullptr;
}

template <typename T>
Node<T>::~Node()
{
    delete this->data;
}

#endif