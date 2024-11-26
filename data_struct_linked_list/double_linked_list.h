#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <cstdint>
#include "node.h"

template <typename T>
class DoubleLinkedList
{
public:
    Node<T> *GetNodeByIndex(size_t index);
    void Append(T initialValue);
    bool RemoveNodeByIndex(size_t index);
    void InsertAfterIndex(T initialValue, size_t index);

private:
    Node<T> *firstNode = nullptr;
    Node<T> *lastNode = nullptr;
    size_t size = 0;
};

template <typename T>
Node<T> *DoubleLinkedList<T>::GetNodeByIndex(size_t index)
{
    Node<T> *returnNode = firstNode;
    size_t i = 0;

    while (returnNode != nullptr)
    {
        if (i == index)
        {
            return returnNode;
        }

        returnNode = returnNode->GetNext();
        i++;
    }

    return returnNode;
}

template <typename T>
void DoubleLinkedList<T>::Append(T iv)
{
    if (size == 0)
    {
        firstNode = new Node<T>(iv);
        lastNode = firstNode;
        size += 1;
        return;
    }
    else
    {
        Node<T> *newNode = new Node<T>(iv);
        lastNode->SetNext(newNode);
        newNode->SetPrevious(lastNode);
        size += 1;
    }
}

template <typename T>
bool DoubleLinkedList<T>::RemoveNodeByIndex(size_t index)
{
    if (index >= size)
    {
        // out-of-range
        return false;
    }

    if (index == 0)
    {
        if (size == 1)
        {
            lastNode = nullptr;
        }

        // New first node is needed
        Node<T> *newFirstNode = firstNode->GetNext();
        delete firstNode;
        firstNode = newFirstNode;
        size -= 1;
        return true;
    }

    Node<T> *nodeInFront = GetNodeByIndex(index - 1);
    Node<T> *nodeToRemove = nodeInFront->GetNext();
    Node<T> *nodeNext = nodeToRemove->GetNext();

    delete nodeToRemove;
    size -= 1;
    nodeInFront->SetNext(nodeNext);

    return true;
}

template <typename T>
void DoubleLinkedList<T>::InsertAfterIndex(T iv, size_t index)
{
    // new value will be inserted after this given index
    if (size == 0)
    {
        if (index != 0)
        {
            return;
        }
        else
        {
            Append(iv);
            return;
        }
    }

    if (index >= size)
    {
        // out-of-range
        return;
    }

    Node<T> *nodeToInsert = new Node<T>(iv);

    Node<T> *insertionPoint = GetNodeByIndex(index);
    Node<T> *nextToInsertion = insertionPoint->GetNext();

    insertionPoint->SetNext(nodeToInsert);

    nodeToInsert->SetNext(nextToInsertion);
    nodeToInsert->SetPrevious(insertionPoint);

    nextToInsertion->SetPrevious(nodeToInsert);

    size += 1;

    return;
}

#endif