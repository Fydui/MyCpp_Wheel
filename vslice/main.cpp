#include <iostream>
#include <valarray>
#include <cstdlib>
using namespace std;
const int SIZE = 12;

void show(const valarray<int>& v, int cols)
{
    int lim = v.size();
    for(int i = 0; i < lim; ++i)
    {
        cout.width(3);
        cout << v[i];
        if(i % cols == cols -1)
            cout<< endl;
        else
            cout << ' ';
    }
    if(lim % cols != 0)
        cout << endl;
}
int main()
{
    valarray<int> vint(SIZE);

    int i = 0;
    for(; i < SIZE; ++i)
        vint[i] = rand() % 10;
    cout << "原始数据: " << endl;
    show(vint,3);
    valarray<int> vcol(vint[slice(1,4,3)]);
    cout << "第二列: " << endl;
    show(vcol,1);
    valarray<int> vrow(vint[slice(3,3,1)]);
    cout << "第二行: " << endl;
    show(vrow,3);
    cout << "将最后一列设为10:" <<endl;
    show(vint,3);
    cout << "将第一列设置为下两个的总和:" << endl;
    vint[slice(0,4,3)] = valarray<int>(vint[slice(1,4,3)])
            + valarray<int>(vint[slice(2,4,3)]);
    show(vint,3);

    return 0;
}

