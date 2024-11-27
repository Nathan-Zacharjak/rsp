#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <node.hpp>
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
    void Print(bool backwards);
    Node<T> *Pop(void);
    LinkedList();
    ~LinkedList();
};

template <typename T>
void LinkedList<T>::Push(T data)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    Node<T> *oldHead = this->head;
    oldHead->prevNode = newNode;
    newNode->nextNode = oldHead;
    this->head = newNode;
}

template <typename T>
Node<T> *LinkedList<T>::Find(T data)
{
    Node<T> *currentNode = head;
    while (currentNode != nullptr)
    {
        currentNode = currentNode->nextNode;
    }
    return currentNode;
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
void LinkedList<T>::Print(bool backwards = false)
{
    if (backwards)
    {
        Node<T> *currentNode = this->tail;

        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->prevNode;
        }
    }
    else
    {
        Node<T> *currentNode = this->head;

        while (currentNode != nullptr)
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->nextNode;
        }
    }
}

template <typename T>
Node<T> *LinkedList<T>::Pop(void)
{
    Node<T> oldTail = this->tail;

    if (oldTail == nullptr)
    {
        cout << "Warning: Popping empty list!" << endl;
        return nullptr;
    }

    Node<T> newTail = oldTail->prevNode;
    newTail->nextNode = nullptr;
    oldTail->prevNode = nullptr;

    return oldTail;
}

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> currentNode = this->head;

    cout << "Deleting list..." << endl;

    while (currentNode != nullptr)
    {
        Node<T> nextNode = currentNode->nextNode;
        cout << "Deleting node: " << currentNode.data << endl;
        delete currentNode;
        currentNode = nextNode;
    }
}

#endif