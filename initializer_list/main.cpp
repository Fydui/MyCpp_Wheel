#include <iostream>
#include <initializer_list>
using namespace std;

double sum(initializer_list<double> il)
{
    double s = 0;
    for(auto p = il.begin(); p != il.end(); p++)
        s += *p;
    return s;
}

double average(const initializer_list<double> & av)
{
    double s = 0;
    double n = av.size();
    if(n > 0){
    for(auto p = av.begin(); p != av.end(); p++)
        s += *p;
    s = s/n;
    }
    return s;
}

int main()
{
    cout << "List 1: sum = " << sum({2,3,4});
    cout << "ave = " << average({2,3,4}) << endl;
    initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "List 2: sum = " << sum(dl);
    cout << "ave = " << average(dl) << endl;
    dl = {16.0, 25.0, 36.0, 40.0, 64.0};
    cout << "List 3: sum = " << sum(dl);
    cout << "ave = " << average(dl) << endl;
    return 0;
}
