#include <iostream>
#include "linkedlist.h"

int main(void)
{
    LinkedList ll;

    for (int i = 0; i < 15; i++)
    {
        ll.Append(i);
    }

    std::cout << ll.GetNodeByIndex(5)->GetValue() << std::endl;

    ll.RemoveNodeByIndex(5);

    std::cout << ll.GetNodeByIndex(5)->GetValue() << std::endl;

    ll.InsertAfterIndex(10, 4);

    std::cout << ll.GetNodeByIndex(5)->GetValue() << std::endl;

    return 0;
}