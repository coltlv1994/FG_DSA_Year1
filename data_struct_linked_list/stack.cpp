#include <stdint.h>
#include "stack.h"

Stack::Stack(size_t size)
{
    m_stack = new char[size];
    m_stackSize = size;
}

Stack::~Stack(void)
{
    delete(m_stack);
}

bool Stack::Pop(char &c)
{
    if (m_stackHead == -1)
    {
        return false; // stack underflow
    }

    c = m_stack[m_stackHead];
    m_stackHead -= 1;
    return true;
}

bool Stack::Push(char c)
{
    if (m_stackHead == m_stackSize - 1)
    {
        return false; // stack overflow
    }

    m_stackHead += 1;
    m_stack[m_stackHead] = c;
    return true;
}

bool Stack::Peek(char &c)
{
    if (m_stackHead == -1)
    {
        return false; // empty
    }

    c = m_stack[m_stackHead];
    return true;
}

void Stack::Clear(void)
{
    m_stackHead = -1;
}