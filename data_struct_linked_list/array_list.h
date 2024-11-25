#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#include <iostream>
#include <cstdint>

class ArrayList
{
public:
    bool Push_back(int p_newInt);
    bool RemoveAt(size_t p_index);
    size_t Length(void);
    int &ElementAt(size_t p_index);
    ~ArrayList(void);
    int &operator[](size_t index);

    void PrintAll(std::ostream &out = std::cout);

private:
    int *m_valueList = nullptr;
    size_t m_size = 0;   // size of internal memory area
    size_t m_length = 0; // occupied
    bool _resize();
};

#endif