#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "node.h"
#include <iostream>

template <typename T>
class LinkedList
{
public:
    Node<T> *GetNodeByIndex(size_t index);
    void Append(T initialValue);
    bool RemoveNodeByIndex(size_t index);
    void InsertAfterIndex(T initialValue, size_t index);
    void Clear(void);

    bool ContainsLoop(void);

    void PrintAll(std::ostream &out = std::cout);

    // use linked list as a queue
    T DeQueue(void);
    void EnQueue(T iv);

private:
    Node<T> *firstNode = nullptr;
    size_t size = 0;
};

template <typename T>
Node<T> *LinkedList<T>::GetNodeByIndex(size_t index)
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
void LinkedList<T>::Append(T iv)
{
    if (size == 0)
    {
        firstNode = new Node<T>(iv);
        size += 1;
        return;
    }
    else
    {
        Node<T> *lastNode = GetNodeByIndex(size - 1);
        Node<T> *newNode = new Node<T>(iv);
        lastNode->SetNext(newNode);
        size += 1;
    }
}

template <typename T>
bool LinkedList<T>::RemoveNodeByIndex(size_t index)
{
    if (index >= size)
    {
        // out-of-range
        return false;
    }

    if (index == 0)
    {
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
void LinkedList<T>::InsertAfterIndex(T iv, size_t index)
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

    size += 1;

    return;
}

template <typename T>
void LinkedList<T>::Clear(void)
{
    /* This method has a potential bug: it won't handle a linked list with
       circle/loop. A method called ContainsLoop() can check if the list has
       a loop. In production code, always check if there were any loop
       in the list, otherwise there will be serious segmentation fault/memory
       corruption.

       This method has a recursive implementation but will also suffer
       from abovementioned bug. It is NOT recommended to write recursive
       functions in many coding guidelines and practices: a beautifully designed
       recursion may be a shithole of bug in other's eyes.

       Remember: every recursive function can be written equivalently by another
       while/for-loop.

       one line:

       firstNode->_recursiveClear();
    */

    Node<T> *releaseNode = firstNode;

    while (firstNode != nullptr)
    {
        firstNode = firstNode->GetNext();
        delete releaseNode;
        releaseNode = firstNode;
    }
}

template <typename T>
bool LinkedList<T>::ContainsLoop(void)
{
    if (size == 0)
    {
        // for 0-sized linked list, no need to check.
        return false;
    }

    Node<T> *slowPointer = firstNode;

    Node<T> *fastPointer = firstNode->GetNext();
    if (fastPointer != nullptr)
    {
        fastPointer = fastPointer->GetNext();
    }
    else
    {
        // has reached the end
        return false;
    }

    while (fastPointer != nullptr)
    {
        if (fastPointer == slowPointer)
        {
            // now they meet: so there is a loop on the linked list.
            return true;
        }

        slowPointer = slowPointer->GetNext();

        fastPointer = fastPointer->GetNext();
        if (fastPointer == nullptr)
        {
            // has reached the end
            return false;
        }
        else
        {
            // move fast pointer one more step
            fastPointer = fastPointer->GetNext();
        }
    }

    return false;
}

template <typename T>
void LinkedList<T>::PrintAll(std::ostream &out)
{
    Node<T> *startNode = firstNode;

    while (startNode != nullptr)
    {
        out << startNode->GetValue() << ", ";
        startNode = startNode->GetNext();
    }

    out << std::endl;
}

template <typename T>
T LinkedList<T>::DeQueue(void)
{
    T returnValue = firstNode->GetValue();
    RemoveNodeByIndex(0);
    return returnValue;
}

template <typename T>
void LinkedList<T>::EnQueue(T iv)
{
    Append(iv);
}

#endif