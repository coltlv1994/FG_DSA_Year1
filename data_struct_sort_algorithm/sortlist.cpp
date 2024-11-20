#include <vector>
#include <stdint.h>
#include "sortlist.h"

void InsertionSort(std::vector<uint32_t> &p_list)
{
    // Insertion sort
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

void ShellSort(std::vector<uint32_t> &p_list)
{
    // Shellsort
    auto listSize = p_list.size();

    for (auto gap = listSize / 2; gap > 0; gap /= 2)
    {
        for (auto i = gap; i < listSize; i++)
        {
            int temp = p_list[i];

            auto j = i;
            for (; j >= gap && p_list[j - gap] > temp; j -= gap)
            {
                p_list[j] = p_list[j - gap];
            }

            p_list[j] = temp;
        }
    }
}

void _swap(uint32_t &v1, uint32_t &v2)
{
    uint32_t temp = v1;
    v1 = v2;
    v2 = temp;
}