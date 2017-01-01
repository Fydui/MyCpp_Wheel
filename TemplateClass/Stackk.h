#ifndef STACK_H
#define STACK_H

template <typename Type>
class Stack
{
private:
    enum {MAX = 10};
    Type item[MAX];
    int top;
public:
    Stack();
    bool isfull();
    bool isempty();
    bool push(const Type & it);
    bool pop(Type & it);
};
template <typename Type>
Stack<Type>::Stack()
{
    top = 0;
}

template <typename Type>
bool Stack<Type>::isempty()
{
    return top == 0;
}

template <typename Type>
bool Stack<Type>::isfull()
{
    return top == MAX;
}

template <typename Type>
bool Stack<Type>::push(const Type &it)
{
    if(top < MAX)
    {
        item[top++] = it;
        return true;
    }
    else
        return false;
}

template <typename Type>
bool Stack<Type>::pop(Type & it)
{
    if(top > 0)
    {
        it = item[--top];
        return 0;
    }
    else
        return false;
}

#endif // STACK_H
