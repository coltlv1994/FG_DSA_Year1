#include <iostream>
#include <random>
#include "linked_list.h"
#include "array_list.h"

int main(void)
{
    std::uniform_real_distribution<double> rng(0.0, 1.0);
    std::default_random_engine re;

    ArrayList<double> al;

    for (int i = 0; i < 20; i++)
    {
        al.Push_back(rng(re));
    }

    al.PrintAll();

    return 0;
}