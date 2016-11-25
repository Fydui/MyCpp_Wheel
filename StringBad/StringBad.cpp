#include "StringBad.h"
using namespace std;
int StringBad::num_strings = 0;

StringBad::StringBad()
{
    len = 4;
    str = new char[len+1];
    strcpy(str,"C++");
    num_strings++;
    cout << "目前有: "<<num_strings << "个对象" << endl;
}

StringBad::~StringBad()
{
    cout << "删除: " << str << endl;
    --num_strings;
    cout << "当前对象数"<<num_strings<<endl;
    delete [] str;
}

StringBad::StringBad(char* s)
{
    int len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
    num_strings++;
    cout << "第 "<<num_strings<<" 个对象:"<< str <<endl;
}

ostream & operator<<(ostream &os, StringBad &st)
{
    os << st.str;
    return os;
}
