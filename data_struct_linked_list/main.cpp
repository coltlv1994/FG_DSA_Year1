#include <iostream>
#include "node.h"
#include "linked_list.h"

int main(void)
{
    LinkedList ll;

    for (int i = 0; i < 15; i++)
    {
        ll.Append(i);
    }

    ll.PrintAll(std::cout);

    ll.RemoveNodeByIndex(5);

    ll.PrintAll(std::cout);

    ll.InsertAfterIndex(10, 4);

    ll.PrintAll(std::cout);

    return 0;
}