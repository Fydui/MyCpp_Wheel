#include "play_p.h"
#include<iostream>
#include<string>
#include<valarray>
using namespace std;
double play_p::Average() const{
    if(valarray<double>::size() > 0)
        return valarray<double>::sum()/valarray<double>::size();
    else return 0;
}
const string & play_p::Name() const{
    return (const string &)*this;
}
double & play_p::operator[](int i){
    return valarray<double>::operator[](i);
}
double play_p::operator[](int i) const
{
    return valarray<double>::operator[](i);
}
ostream & play_p::arr_out(ostream & os) const
{
    int i;
    int lim = valarray<double>::size();
    if(lim > 0)
    {
        for(i = 0; i< lim;i++)
        {
            os << valarray<double>::operator[](i) << " ";
            if( i % 5 == 4)
            os << endl;
        }
        if(i % 5 != 0) os << endl;
    }
    else os<< "empty array ";
    return os;
}
istream & operator>>(istream & is,play_p & p)
{
    is >> (string &)p;
    return is;
}
istream & getline(istream & is,play_p & p){
    getline(is,(string &)p);
    return is;
}
ostream & operator <<(ostream & os,const play_p & p){
    os << "Scores for"<<(const string &)p << ": " << endl;
    p.arr_out(os);
    return os;
}
