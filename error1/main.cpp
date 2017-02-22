#include <iostream>
#include <cstdlib>
using namespace std;
double hmean(double a,double b)
{

    if(a == -b)
    {
        cout << "这俩数有毛病..." << endl;
        //在不使用abort的情况下 输入 10 和 -10 ,调和平均数是 -inf
        abort();
    }
    return 2.0 * a * b / (a+b);
}

int main()
{
    cout<< "输入俩数以计算调和平均数:";
    double x, y, z;
    while(cin >>x >> y)
    {
        z = hmean(x,y);
        cout<< x <<" 和 "<< y << " 的调和平均数是 " << z << std::endl;
        cout << "输入任意按回车退出" << std::endl;
    }
    cout << "bye 再次按回车退出.";
    return 0;
}
/*
 //error2
#include <cfloat>
using namespace std;
bool hmean_1(double a, double b, double * ans){

    if(a == -b){
        *ans = DBL_MAX;
        return false;
    }
    else {
        *ans = 2.0 * a * b/(a + b);
        return true;
    }
}

int main()
{
    double x, y ,z;
    cout << "输入俩数: " ;
    while(cin >> x >> y)
    {
        if(hmean_1(x,y, &z))
             cout<< x <<" 和 "<< y << " 的调和平均数是 " << z
                 <<"输入任意字符按回车退出:" <<std::endl;
        else
            cout << "这俩数有毛病,输入任意字符按回车退出:" << endl;
    }
    cout << "Bye 再按回车退出" << endl;
    return 0;
}*/
