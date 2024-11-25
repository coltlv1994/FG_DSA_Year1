#ifndef _NODE_H_
#define _NODE_H_

class Node
{
public:
    int GetValue(void);
    Node *GetNext(void);
    Node *GetPrevious(void);
    void SetValue(int valueToSet);
    void SetNext(Node *n);
    void SetPrevious(Node *n);

    void _recursiveClear(void);

    Node(int initialValue);

private:
    int value;
    Node *previous = nullptr;
    Node *next = nullptr;
};

#endif