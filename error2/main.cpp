#include <iostream>
using namespace std;
double hmean(double a, double b){
    if(a == -b)
        throw "�쳣:��������ë��"; //�쳣������
    return 2.0 * a * b /(a + b);
}
int main()
{
    double x , y, z;
    cout << "����������: ";
    while(cin >> x >> y)
    {
        try {
           z = hmean(x,y); //try����ı�ʾ��Ҫע����Щ������ܴ����쳣
        }
        catch (const char * s){ //��׽���쳣 ����������� ����char������ throw������ַ���ƥ��
            cout << s << endl;  //ƥ��֮��ִ�д�����ڵĴ��봦���쳣
            cout << "������: ";
            continue;
        }
        cout << x << " �� " << y << " �������ĵ���ƽ������: " << z << endl;
        cout << "���������ַ����˳�: ";
    }
    cout << "bye,�ٰ��س��˳�" << endl;
}
