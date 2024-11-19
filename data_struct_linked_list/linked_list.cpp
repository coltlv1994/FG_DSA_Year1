#include <iostream>
#include "node.h"
#include "linked_list.h"

Node* LinkedList::GetNodeByIndex(size_t index)
{
    Node* returnNode = firstNode;
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

void LinkedList::Append(int iv)
{
    if (size == 0)
    {
        firstNode = new Node(iv);
        size += 1;
        return;
    }
    else
    {
        Node* lastNode = GetNodeByIndex(size - 1);
        Node* newNode = new Node(iv);
        lastNode->SetNext(newNode);
        size += 1;
    }
}

bool LinkedList::RemoveNodeByIndex(size_t index)
{
    if (index >= size)
    {
        // out-of-range
        return false;
    }

    if (index == 0)
    {
        // New first node is needed
        Node* newFirstNode = firstNode->GetNext();
        delete(firstNode);
        firstNode = newFirstNode;
        size -= 1;
        return true;
    }

    Node* nodeInFront = GetNodeByIndex(index - 1);
    Node* nodeToRemove = nodeInFront->GetNext();
    Node* nodeNext = nodeToRemove->GetNext();

    delete(nodeToRemove);
    size -= 1;
    nodeInFront->SetNext(nodeNext);

    return true;
}

void LinkedList::InsertAfterIndex(int iv, size_t index)
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

    Node* nodeToInsert = new Node(iv);

    Node* insertionPoint = GetNodeByIndex(index);
    Node* nextToInsertion = insertionPoint->GetNext();

    insertionPoint->SetNext(nodeToInsert);
    nodeToInsert->SetNext(nextToInsertion);

    size += 1;
    
    return;    
}

void LinkedList::Clear()
{
    /* This method has a potential bug: it won't handle a linked list with
       circle/loop.

       This method has a recursive implementation but will also suffer
       from abovementioned bug. It is NOT recommended to write recursive
       functions in many coding guidelines and practices; a beautifully designed
       recursion may be a shithole of bug in other's eyes.

       one line:

       firstNode->_recursiveClear();
    */

    Node* releaseNode = firstNode;

    while (firstNode != nullptr)
    {
        firstNode = firstNode->GetNext();
        delete(releaseNode);
        releaseNode = firstNode;
    }
}