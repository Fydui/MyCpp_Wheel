#include "Worker.h"
char * Singer::pv[] = {"other","alto","contralto",
                       "soprano","bass","baritone","tenor"};

Worker::~Worker(){}
void Worker::Data() const
{
    cout <<"Name: " << name << endl;
    cout << "ID: " << id << endl;
}

void Worker::Get()
{
    cout << "����������:";
    getline(cin,name);
    cout << "������ID:";
    cin >> id;
    while(cin.get() != '\n') continue;
}


//---------------------------

void Waiter::Set(){
    cout << "����������:";
    Worker::Get();
    Get();
}
void Waiter::Show() const
{
    cout << "���: Waiter" <<endl;
    Worker::Data();
    Data();
}
void Waiter::Data() const{
    cout << "����: "<< panache << endl;
}
void Waiter::Get(){
    cout << "��������: ";
    cin >> panache;
    while(cin.get() != '\n') continue;
}
//-------------------------------
void Singer::Set()
{
    cout << "�������������: ";
    Worker::Get();
    Data();
}

void Singer::Show() const
{
    cout << "���: Singer" <<endl;
    Worker::Data();
    Data();
}
void Singer::Data() const{
    cout << "�������: " << pv[voice] << endl;
}
void Singer::Get()
{
    cout << "�������ֶ�Ӧ�������:" << endl;
    int i;
    for( i = 0; i < Vtypes; i++){
        cout << i << ":" << pv[i] << " ";
        if(i%4 == 3)
            cout << endl;
    }
    if(i % 4 != 0)
        cout << '\n';
    cin >> voice;
    while(cin.get() != '\n')
        continue;
}
//------------------
void SingingWaiter::Data() const
{
    Singer::Data();
    Waiter::Data();
}
void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}
void SingingWaiter::Set(){
    cout << "����������: ";
    Worker::Get();
    Get();
}
void SingingWaiter::Show()const{
    Worker::Data();
    Data();
}

