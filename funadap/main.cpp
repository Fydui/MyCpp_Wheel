#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
const int LIM = 6;
void Show(double v)
{
    cout.width(6);
    cout << v << ' ';
}
int main()
{
    double arr1[LIM] = {28,29,30,35,38,59};
    double arr2[LIM] = {63,65,69,75,80,99};
    vector<double> g(arr1,arr1+LIM);
    vector<double> m(arr2,arr1+LIM);
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "g:\t";
    for_each(g.begin(),g.end(),Show);
    cout << endl;
    cout << "m: \t";
    for_each(m.begin(),m.end(),Show);
    cout << endl;
    vector<double> sum(LIM);
    transform(g.begin(),g.end(),m.begin(),sum.begin(),plus<double>());
    cout << "sum :\t";
    for_each(sum.begin(),sum.end(),Show);
    cout << endl;

    vector<double>prod(LIM);
    transform(g.begin(),g.end(),prod.begin(),bind1st(multiplies<double>(),2.5));
    cout << "prod :\t";
    for_each(prod.begin(),prod.end(),Show);
    cout << endl;


    return 0;
}

