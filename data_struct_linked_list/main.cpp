#include <iostream>
#include "array_list.h"

int main(void)
{
    ArrayList al;

    for (int i = 0; i < 20; i++)
    {
        al.Push_back(i);
    }

    std::cout << al[5] << std::endl;

    al[5] = 50;

    al.PrintAll();

    return 0;
}