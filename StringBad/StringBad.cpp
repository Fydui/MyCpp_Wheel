#include "StringBad.h"
using namespace std;
int StringBad::num_strings = 0;

StringBad::StringBad()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
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

StringBad::StringBad(const char* s){
    len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
    num_strings++;
}

StringBad::StringBad(const StringBad &st){
    num_strings++;
    int len = st.len;
    str = new char[len+1];
    strcpy(str,st.str);
    cout <<"复制构造函数被调用.值:" << str <<endl;
}
StringBad & StringBad::operator =(const StringBad &st){
    if(this == &st) return *this;
    delete [] str;
    len = st.len;
    str = new char[len+1];
    strcpy(str,st.str);
    return *this;
}

StringBad & StringBad::operator =(const char* st){
    delete [] str;
    len = strlen(st);
    str = new char[len+1];
    strcpy(str,st);
    return *this;
}
ostream & operator<<(ostream &os, StringBad &st)
{
    os << st.str;
    return os;
}

bool operator<(const StringBad &st,const StringBad &st2){
    if(strcmp(st.str,st2.str) < 0) return true;
    else return false;
}

bool operator>(const StringBad &st,const StringBad &st2){
    return st2 < st;
}

bool operator==(const StringBad &st,const StringBad &st2){
    if(strcmp(st.str,st2.str) == 0) return true;
    else return false;
}
istream & operator>>(istream &is, StringBad &st){
    is >> st.str;
    return is;
}
char & StringBad::operator [](int i){
    return str[i];
}
const char & StringBad::operator [](int i) const{
    return str[i];
}

