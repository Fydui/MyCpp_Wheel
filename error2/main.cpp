#include <iostream>
using namespace std;
double hmean(double a, double b){
    if(a == -b)
        throw "异常:这俩数有毛病"; //异常被触发
    return 2.0 * a * b /(a + b);
}
int main()
{
    double x , y, z;
    cout << "请输入俩数: ";
    while(cin >> x >> y)
    {
        try {
           z = hmean(x,y); //try块里的表示需要注意这些代码可能触发异常
        }
        catch (const char * s){ //捕捉到异常 程序跳到这儿 发现char类型与 throw后面的字符串匹配
            cout << s << endl;  //匹配之后执行代码块内的代码处理异常
            cout << "请重试: ";
            continue;
        }
        cout << x << " 和 " << y << " 这俩数的调和平均数是: " << z << endl;
        cout << "输入任意字符串退出: ";
    }
    cout << "bye,再按回车退出" << endl;
}
