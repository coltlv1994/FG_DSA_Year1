#include <vector>
#include <stdint.h>
#include "sortlist.h"

void SortList(std::vector<uint32_t> &p_list)
{
    auto listSize = p_list.size();

    for (auto i = 0; i < listSize; i++)
    {
        auto jMin = i;
        for (auto j = i + 1; j < listSize; j++)
        {
            if (p_list[j] < p_list[jMin])
            {
                jMin = j;
            }
        }

        if (jMin != i)
        {
            _swap(p_list[i], p_list[jMin]);
        }
    }
}

void _swap(uint32_t &v1, uint32_t &v2)
{
    uint32_t temp = v1;
    v1 = v2;
    v2 = temp;
}