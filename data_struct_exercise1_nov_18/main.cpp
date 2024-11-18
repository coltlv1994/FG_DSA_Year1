#include <iostream>
#include <vector>
#include "mersenne.h"
#include "sortlist.h"

int main(void)
{
    const uint32_t seeds  = 5000;

    Mersenne mt = Mersenne();

    std::vector<uint32_t> randomList;

    mt.Seed(seeds);

    for (int i = 0; i < 100; i++)
    {
        randomList.push_back(mt.Rand_u32());
    }

    SortList(randomList);

    for (uint32_t i : randomList)
    {
        std::cout << i << std::endl;
    }

    return 0;
}