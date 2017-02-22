#include <iostream>
#include <cstdlib>
using namespace std;
double hmean(double a,double b)
{

    if(a == -b)
    {
        cout << "��������ë��..." << endl;
        //�ڲ�ʹ��abort������� ���� 10 �� -10 ,����ƽ������ -inf
        abort();
    }
    return 2.0 * a * b / (a+b);
}

int main()
{
    cout<< "���������Լ������ƽ����:";
    double x, y, z;
    while(cin >>x >> y)
    {
        z = hmean(x,y);
        cout<< x <<" �� "<< y << " �ĵ���ƽ������ " << z << std::endl;
        cout << "�������ⰴ�س��˳�" << std::endl;
    }
    cout << "bye �ٴΰ��س��˳�.";
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
    cout << "��������: " ;
    while(cin >> x >> y)
    {
        if(hmean_1(x,y, &z))
             cout<< x <<" �� "<< y << " �ĵ���ƽ������ " << z
                 <<"���������ַ����س��˳�:" <<std::endl;
        else
            cout << "��������ë��,���������ַ����س��˳�:" << endl;
    }
    cout << "Bye �ٰ��س��˳�" << endl;
    return 0;
}*/
