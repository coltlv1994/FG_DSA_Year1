#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <cstdint>
#include "node.h"

class DoubleLinkedList
{
public:
    Node *GetNodeByIndex(size_t index);
    void Append(int initialValue);
    bool RemoveNodeByIndex(size_t index);
    void InsertAfterIndex(int initialValue, size_t index);

private:
    Node *firstNode = nullptr;
    Node *lastNode = nullptr;
    size_t size = 0;
};

#endif