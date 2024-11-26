#ifndef _NODE_H_
#define _NODE_H_

template <typename T>
class Node
{
public:
    T GetValue(void);
    Node<T> *GetNext(void);
    Node<T> *GetPrevious(void);
    void SetValue(T valueToSet);
    void SetNext(Node<T> *n);
    void SetPrevious(Node<T> *n);

    void _recursiveClear(void);

    Node(T initialValue);

private:
    T value;
    Node<T> *previous = nullptr;
    Node<T> *next = nullptr;
};

template <typename T>
T Node<T>::GetValue(void)
{
    return value;
}

template <typename T>
Node<T> *Node<T>::GetNext(void)
{
    return next;
}

template <typename T>
void Node<T>::SetValue(T iv)
{
    value = iv;
}

template <typename T>
void Node<T>::SetNext(Node<T> *n)
{
    next = n;
}

template <typename T>
Node<T>::Node(T iv)
{
    value = iv;
}

template <typename T>
Node<T> *Node<T>::GetPrevious(void)
{
    return previous;
}

template <typename T>
void Node<T>::SetPrevious(Node<T> *n)
{
    previous = n;
}

template <typename T>
void Node<T>::_recursiveClear(void)
{
    if (next != nullptr)
    {
        next->_recursiveClear();
    }

    delete this;
}

#endif