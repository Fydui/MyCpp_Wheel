#include "StringBad.h"
using namespace std;
int StringBad::num_strings = 0;

StringBad::StringBad()
{
    len = 4;
    str = new char[len+1];
    strcpy(str,"C++");
    num_strings++;
    cout << "Ŀǰ��: "<<num_strings << "������" << endl;
}

StringBad::~StringBad()
{
    cout << "ɾ��: " << str << endl;
    --num_strings;
    cout << "��ǰ������"<<num_strings<<endl;
    delete [] str;
}

StringBad::StringBad(char* s)
{
    int len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
    num_strings++;
    cout << "�� "<<num_strings<<" ������:"<< str <<endl;
}

StringBad::StringBad(const StringBad &st){
    num_strings++;
    int len = st.len;
    str = new char[len+1];
    strcpy(str,st.str);
    cout <<"���ƹ��캯��������.ֵ:" << str <<endl;
}
StringBad::operator =(const StringBad &st){
    if(this == &st) return *this;
    delete str;
    len = st.len;
    str = new char[len+1];
    strcpy(str,st.str);
    return *this;
}
ostream & operator<<(ostream &os, StringBad &st)
{
    os << st.str;
    return os;
}
