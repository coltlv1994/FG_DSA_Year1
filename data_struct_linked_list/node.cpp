#include "node.h"

int Node::GetValue(void)
{
    return value;
}

Node* Node::GetNext(void)
{
    return next;
}

void Node::SetValue(int iv)
{
    value = iv;
}

void Node::SetNext(Node* n)
{
    next = n;
}

Node::Node(int iv)
{
    value = iv;
}

Node* Node::GetPrevious(void)
{
    return previous;
}

void Node::SetPrevious(Node* n)
{
    previous = n;
}

void Node::_recursiveClear(void)
{
    if (next != nullptr)
    {
        next->_recursiveClear();
    }

    delete this;
}