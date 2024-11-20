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

    std::cout << ll.ContainsLoop() << std::endl;

    Node* node = ll.GetNodeByIndex(5);
    Node* nodeLoop = ll.GetNodeByIndex(2);
    Node* nodeToReconnect = node->GetNext();

    node->SetNext(nodeLoop); // now a loop is created on purpose

    std::cout << ll.ContainsLoop() << std::endl;

    node->SetNext(nodeToReconnect); // restore it

    std::cout << ll.ContainsLoop() << std::endl;

    return 0;
}