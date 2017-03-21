#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Grand
{
private:
    int hold;
public:
    Grand(int h = 0) : hold(h){}
    virtual void Speak() const{cout << "Grand" << endl;}
    virtual int Value() const{return hold;}
};

class Superb : public Grand
{
public:
    Superb(int h = 0) : Grand(h){}
    void Speak() const {cout << "Superb" << endl;}
    virtual void Say() const{cout << "superb value of " << Value() << endl;}
};

class Magn : public Superb
{
private:
    char ch;
public:
    Magn(int h = 0,char c = 'A') : Superb(h),ch(c){}
    void Speak() const {cout << "Magn" << endl;}
    void Say() const{cout << "I hold the character " << ch << "and the integer " << Value() << endl;}
};

Grand * GetOne(){
    Grand * p;
    switch(std::rand() % 3)
    {
       case 0 : p = new Grand(std::rand() % 100);
                break;
       case 1 : p = new Superb(std::rand() % 100);
                break;
       case 2 : p = new Magn(std::rand() % 100,'A' + std::rand() % 26);
                break;
    }
    return p;
}

int main()
{
    std::srand(std::time(0));
    Grand * pg;
    Superb * ps;
    for(int i = 0; i < 5; i++)
    {
        pg = GetOne();
        pg->Speak();
        if(ps = dynamic_cast<Superb *>(pg)) //检测pg是否可以安全的将其转化为Superb类型
            ps->Say();
        if(typeid(Magn) == typeid(*pg))
            cout << "Magn == *pg" << endl; //检测*pg的类型和Magn是否相同
    }
    return 0;
}
