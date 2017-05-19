#include "deep.h"

deep::deep(const string & s)
{
     name = new string[sizeof(s)+1];
     *name = s;
}

deep::deep(const deep & d){

    delete name;
    name = new string;
    name = d.name;

}
deep & deep::operator=(const deep & d){
    if(this == &d) return *this;
    delete name;
    name = new string;
    name = d.name;
    return *this;
}
ostream & operator << (ostream & os,deep & d)
{
    os << *d.name;
    return os;
}
