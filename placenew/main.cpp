#include<iostream>
#include<string>
#include<new>
using namespace std;
const int BUF = 512;

class Test{
private:
    string words;
    int number;
public:
    Test(const string& s ="C++",int n = 0){
        words = s; number = n;
        cout << words << " 构造函数被调用" << endl;
    }
    ~Test(){
        cout << words << " 析构函数被调用" << endl;
    }
    void show(){
        cout << words << " , 编号: " << number << endl;

    }
    friend ostream & operator<<(ostream & os, Test & t){
        os << t.words<<" 编号:"<< t.number << endl;
        return os;
    }
};

int main(){
    string *buffer = new string[BUF];
    Test* pc1 = new(buffer) Test;
    Test* pc2 = new Test("ysy",16);

    cout <<"内存块地址"<< "buffer:"<< (void*)buffer << " ysy:"<< pc2 <<endl;
    cout <<"字符串" <<endl;
    cout << *pc1 <<"地址:"<<pc1<<"\n"<<*pc2<<"地址:"<<pc2 <<endl;


    Test *pc3 = new(buffer + sizeof(Test)) Test("ysy_2",17);
    Test *pc4 = new Test("ysy_3",18);

    cout << *pc3 <<"地址:"<<pc3<<"\n"<<*pc4<<"地址:"<<pc4 <<endl;

    delete pc4;
    delete pc2;
    pc3->~Test();
    pc1->~Test();
    delete [] buffer;

    return 0;
}
