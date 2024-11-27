#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include "node.hpp"
#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

public:
    void Push(T data);
    Node<T> *Find(T data);
    void Remove(T data);
    void Print();
    // T *Pop();
    LinkedList();
    ~LinkedList();
};

template <typename T>
void LinkedList<T>::Push(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;

    if (this->head != nullptr)
    {
        this->head->prevNode = newNode;
    }
    else if (this->tail == nullptr)
    {
        this->tail = newNode;
    }

    newNode->nextNode = this->head;
    this->head = newNode;
}

template <typename T>
Node<T> *LinkedList<T>::Find(T data)
{
    Node<T> *currentNode = this->head;

    while (currentNode->nextNode != nullptr)
    {
        if (currentNode->data == data)
        {
            return currentNode;
        }

        currentNode = currentNode->nextNode;
    }

    return nullptr;
}

template <typename T>
void LinkedList<T>::Remove(T data)
{
    Node<T> *removeNode = this->Find(data);
    if (removeNode == nullptr)
    {
        cout << "Warning: Tried to remove node that does not exist: " << data << endl;
        return;
    }

    Node<T> *beforeNode = removeNode->prevNode;
    Node<T> *afterNode = removeNode->prevNode;
    beforeNode->nextNode = removeNode->nextNode;
    afterNode->prevNode = removeNode->prevNode;

    delete removeNode;
}

template <typename T>
void LinkedList<T>::Print()
{
    if (this->head == nullptr)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node<T> *currentNode = this->head;

    while (currentNode != nullptr)
    {
        cout << currentNode->data << endl;
        currentNode = currentNode->nextNode;
    }
}

// template <typename T>
// T *LinkedList<T>::Pop()
// {
//     if (this->tail == nullptr)
//     {
//         cout << "Warning: Popping empty list!" << endl;
//         return nullptr;
//     }

//     T *oldTailData = new T(this->tail->data);
//     Node<T> *oldTail = this->tail;
//     // Node<T> *oldTail = this->tail;

//     cout << "Old tail: " << oldTail->data << " Next: " << oldTail->nextNode << " Prev: " << oldTail->prevNode << endl;

//     this->tail->prevNode->nextNode = nullptr;
//     this->tail = this->tail->prevNode;
//     delete oldTail;

//     if (this->tail == nullptr)
//     {
//         this->head = nullptr;
//         return oldTailData;
//     }

//     cout << "Changed tail to: " << this->tail->data << " Next: " << this->tail->nextNode << " Prev: " << this->tail->prevNode << endl;

//     return oldTailData;
// }

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *currentNode = this->head;

    cout << "Deleting list..." << endl;

    while (currentNode != nullptr)
    {
        Node<T> *nextNode = currentNode->nextNode;
        cout << "Deleting node: " << currentNode->data << endl;
        delete currentNode;
        currentNode = nextNode;
    }
}

#endif