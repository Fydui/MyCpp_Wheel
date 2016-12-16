#include "DMA.h"

DMA::DMA(const string &na, const bool b)
{
    name = new string;
    *name = na;
    sex = b;
}
DMA & DMA::operator =(const DMA & d){
    if(&d == this) return *this;
    delete name;
    name = new string;
    name = d.name;
    sex= d.sex;
    return *this;
}
DMA::DMA(const DMA & d){
    name = new string;
    name = d.name;
    sex = d.sex;
}
DMA::~DMA(){delete name;}
ostream & operator <<( ostream & os,const DMA & d){
    os << "name:" <<*d.name<<" sex:" << d.sex;
    return os;
}

shipDMA::shipDMA(const string &na, const bool b, const int a):DMA(na,b)
{
  age = a;   
}
shipDMA::shipDMA(const DMA &d, const int a):DMA(d){
    age = a;
}
ostream & operator<<(ostream & os,const shipDMA & sp){
    os << (const DMA &) sp << " age:"<<sp.age;
    return os;
}
shipplus::shipplus(const DMA &d, const string &ty) : DMA(d){
    type = new string;
    *type = ty; 
}

shipplus::shipplus(const shipplus &sp) : DMA(sp){
    type = new string;
    type = sp.type;
}
shipplus::shipplus(const string &na, const bool b, const string &ty): DMA(na,b)
{
    type = new string;
    *type = ty;
}
shipplus::~shipplus(){delete type;}
shipplus & shipplus::operator =(const shipplus& sp){
    if(&sp == this) return *this;
    delete type;
    type = new string;
    type = sp.type;
    DMA::operator =(sp);
    return *this;
}
ostream & operator <<(ostream & os, const shipplus & sp){
    os << (const DMA &) sp << " type:" << *sp.type;
    return os;
}
