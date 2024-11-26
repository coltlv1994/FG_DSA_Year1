#include <iostream>
#include <random>
#include "linked_list.h"
#include "array_list.h"

int main(void)
{
    std::random_device r;
    std::uniform_real_distribution<double> rngf(0.0, 1.0);
    std::uniform_int_distribution<int> rngi(0,99);
    std::default_random_engine re(r());

    ArrayList<double> alf;
    ArrayList<int> ali;

    for (int i = 0; i < 20; i++)
    {
        alf.Push_back(rngf(re));
        ali.Push_back(rngi(re));
    }

    alf.InsertionSort();
    ali.ShellSort();

    alf.PrintAll();
    ali.PrintAll();

    return 0;
}