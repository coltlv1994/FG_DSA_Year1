#include <iostream>
#include "linked_list.h"
#include "array_list.h"

int main(void)
{
    LinkedList<int> ll;

    for (int i = 0; i < 20; i++)
    {
        ll.Append(i);
    }

    ll.PrintAll(std::cout);

    return 0;
}