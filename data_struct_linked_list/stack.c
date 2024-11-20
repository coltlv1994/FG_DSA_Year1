#define MAX_STACK_SIZE 100

char _stack[MAX_STACK_SIZE]; // a char takes 1 byte in memory 
int stack_position = -1; // means the stack is empty at start

int Pop(char* c);
int Push(char c);
int Peek(char* c);

int Pop(char* c)
{
    if (stack_position == -1)
    {
        return 1; // stack underflow
    }

    *c = _stack[stack_position];
    stack_position -= 1;
    return 0;
}

int Push(char c)
{
    if (stack_position == MAX_STACK_SIZE - 1)
    {
        return 1; // stack overflow
    }

    stack_position += 1;
    _stack[stack_position] = c;
    return 0;
}

int Peek(char* c)
{
    if (stack_position == -1)
    {
        return 1; // empty
    }

    *c = _stack[stack_position];
    return 0;
}