#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

class Node
{
    public:
        int GetValue(void);
        Node* GetNext(void);
        void SetValue(int valueToSet);
        void SetNext(Node* n);
        Node(int initialValue);
    
    private:
        int value;
        Node* next = nullptr;
};

class LinkedList
{
    public:
        Node* GetNodeByIndex(size_t index);
        void Append(int initialValue);
        bool RemoveNodeByIndex(size_t index);
        void InsertAfterIndex(int initialValue, size_t index);

    private:
        Node* firstNode = nullptr;
        size_t size = 0;
};

#endif