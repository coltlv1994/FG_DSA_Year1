#include <iostream>
#include "node.h"
#include "double_linked_list.h"

Node *DoubleLinkedList::GetNodeByIndex(size_t index)
{
    Node *returnNode = firstNode;
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

void DoubleLinkedList::Append(int iv)
{
    if (size == 0)
    {
        firstNode = new Node(iv);
        lastNode = firstNode;
        size += 1;
        return;
    }
    else
    {
        Node *newNode = new Node(iv);
        lastNode->SetNext(newNode);
        newNode->SetPrevious(lastNode);
        size += 1;
    }
}

bool DoubleLinkedList::RemoveNodeByIndex(size_t index)
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
        Node *newFirstNode = firstNode->GetNext();
        delete firstNode;
        firstNode = newFirstNode;
        size -= 1;
        return true;
    }

    Node *nodeInFront = GetNodeByIndex(index - 1);
    Node *nodeToRemove = nodeInFront->GetNext();
    Node *nodeNext = nodeToRemove->GetNext();

    delete nodeToRemove;
    size -= 1;
    nodeInFront->SetNext(nodeNext);

    return true;
}

void DoubleLinkedList::InsertAfterIndex(int iv, size_t index)
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

    Node *nodeToInsert = new Node(iv);

    Node *insertionPoint = GetNodeByIndex(index);
    Node *nextToInsertion = insertionPoint->GetNext();

    insertionPoint->SetNext(nodeToInsert);

    nodeToInsert->SetNext(nextToInsertion);
    nodeToInsert->SetPrevious(insertionPoint);

    nextToInsertion->SetPrevious(nodeToInsert);

    size += 1;

    return;
}
