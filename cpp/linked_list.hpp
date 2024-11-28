#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include "node.hpp"
#include <iostream>

using namespace std;

class LinkedList
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int length;

public:
    LinkedList();

    int GetLength(void);
    bool IsEmpty(void);

    void InsertFront(int data);
    void InsertEnd(int data);

    void PrintForwards(void);
    void PrintBackwards(void);

    Node *FindByData(int data);
    Node *FindByIndex(int index);

    void InsertAtIndex(int data, int index);

    void DeleteFront(int data);
    void DeleteEnd(int data);
    void DeleteAtIndex(int index);
    void DeleteByData(int data);

    ~LinkedList();
};

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

int LinkedList::GetLength(void)
{
    return this->length;
}

bool LinkedList::IsEmpty(void)
{
    return this->head == nullptr;
}

void LinkedList::InsertFront(int data)
{
    Node *newNode = new Node(data);

    if (this->IsEmpty())
    {
        this->head = newNode;
        this->tail = newNode;
        return;
    }

    this->head->prevNode = newNode;
    newNode->nextNode = this->head;
    this->head = newNode;
    this->length++;
}

void LinkedList::InsertEnd(int data)
{
    Node *newNode = new Node(data);

    if (this->IsEmpty())
    {
        this->head = newNode;
        this->tail = newNode;
        return;
    }

    this->tail->nextNode = newNode;
    newNode->prevNode = this->tail;
    this->tail = newNode;
    this->length++;
}

// void LinkedList::InsertAtIndex(int data, int index)
// {
//     Node *newNode = new Node(data);

//     if (index > this->length || index < 1)
//     {
//         cout << "Insert index: " << index << " out of range." << endl;
//         return;
//     }

//     this->tail->nextNode = newNode;
//     newNode->prevNode = this->tail;
//     this->tail = newNode;
//     this->length++;
// }

void LinkedList::PrintForwards()
{
    if (this->IsEmpty())
    {
        cout << "*Empty list*" << endl;
        return;
    }

    Node *currentNode = this->head;

    while (currentNode != nullptr)
    {
        cout << currentNode->data << endl;
        currentNode = currentNode->nextNode;
    }
}

void LinkedList::PrintBackwards()
{
    if (this->IsEmpty())
    {
        cout << "*Empty list*" << endl;
        return;
    }

    Node *currentNode = this->tail;

    while (currentNode != nullptr)
    {
        cout << currentNode->data << endl;
        currentNode = currentNode->prevNode;
    }
}

Node *LinkedList::FindByData(int data)
{
    Node *currentNode = this->head;

    while (currentNode != nullptr)
    {
        if (currentNode->data == data)
        {
            return currentNode;
        }

        currentNode = currentNode->nextNode;
    }

    cout << "Node with data: " << data << " not found!" << endl;

    return nullptr;
}

// void LinkedList::Remove(T data)
// {
//     Node *removeNode = this->Find(data);
//     if (removeNode == nullptr)
//     {
//         cout << "Warning: Tried to remove node that does not exist: " << data << endl;
//         return;
//     }

//     Node *beforeNode = removeNode->prevNode;
//     Node *afterNode = removeNode->prevNode;
//     beforeNode->nextNode = removeNode->nextNode;
//     afterNode->prevNode = removeNode->prevNode;

//     delete removeNode;
// }

// T *LinkedList::Pop()
// {
//     if (this->tail == nullptr)
//     {
//         cout << "Warning: Popping empty list!" << endl;
//         return nullptr;
//     }

//     T *oldTailData = new T(this->tail->data);
//     Node *oldTail = this->tail;
//     // Node *oldTail = this->tail;

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

LinkedList::~LinkedList()
{
    Node *currentNode = this->head;

    cout << "Deleting list..." << endl;

    while (currentNode != nullptr)
    {
        Node *nextNode = currentNode->nextNode;
        cout << "Deleting node: " << currentNode->data << endl;
        delete currentNode;
        currentNode = nextNode;
    }
}

#endif