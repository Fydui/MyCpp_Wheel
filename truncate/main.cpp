#include <iostream>
using namespace std;
const int SUM = 10;
//�������SUM���ַ�,�򳬹����ַ���������������..��������
inline void eatline(){
    while(cin.get() != '\n'){
        cout << "eatline() done..." << endl;
        continue;
    }
}

int main()
{
    char name [SUM] ;
    char title[SUM];

    cout << "�����ַ���: " << endl;
    cin.get(name,SUM);
    if (cin.peek() != '\n');
       cout << "����: "<< name <<" ��˵�洢�ռ��㹻" << endl;
    eatline();
    cout<< "�����ַ���2" << endl;

    cin.get(title,SUM);
    if(cin.peek() != '\n')
        cout << "���Ƚض��ַ���2" << endl;
    eatline();
    cout << "�ַ���1: " << name << " �ַ���2: " << title << endl;

    return 0;
}
