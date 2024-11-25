#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include "array_list.h"

bool ArrayList::Push_back(int p_newInt)
{
    if (m_length == m_size)
    {
        _resize();
    }

    m_valueList[m_length] = p_newInt;
    m_length += 1;
    return true;
}

bool ArrayList::RemoveAt(size_t p_index)
{
    if (p_index >= m_length)
    {
        // out-of-range
        return false;
    }

    // this can handle overlapping memory, while memcpy() won't.
    memmove(m_valueList + p_index,
            m_valueList + (p_index + 1),
            (m_length - p_index - 1) * sizeof(int));

    m_length -= 1;
    return true;
}

size_t ArrayList::Length(void)
{
    return m_length;
}

int &ArrayList::ElementAt(size_t p_index)
{
    if (p_index >= m_length)
    {
        throw std::overflow_error("Index out of range!");
    }

    return m_valueList[p_index];
}

bool ArrayList::_resize()
{
    // now the intermal m_valueList is full, i.e. m_length == m_size.
    int *newValueList = new int[m_size + 100]; // 100 new space.

    if (newValueList == nullptr)
    {
        // allocation fails
        throw std::overflow_error("Memory allocation failure!");
    }

    if (m_size != 0)
    {
        // copy
        memcpy(newValueList, m_valueList, sizeof(m_valueList)); // memcpy(dest, src, size);
        // release old one
        delete m_valueList;
    }

    m_valueList = newValueList;
    m_size += 100;
    return true;
}

ArrayList::~ArrayList(void)
{
    delete m_valueList;
}

int &ArrayList::operator[](size_t p_index)
{
    if (p_index >= m_length)
    {
        throw std::overflow_error("Index out of range!");
    }

    return m_valueList[p_index];
}

void ArrayList::PrintAll(std::ostream &out = std::cout)
{
    for (size_t i = 0; i < m_length; i++)
    {
        out << m_valueList[i] << ", ";
    }

    out << std::endl;
}