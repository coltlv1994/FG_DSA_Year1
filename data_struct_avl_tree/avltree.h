#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include "node.h"

class AvlTree
{
    public:
    AvlTree();
    ~AvlTree();
    void ClearAll();
    bool Add(int iv);

    private:
    Node* m_rootNode = nullptr;
};

#endif