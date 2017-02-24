#include <iostream>
#include <exc_mean.h>
#include <math.h>
using namespace std;

double hmean(double a,double n){
    if(a == -n)
        throw bad_hmean(a,n);
    return 2.0 * a * n / (a+n);
}

double gmean(double a,double b){
    if(a < 0 || b < 0)
        throw bad_gmean(a,b);
    return sqrt(a*b);
}
int main()
{
    double x, y, z;
    cout << "请输入俩数: ";
    while(cin >> x >> y){
        try{
            z = hmean(x,y);
            cout << x << "和" << y<<" 的调和平均数: " << z << endl;
            cout << x << "和" << y<<" 的几何平均值: " << gmean(x,y) << endl;
            cout << "输入任意字符串退出:" ;
        }
        catch (bad_gmean & bg){
            cout << bg.mesg();
            cout << bg.v1 <<"," << bg.v2 << endl;
            cout << "你这俩数不好使" << endl;
            break;
        }
        catch (bad_hmean & bh){
            bh.mesg();
            //cout << bh.a1 << "," << bh.a2 << endl;
            cout << "你这俩数不好使" << endl;
            break;
        }
    }
    cout << "bye 再次按回车退出" << endl;
    return 0;
}
