#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include "node.h"

class LinkedList
{
    public:
        Node* GetNodeByIndex(size_t index);
        void Append(int initialValue);
        bool RemoveNodeByIndex(size_t index);
        void InsertAfterIndex(int initialValue, size_t index);
        void Clear(void);

        bool ContainsLoop(void);

        void PrintAll(std::ostream &out);

    private:
        Node* firstNode = nullptr;
        size_t size = 0;
};

#endif