#ifndef _BST_H_
#define _BST_H_

#include <vector>

enum Traversal
{
    InOrder,
    PreOrder,
    PostOrder
};

template <typename T>
class BinarySearchTree
{
    class Node
    {
    public:
        Node(T iv)
        {
            m_value = iv;
        }

        bool _add(T iv)
        {
            if (iv <= m_value)
            {
                if (m_left == nullptr)
                {
                    m_left = new Node(iv);
                    return true;
                }
                else
                {
                    return m_left->_add(iv);
                }
            }
            else
            {
                if (m_right == nullptr)
                {
                    m_right = new Node(iv);
                    return true;
                }
                else
                {
                    return m_right->_add(iv);
                }
            }
        }

        void _traverse(std::vector<T> &result, Traversal order)
        {
            switch (order)
            {
            case Traversal::InOrder:
                if (m_left != nullptr)
                {
                    m_left->_traverse(result, order);
                }

                result.push_back(m_value);

                if (m_right != nullptr)
                {
                    m_right->_traverse(result, order);
                }

                break;

            case Traversal::PreOrder:
                result.push_back(m_value);

                if (m_left != nullptr)
                {
                    m_left->_traverse(result, order);
                }

                if (m_right != nullptr)
                {
                    m_right->_traverse(result, order);
                }

                break;

            case Traversal::PostOrder:
                if (m_left != nullptr)
                {
                    m_left->_traverse(result, order);
                }

                if (m_right != nullptr)
                {
                    m_right->_traverse(result, order);
                }

                result.push_back(m_value);

                break;
            
            default: break;
            }
        }

    private:
        T m_value;
        Node *m_left = nullptr;
        Node *m_right = nullptr;
    };

public:
    bool Add(T iv);
    void Traverse(std::vector<T> &result, Traversal order);

private:
    Node *m_rootNode = nullptr;
};

template <typename T>
bool BinarySearchTree<T>::Add(T iv)
{
    if (m_rootNode == nullptr)
    {
        m_rootNode = new Node(iv);
        return true;
    }
    else
    {
        return m_rootNode->_add(iv);
    }
}

template <typename T>
void BinarySearchTree<T>::Traverse(std::vector<T> &result, Traversal order)
{
    if (m_rootNode == nullptr)
    {
        return;
    }
    else
    {
        m_rootNode->_traverse(result, order);
    }
}
#endif