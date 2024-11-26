#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#include <iostream>
#include <cstdint>

template <typename T>
class ArrayList
{
public:
    bool Push_back(T p_newElement);
    bool RemoveAt(size_t p_index);
    size_t Length(void);
    T &ElementAt(size_t p_index);
    ~ArrayList(void);
    T &operator[](size_t index);

    void PrintAll(std::ostream &out = std::cout);

    // sorting algorithms
    void InsertionSort(void);
    void ShellSort(void);

private:
    T *m_valueList = nullptr;
    size_t m_size = 0;   // size of internal memory area
    size_t m_length = 0; // occupied
    bool _resize();
    void _swap(T &a, T &b);
};

template <typename T>
bool ArrayList<T>::Push_back(T p_newElement)
{
    if (m_length == m_size)
    {
        _resize();
    }

    m_valueList[m_length] = p_newElement;
    m_length += 1;
    return true;
}

template <typename T>
bool ArrayList<T>::RemoveAt(size_t p_index)
{
    if (p_index >= m_length)
    {
        // out-of-range
        return false;
    }

    // this can handle overlapping memory, while memcpy() won't.
    memmove(m_valueList + p_index,
            m_valueList + (p_index + 1),
            (m_length - p_index - 1) * sizeof(T));

    m_length -= 1;
    return true;
}

template <typename T>
size_t ArrayList<T>::Length(void)
{
    return m_length;
}

template <typename T>
T &ArrayList<T>::ElementAt(size_t p_index)
{
    if (p_index >= m_length)
    {
        throw std::overflow_error("Index out of range!");
    }

    return m_valueList[p_index];
}

template <typename T>
bool ArrayList<T>::_resize()
{
    // now the intermal m_valueList is full, i.e. m_length == m_size.
    T *newValueList = new T[m_size + 100]; // 100 new space.

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

template <typename T>
ArrayList<T>::~ArrayList(void)
{
    delete m_valueList;
}

template <typename T>
T &ArrayList<T>::operator[](size_t p_index)
{
    if (p_index >= m_length)
    {
        throw std::overflow_error("Index out of range!");
    }

    return m_valueList[p_index];
}

template <typename T>
void ArrayList<T>::PrintAll(std::ostream &out)
{
    for (size_t i = 0; i < m_length; i++)
    {
        out << m_valueList[i] << ", ";
    }

    out << std::endl;
}

template <typename T>
void ArrayList<T>::_swap(T &v1, T &v2)
{
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

template <typename T>
void ArrayList<T>::InsertionSort(void)
{
    for (size_t i = 0; i < m_length; i++)
    {
        size_t jMin = i;
        for (size_t j = i + 1; j < m_length; j++)
        {
            if (m_valueList[j] < m_valueList[jMin])
            {
                jMin = j;
            }
        }

        if (jMin != i)
        {
            _swap(m_valueList[i], m_valueList[jMin]);
        }
    }
}

template <typename T>
void ArrayList<T>::ShellSort(void)
{
    size_t gap = 1;
    while (gap < m_length / 3)
    {
        // choose an initial gap
        gap = 3 * gap + 1;
    }

    while (gap >= 1)
    {
        for (size_t i = gap; i < m_length; i++)
        {
            for (size_t j = i; j >= gap && m_valueList[j] < m_valueList[j - gap]; j -= gap)
            {
                _swap(m_valueList[j], m_valueList[j - gap]);
            }
        }

        gap /= 3;
    }
}

#endif