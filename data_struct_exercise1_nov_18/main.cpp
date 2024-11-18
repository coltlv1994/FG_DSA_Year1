#include <iostream>
#include <list>
#include "mersenne.h"

int main(void)
{
    const uint32_t seeds  = 5000;

    Mersenne mt = Mersenne();

    std::list<uint32_t> randomList;

    mt.Seed(seeds);

    for (int i = 0; i < 100; i++)
    {
        randomList.push_back(mt.Rand_u32());
    }

    for (uint32_t i : randomList)
    {
        std::cout << i << std::endl;
    }

    return 0;
}