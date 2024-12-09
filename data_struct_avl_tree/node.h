#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>

class Node
{
public:
    Node();
    Node(int iv);
    int GetValue();
    void SetValue(int p_value);
    bool IsLeafNode();
    Node *GetRight();
    Node *GetLeft();
    void SetRight(Node *p_right);
    void SetLeft(Node *p_left);

    bool Add(int iv);
    void ClearAll();

private:
    int m_value;
    Node *m_left = nullptr;
    Node *m_right = nullptr;
};
#endif