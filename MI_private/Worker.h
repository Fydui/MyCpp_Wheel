#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>
using namespace std;
class Worker
{
public:
    Worker() : name("NULL"),id(0L){}
    Worker(const string & s,long n) : name(s),id(n){}
    virtual ~Worker() = 0;
    virtual void Set();
    virtual void Show() const;
private:
    string name;
    long id;
};

class Waiter : public Worker
{
public:
    Waiter() : Worker(),panache(0){}
    Waiter(const string & s, long n, int p = 0) :
        Worker(s,n),panache(p){}
    Waiter(const Worker & w, int p) : Worker(w),panache(p){}
    void Set();
    void Show() const;
private:
    int panache;
};

class Singer : public Worker
{
public:
    Singer() : Worker(),voice(other){}
    Singer(const string & s, long n, int v = other) :
        Worker(s,n),voice(v){}
    Singer(const Worker & w, int v =other) : Worker(w),voice(v){}
    void Set();
    void Show() const;
protected:
    enum{other,alto,contralto,soprano,bass,baritone,tenor};
    enum{Vtypes = 7};
private:
    static char* pv[Vtypes];
    int voice;
};

#endif // WORKER_H
