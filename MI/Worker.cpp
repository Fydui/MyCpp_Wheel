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
    cout << "请输入名字:";
    getline(cin,name);
    cout << "请输入ID:";
    cin >> id;
    while(cin.get() != '\n') continue;
}


//---------------------------

void Waiter::Set(){
    cout << "请输入名字:";
    Worker::Get();
    Get();
}
void Waiter::Show() const
{
    cout << "类别: Waiter" <<endl;
    Worker::Data();
    Data();
}
void Waiter::Data() const{
    cout << "评级: "<< panache << endl;
}
void Waiter::Get(){
    cout << "输入评级: ";
    cin >> panache;
    while(cin.get() != '\n') continue;
}
//-------------------------------
void Singer::Set()
{
    cout << "请输入歌者姓名: ";
    Worker::Get();
    Data();
}

void Singer::Show() const
{
    cout << "类别: Singer" <<endl;
    Worker::Data();
    Data();
}
void Singer::Data() const{
    cout << "声音类别: " << pv[voice] << endl;
}
void Singer::Get()
{
    cout << "输入数字对应声音类别:" << endl;
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
    cout << "请输入名字: ";
    Worker::Get();
    Get();
}
void SingingWaiter::Show()const{
    Worker::Data();
    Data();
}

