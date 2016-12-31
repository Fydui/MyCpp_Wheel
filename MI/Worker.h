#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>
using namespace std;
class Worker{
public:
    Worker() : name("NULL"),id(0L){}
    Worker(const string & s,long n) : name(s),id(n){}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
protected:
    virtual void Data() const;
    virtual void Get();
private:
    string name;
    long id;
};

class Waiter : virtual public Worker
{
public:
    Waiter() : Worker(),panache(0){}
    Waiter(const string & s, long n, int p = 0) :
        Worker(s,n),panache(p){}
    Waiter(const Worker & w, int p) : Worker(w),panache(p){}
    void Set();
    void Show() const;
protected:
    void Data() const;
    void Get();
private:
    int panache;
};

class Singer : virtual public Worker
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
    void Data() const;
    void Get();
private:
    static char* pv[Vtypes];
    int voice;
};

class SingingWaiter : public Singer, public Waiter
{
public:
    SingingWaiter(){}
    SingingWaiter(const string & st,long n,int p = 0, int v = other)
                    :Worker(st,n),Waiter(st,n,p),Singer(st,n,v){}
    SingingWaiter(const Worker & wo, int p = 0, int v = other)
                    :Worker(wo),Waiter(wo,p),Singer(wo,v){}
    SingingWaiter(const Waiter & wa,int v= other)
                    :Worker(wa),Waiter(wa),Singer(wa,v){}
    SingingWaiter(const Singer & si ,int p = 0)
                    :Worker(si),Waiter(si,p),Singer(si){}
    void Set();
    void Show() const;

protected:
    void Data() const;
    void Get();

};
#endif // WORKER_H
