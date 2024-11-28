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

    void InsertByIndex(int data, int index);

    void DeleteFront(void);
    void DeleteEnd(void);
    void DeleteByData(int data);
    void DeleteByIndex(int index);

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
    this->length++;

    if (this->IsEmpty())
    {
        this->head = newNode;
        this->tail = newNode;
        return;
    }

    this->head->prevNode = newNode;
    newNode->nextNode = this->head;
    this->head = newNode;
}

void LinkedList::InsertEnd(int data)
{
    Node *newNode = new Node(data);
    this->length++;

    if (this->IsEmpty())
    {
        this->head = newNode;
        this->tail = newNode;
        return;
    }

    this->tail->nextNode = newNode;
    newNode->prevNode = this->tail;
    this->tail = newNode;
}

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

Node *LinkedList::FindByIndex(int index)
{
    if (index < 1 || index > this->GetLength())
    {
        cout << "FindByIndex index: " << index << " out of range! Index non-positive or over list length " << this->GetLength() << endl;
        return nullptr;
    }

    Node *currentNode = this->head;
    int currentIndex = 1;

    while (currentNode != nullptr)
    {
        if (currentIndex == index)
        {
            return currentNode;
        }

        currentNode = currentNode->nextNode;
        currentIndex++;
    }

    cout << "FindByIndex index: " << index << " out of range! Couldn't find index!" << endl;
    return nullptr;
}

void LinkedList::InsertByIndex(int data, int index)
{
    Node *newNode = new Node(data);

    if (index == 1)
    {
        this->InsertFront(data);
        return;
    }

    if (index == this->GetLength() + 1)
    {
        this->InsertEnd(data);
        return;
    }

    Node *oldNode = this->FindByIndex(index);

    if (oldNode == nullptr)
    {
        cout << "Tried to insert node with data: " << data << " in index out of range: " << index << endl;
        return;
    }

    newNode->prevNode = oldNode->prevNode;
    oldNode->prevNode->nextNode = newNode;

    oldNode->prevNode = newNode;
    newNode->nextNode = oldNode;

    this->length++;
}

void LinkedList::DeleteFront(void)
{
    Node *oldHead = this->head;

    if (oldHead == nullptr)
    {
        cout << "Tried to delete front node on empty list!" << endl;
        return;
    }

    Node *newHead = oldHead->nextNode;
    this->head = newHead;
    delete oldHead;

    if (newHead != nullptr)
    {
        newHead->prevNode = nullptr;
    }
}

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