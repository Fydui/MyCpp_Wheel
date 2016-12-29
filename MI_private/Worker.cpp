#include "Worker.h"
char * Singer::pv[] = {"other","alto","contralto",
                       "soprano","bass","baritone","tenor"};

Worker::~Worker(){}
void Worker::Set()
{
    cout << "请输入名字:";
    getline(cin,name);
    cout << "请输入ID:";
    cin >> id;
    while(cin.get() != '\n') continue;
}

void Worker::Show() const{
    cout <<"Name: " << name << endl;
    cout << "ID: " << id << endl;
}

void Waiter::Set(){
    Worker::Set();
    cout << "请输入评级:";
    cin >> panache;
    while(cin.get() != '\n')
        continue;
}
void Waiter::Show() const
{
     cout << "类别: " <<endl;
     Worker::Show();
     cout << "评级: " << panache <<endl;
}

void Singer::Set()
{
    Worker::Set();
    cout << "输入歌手的声音类别:";
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
        cout << "请输入正确的数值: value>=0 并且 <" << Vtypes << endl;
    while(cin.get() != '\n')
        continue;
}

void Singer::Show() const {
    cout << "类别:歌手" <<endl;
    Worker::Show();
    cout << "声音类别: " << pv[voice] << endl;
}
