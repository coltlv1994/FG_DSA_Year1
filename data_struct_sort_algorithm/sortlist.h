#ifndef _SORTLIST_H_
#define _SORTLIST_H_

#include <stdint.h>
#include <vector>

void InsertionSort(std::vector<uint32_t> &p_list);

void ShellSort(std::vector<uint32_t> &p_list);

void _swap(uint32_t &v1, uint32_t &v2);

#endif