#include <iostream>
#include<string>
using namespace std;

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
        return true;
    }
    else
        return false;
}

template<template <typename T>class Thing>
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab(){}
    bool push(int a,double x){
        return
                s1.push(a) &&
                s2.push(x);}
    bool pop(int & a,double & x){return s1.pop(a) && s2.pop(x);}
};

int main(){
    Crab<Stack> cs;
    int ni;
    double nd;
    cout << "Enter int double pairs,such as 4 3.5(0 0 to end):" << endl;
    while (cin >> ni >>nd && ni > 0 && nd > 0)
    {
        if(!cs.push(ni,nd))
            break;
    }
    while(cs.pop(ni,nd))
        cout << ni << " , " << nd << endl;
    cout << "DONE" <<endl;

    return 0;
}
