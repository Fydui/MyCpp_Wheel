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
        cout << words << " ���캯��������" << endl;
    }
    ~Test(){
        cout << words << " ��������������" << endl;
    }
    void show(){
        cout << words << " , ���: " << number << endl;

    }
    friend ostream & operator<<(ostream & os, Test & t){
        os << t.words<<" ���:"<< t.number << endl;
        return os;
    }
};

int main(){
    string *buffer = new string[BUF];
    Test* pc1 = new(buffer) Test;
    Test* pc2 = new Test("ysy",16);

    cout <<"�ڴ���ַ"<< "buffer:"<< (void*)buffer << " ysy:"<< pc2 <<endl;
    cout <<"�ַ���" <<endl;
    cout << *pc1 <<"��ַ:"<<pc1<<"\n"<<*pc2<<"��ַ:"<<pc2 <<endl;


    Test *pc3 = new(buffer + sizeof(Test)) Test("ysy_2",17);
    Test *pc4 = new Test("ysy_3",18);

    cout << *pc3 <<"��ַ:"<<pc3<<"\n"<<*pc4<<"��ַ:"<<pc4 <<endl;

    delete pc4;
    delete pc2;
    pc3->~Test();
    pc1->~Test();
    delete [] buffer;

    return 0;
}
