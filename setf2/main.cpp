#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //使用左对齐，显示加号，显示尾随零，精度为3
    cout.setf(ios_base::left,ios_base::adjustfield);
    cout.setf(ios_base::showpos);
    cout.setf(ios_base::showpoint);
    cout.precision(3);

    //使用e表示法,保存旧的格式设置
    ios_base::fmtflags old = cout.setf(ios_base::scientific,ios_base::floatfield);
    cout << "左对齐:" << endl;
    long n;
    for(n = 1; n < 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|" << endl;
    }

    //改为内对齐
    cout.setf(ios_base::internal,ios_base::adjustfield);
    //恢复默认浮点显示样式
    cout.setf(old,ios_base::floatfield);
    cout << "内对齐:" << endl;
    for(n = 1; n < 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|" << endl;
    }

    //右对齐,使用定点计数法
    cout.setf(ios_base::right,ios_base::adjustfield);
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout << "右对齐:" << endl;
    for(n = 1; n < 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|" << endl;
    }


    return 0;
}
