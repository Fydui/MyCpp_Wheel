#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

struct Big
{
    double stuff[20000];
};

int main()
{
    Big* pb;
    try{
        cout << "��������һ�����ڴ�" << endl;
        pb = new Big[100000];
        /*pb = new (std::nothrow) Big[10000]; //�������ڴ�����ʧ�ܵ�ʱ��᷵�ؿ�ָ��
        if(){
            cout << "����ʧ��" << endl;
            exit(EXIT_FAILURE);
        }*/
        cout << "����ͨ��" << endl;
    }
    catch(bad_alloc & ba){
        cout << "��׽���쳣" << endl;
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    cout << "�ɹ������ڴ�" << endl;
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete [] pb;
    return 0;
}
