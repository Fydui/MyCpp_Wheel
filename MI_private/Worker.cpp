#include "Worker.h"
char * Singer::pv[] = {"other","alto","contralto",
                       "soprano","bass","baritone","tenor"};

Worker::~Worker(){}
void Worker::Set()
{
    cout << "����������:";
    getline(cin,name);
    cout << "������ID:";
    cin >> id;
    while(cin.get() != '\n') continue;
}

void Worker::Show() const{
    cout <<"Name: " << name << endl;
    cout << "ID: " << id << endl;
}

void Waiter::Set(){
    Worker::Set();
    cout << "����������:";
    cin >> panache;
    while(cin.get() != '\n')
        continue;
}
void Waiter::Show() const
{
     cout << "���: " <<endl;
     Worker::Show();
     cout << "����: " << panache <<endl;
}

void Singer::Set()
{
    Worker::Set();
    cout << "������ֵ��������:";
    int i;
    for(i= 0; i < Vtypes;i++)
    {
        cout << i << " : " << pv[i] << " ";
        if( i % 4 == 3)
            cout << endl;
    }
    if(i % 4 != 0)
        cout << endl;
    while(cin >> voice && (voice < 0 || voice >=Vtypes))
        cout << "��������ȷ����ֵ: value>=0 ���� <" << Vtypes << endl;
    while(cin.get() != '\n')
        continue;
}

void Singer::Show() const {
    cout << "���:����" <<endl;
    Worker::Show();
    cout << "�������: " << pv[voice] << endl;
}
