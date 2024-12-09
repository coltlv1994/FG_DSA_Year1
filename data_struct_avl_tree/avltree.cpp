#include "node.h"
#include "avltree.h"

AvlTree::AvlTree()
{
}

AvlTree::~AvlTree()
{
}

void AvlTree::ClearAll()
{
    m_rootNode->
}

bool AvlTree::Add(int iv)
{
    if (m_rootNode == nullptr)
    {
        m_rootNode = new Node(iv);
        return true;
    }
    else
    {
        return m_rootNode->Add(iv);
    }
}