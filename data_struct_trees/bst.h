#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <vector>
#include "node.h"

class BSTNode : public BaseNode
{
public:
    bool _add(int iv);
    BSTNode(int iv);
};

BSTNode::BSTNode(int iv)
{
    m_value = iv;
}

bool BSTNode::_add(int iv)
{
    if (iv <= m_value)
    {
        if (m_left == nullptr)
        {
            m_left = new BSTNode(iv);
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
            m_right = new BSTNode(iv);
            return true;
        }
        else
        {
            return m_right->_add(iv);
        }
    }
}

class BinarySearchTree
{
public:
    bool Add(int iv);
    void Traverse(std::vector<int> &result, Traversal order);
    void Traverse(std::vector<int> &result, Traversal order, std::ostream &out);

private:
    BSTNode *m_rootNode = nullptr;
};

bool BinarySearchTree::Add(int iv)
{
    if (m_rootNode == nullptr)
    {
        m_rootNode = new BSTNode(iv);
        return true;
    }
    else
    {
        return m_rootNode->_add(iv);
    }
}

void BinarySearchTree::Traverse(std::vector<int> &result, Traversal order)
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

void BinarySearchTree::Traverse(std::vector<int> &result, Traversal order, std::ostream &out)
{
    if (m_rootNode == nullptr)
    {
        return;
    }
    else
    {
        m_rootNode->_traverse(result, order);

        for (int i : result)
        {
            out << i << ", ";
        }

        out << std::endl;
    }
}
#endif