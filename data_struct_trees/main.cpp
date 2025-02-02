#include <iostream>
#include <vector>
#include "bst.h"

int main(void)
{
    BinarySearchTree bstInt = BinarySearchTree();

    bstInt.Add(65);
    bstInt.Add(110);
    bstInt.Add(100);

    std::vector<int> result;
    bstInt.Traverse(result, Traversal::InOrder, std::cout);

    return 0;
}