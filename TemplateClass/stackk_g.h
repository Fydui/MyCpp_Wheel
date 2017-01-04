#ifndef STACKK_G_H
#define STACKK_G_H
#include <iostream>
template <typename T>
class Stack_p
{
private:
    int top;
    int stacksize;
    enum {SIZE = 10};
    T* item;
public:
    explicit Stack_p(int ss = SIZE);
    Stack_p(const Stack_p & st);
    ~Stack_p(){delete [] item;}
    bool isempty(){return top == 0;}
    bool isfull(){return top == SIZE;}
    bool push(const T &st);
    bool pop(T &st);
    Stack_p & operator=(const Stack_p & st);
};
template <typename T>
Stack_p<T>::Stack_p(int ss) : stacksize(ss),top(0)
{
    item = new T[stacksize];
}

template <typename T>
Stack_p<T>::Stack_p(const Stack_p & st) //复制构造函数
{
    stacksize = st.stacksize;
    top = st.top;
    item = new T[stacksize];
    for(int i = 0; i < top; i++)
        item[i] = st.item[i];
}

template <typename T>
bool Stack_p<T>::pop(T &st)
{
    if(top > 0)
    {
        st = item[--top];
        return true;
    }
    else return false;
}

template <typename T>
bool Stack_p<T>::push(const T &st)
{
    if(top < SIZE)
    {
        item[top++] = st;
        return true;
    }
    else return false;
}

template <typename T>
Stack_p<T> & Stack_p<T>::operator =(const Stack_p & st)
{
    if(this == &st) return *this;
    delete [] item;
    stacksize = st.stacksize;
    item = new T[stacksize];
    top = st.top;
    for(int i = 0; i < top; i++)
        item[i] = st.item[i];
    return *this;
}
#endif // STACKK_G_H
