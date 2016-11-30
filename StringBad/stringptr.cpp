#include "stringptr.h"

StringPtr::StringPtr()
{
    str = make_shared<string>("C++");
    cout << *str<<" ��ַΪ: " << str << " �޲������캯��������" <<endl;
}

StringPtr::~StringPtr(){
    cout <<" " <<str << " ��������������" << endl;
}

StringPtr::StringPtr(string  sp){
    str = make_shared<string>(sp);
    cout<< *str<<" ��ַΪ: " << str<< " ���캯�������� " << endl;
}
StringPtr & StringPtr::operator =(const StringPtr & sp){
    str = make_shared<string>(*sp.str);
    cout << *str<<" ��ַΪ: " << str << " StringPtr��ֵ���������� " << endl;
    return *this;
}
StringPtr & StringPtr::operator =(const string & sp){
    str = make_shared<string>(sp);
    cout << *str<<" ��ַΪ: " << str << " char��ֵ����������" << endl;
    return *this;
}
const StringPtr  StringPtr::operator+( StringPtr &st){
    //StringPtr temp;
    this->str = make_shared<string>( *this->str + *st.str);
    cout << "operator+������" << endl;
    return *this;
}
ostream & operator <<(ostream & os, StringPtr &st){
    os << *st.str << " operator<<������" << endl;
    return os;
}
