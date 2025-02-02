#ifndef _NODE_H_
#define _NODE_H_

#include <vector>

enum Traversal
{
    InOrder,
    PreOrder,
    PostOrder
};

class BaseNode
{
public:
    int m_value;
    BaseNode *m_left = nullptr;
    BaseNode *m_right = nullptr;

    void _traverse(std::vector<int> &result, Traversal order);
};

void BaseNode::_traverse(std::vector<int> &result, Traversal order)
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

    default:
        break;
    }
}

#endif