#include <iostream>
#include <random>
#include "linked_list.h"
#include "array_list.h"

int main(void)
{
    std::random_device r;
    std::uniform_int_distribution<int> rngi(0,49);
    std::default_random_engine re(r());

    ArrayList<int> ali;

    // int predefined[] = {39, 35, 46, 3, 37, 6, 21, 36, 19, 19, 46, 29, 30, 0, 37, 8, 17, 5, 10, 22};

    for (int i = 0; i < 20; i++)
    {
        ali.Push_back(rngi(re));
    }

    // for (int iv : predefined)
    // {
    //     ali.Push_back(iv);
    // }

    ali.PrintAll();

    ali.QuickSort();

    ali.PrintAll();

    return 0;
}