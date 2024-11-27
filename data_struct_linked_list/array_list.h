#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#include <iostream>

template <typename T>
class ArrayList
{
public:
    bool Push_back(T p_newElement);
    bool RemoveAt(int p_index);
    int Length(void);
    T &ElementAt(int p_index);
    ~ArrayList(void);
    T &operator[](int index);

    void PrintAll(std::ostream &out = std::cout);

    // sorting algorithms
    void InsertionSort(void);
    void ShellSort(void);
    void QuickSort(void);

private:
    T *m_valueList = nullptr;
    int m_size = 0;   // size of internal memory area
    int m_length = 0; // occupied
    bool _resize();
    void _swap(T &a, T &b);
    void _quicksort(int lowIndex, int highIndex);
    int _partition(int lowIndex, int highIndex);
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
bool ArrayList<T>::RemoveAt(int p_index)
{
    if (p_index >= m_length || p_index < 0)
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
int ArrayList<T>::Length(void)
{
    return m_length;
}

template <typename T>
T &ArrayList<T>::ElementAt(int p_index)
{
    if (p_index >= m_length || p_index < 0)
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
T &ArrayList<T>::operator[](int p_index)
{
    if (p_index >= m_length || p_index < 0)
    {
        throw std::overflow_error("Index out of range!");
    }

    return m_valueList[p_index];
}

template <typename T>
void ArrayList<T>::PrintAll(std::ostream &out)
{
    for (int i = 0; i < m_length; i++)
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
    for (int i = 0; i < m_length; i++)
    {
        int jMin = i;
        for (int j = i + 1; j < m_length; j++)
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
    int gap = 1;
    while (gap < m_length / 3)
    {
        // choose an initial gap
        gap = 3 * gap + 1;
    }

    while (gap >= 1)
    {
        for (int i = gap; i < m_length; i++)
        {
            for (int j = i; j >= gap && m_valueList[j] < m_valueList[j - gap]; j -= gap)
            {
                _swap(m_valueList[j], m_valueList[j - gap]);
            }
        }

        gap /= 3;
    }
}

template <typename T>
void ArrayList<T>::QuickSort(void)
{
    _quicksort(0, m_length - 1);
}

template <typename T>
void ArrayList<T>::_quicksort(int lowIndex, int highIndex)
{
    if (lowIndex < highIndex)
    {
        int partitionIndex = _partition(lowIndex, highIndex);

        _quicksort(lowIndex, partitionIndex - 1);
        _quicksort(partitionIndex + 1, highIndex);
    }
}

template <typename T>
int ArrayList<T>::_partition(int lowIndex, int highIndex)
{
    T pivotValue = m_valueList[lowIndex];

    int writeIndex = highIndex;

    for (int compareIndex = highIndex; compareIndex > lowIndex; compareIndex -= 1)
    {
        if (m_valueList[compareIndex] >= pivotValue)
        {
            _swap(m_valueList[compareIndex], m_valueList[writeIndex]);
            writeIndex -= 1;
            PrintAll();
        }
    }

    _swap(m_valueList[writeIndex], m_valueList[lowIndex]);

    PrintAll();
    std::cout << "writeIndex: " << writeIndex << ", pivotValue: " << pivotValue << ", lowIndex: " << lowIndex << ", highIndex" << highIndex << std::endl;
    std::cout << std::endl;

    return writeIndex;
}
#endif