#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

template<class T>
class TooBig
{
public:
    T cutoff;
    TooBig(const T & t) : cutoff(t) {}
    bool operator()(const T & c){return c > cutoff;}
};

void outint(int n){cout << n << " ";}

int main()
{
    TooBig<int> f100(30);
    int vals[10] = {10,20,30,40,50,60,70,80,90,100};
    list<int> a(vals,vals+10);
    list<int> b(vals,vals+10);

    for_each(a.begin(),a.end(),outint);
    cout << endl;
    for_each(b.begin(),b.end(),outint);
    cout << endl;

    a.remove_if(f100);//bool(*)(const T & c)
    b.remove_if(TooBig<int>(50));

    for_each(a.begin(),a.end(),outint);
    cout << endl;
    for_each(b.begin(),b.end(),outint);
    cout << endl;

    return 0;
}

