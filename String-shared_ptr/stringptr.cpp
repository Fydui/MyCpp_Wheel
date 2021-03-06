#include "stringptr.h"

StringPtr::StringPtr()
{
    str = make_shared<string>("C++");
    cout << *str<<" 地址为: " << str << " 无参数构造函数被调用" <<endl;
}

StringPtr::~StringPtr(){
    cout << str << " 析构函数被调用" << endl;
}

StringPtr::StringPtr(string  sp){
    str = make_shared<string>(sp);
    cout<< *str<<" 地址为: " << str<< " 构造函数被调用 " << endl;
}
StringPtr & StringPtr::operator =(const StringPtr & sp){
    str = make_shared<string>(*sp.str);
    cout << *str<<" 地址为: " << str << " StringPtr赋值函数被调用 " << endl;
    return *this;
}
StringPtr & StringPtr::operator =(const string & sp){
    str = make_shared<string>(sp);
    cout << *str<<" 地址为: " << str << " char赋值函数被调用" << endl;
    return *this;
}
