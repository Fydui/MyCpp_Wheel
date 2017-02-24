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
    cout << "����������: ";
    while(cin >> x >> y){
        try{
            z = hmean(x,y);
            cout << x << "��" << y<<" �ĵ���ƽ����: " << z << endl;
            cout << x << "��" << y<<" �ļ���ƽ��ֵ: " << gmean(x,y) << endl;
            cout << "���������ַ����˳�:" ;
        }
        catch (bad_gmean & bg){
            cout << bg.mesg();
            cout << bg.v1 <<"," << bg.v2 << endl;
            cout << "������������ʹ" << endl;
            break;
        }
        catch (bad_hmean & bh){
            bh.mesg();
            //cout << bh.a1 << "," << bh.a2 << endl;
            cout << "������������ʹ" << endl;
            break;
        }
    }
    cout << "bye �ٴΰ��س��˳�" << endl;
    return 0;
}
