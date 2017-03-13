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
        cout << "demo: " << word << " ����" << endl;
    }
    ~demo(){
        cout << "demo: " << word << " ����" << endl;
    }
    void show() const
    {
        cout << "demo: " << word << " Show��" << endl;
    }
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main(){
    double x,y,z;
    demo d1("��ǰ����: main()");
    cout << "����������: ";
    while(cin >> x >> y)
    {
        try {
            z = means(x,y);
            cout << "" << x << " �� " << y
                 << " ��ƽ��ֵ�� " << z << endl;
            cout << "������һ��: " << endl;
        }
        catch(bad_hmean & bg){
            bg.mesg();
            cout << "��Ҫ���������,����һ��;" << endl;
            continue;
        }
        catch(bad_gmean & hg){
            hg.mesg();
            cout << "values used: " << hg.v1 << ", "
                 << hg.v2 << endl;
            cout << "��������������в�" << endl;
            break;
        }
        d1.show();
    }
    cout << "���ף��,��Ǭ�澭" << endl;
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
    demo d2("��ǰ����: means()");
    am = (a + b) /2.0;
    try{
        hm = hmean(a,b);
        gm = gmean(a,b);
    }
    catch(bad_hmean & bg)
    {
        bg.mesg();
        cout << "����: means() " << endl;
        throw;
    }
    d2.show();
    return (am + gm + hm)/3.0;
}

