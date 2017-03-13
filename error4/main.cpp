#include <iostream>
#include <cmath>
#include <string>
#include "exc_mean.h"
using namespace std;
class demo
{
private:
    string word;
public:
    demo(const string & str){
        word = str;
        cout << "demo: " << word << " 创建" << endl;
    }
    ~demo(){
        cout << "demo: " << word << " 销毁" << endl;
    }
    void show() const
    {
        cout << "demo: " << word << " Show出" << endl;
    }
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main(){
    double x,y,z;
    demo d1("当前处于: main()");
    cout << "请输入俩数: ";
    while(cin >> x >> y)
    {
        try {
            z = means(x,y);
            cout << "" << x << " 和 " << y
                 << " 的平均值是 " << z << endl;
            cout << "输入下一对: " << endl;
        }
        catch(bad_hmean & bg){
            bg.mesg();
            cout << "不要搞个大新闻,再试一次;" << endl;
            continue;
        }
        catch(bad_gmean & hg){
            hg.mesg();
            cout << "values used: " << hg.v1 << ", "
                 << hg.v2 << endl;
            cout << "你输入的这俩数有病" << endl;
            break;
        }
        d1.show();
    }
    cout << "最后祝您,提乾涉经" << endl;
    return 0;
}
double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a,b);
    return 2.0 * a * b /(a+b);
}
double gmean(double a, double b)
{
    if(a < 0 || b < 0)
        throw bad_gmean(a,b);
    return sqrt(a * b);
}
double means(double a, double b)
{
    double am, hm ,gm;
    demo d2("当前处于: means()");
    am = (a + b) /2.0;
    try{
        hm = hmean(a,b);
        gm = gmean(a,b);
    }
    catch(bad_hmean & bg)
    {
        bg.mesg();
        cout << "卡在: means() " << endl;
        throw;
    }
    d2.show();
    return (am + gm + hm)/3.0;
}

