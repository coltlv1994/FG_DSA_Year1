#include <iostream>
#include <vector>
#include "bst.h"

int main(void)
{
    BinarySearchTree<int> bstInt = BinarySearchTree<int>();

    bstInt.Add(65);
    bstInt.Add(110);
    bstInt.Add(100);

    std::vector<int> result;
    bstInt.Traverse(result, Traversal::InOrder);

    for (int i : result)
    {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    return 0;
}