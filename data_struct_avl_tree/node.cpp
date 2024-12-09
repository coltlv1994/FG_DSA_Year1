#include "node.h"


Node::Node(int iv)
{
    m_value = iv;
}

int Node::GetValue()
{
    return m_value;
}

void Node::SetValue(int p_value)
{
    m_value = p_value;
}

bool Node::IsLeafNode()
{
    return (m_left == nullptr && m_right == nullptr);
}

Node *Node::GetRight()
{
    return m_right;
}

Node *Node::GetLeft()
{
    return m_left;
}

void Node::SetRight(Node *p_right)
{
    m_right = p_right;
}

void Node::SetLeft(Node *p_left)
{
    m_left = p_left;
}

bool Node::Add(int iv)
{
    if (m_value == iv)
    {
        // we don't take duplicate value
        return false;
    }
    else
    {
        if (iv < m_value)
        {
            return m_left->Add(iv);
        }
        else
        {
            return m_right->Add(iv);
        }
    }
}

void Node::ClearAll(void)
{
    if (m_left != nullptr)
    {
        m_left->ClearAll();
        m_left = nullptr;
    }

    if (m_right != nullptr)
    {
        m_right->ClearAll();
        m_right = nullptr;
    }

    delete this;
    return;
}