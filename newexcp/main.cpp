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
        cout << "试着申请一大块儿内存" << endl;
        pb = new Big[100000];
        /*pb = new (std::nothrow) Big[10000]; //这样在内存请求失败的时候会返回空指针
        if(){
            cout << "请求失败" << endl;
            exit(EXIT_FAILURE);
        }*/
        cout << "请求通过" << endl;
    }
    catch(bad_alloc & ba){
        cout << "捕捉到异常" << endl;
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    cout << "成功分配内存" << endl;
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete [] pb;
    return 0;
}
