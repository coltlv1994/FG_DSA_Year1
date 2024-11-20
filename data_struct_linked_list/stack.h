#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>

class Stack
{
    public:
        Stack(size_t size);
        bool Pop(char &c);
        bool Push(char c);
        bool Peek(char &c);
        void Clear(void);
        ~Stack();

    private:
        char* m_stack;
        int m_stackHead = -1;
        size_t m_stackSize;
};

#endif