#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <valarray>
using namespace std;
class player
{
private:
    string name;
    valarray<double> source;
    ostream & arr_out(ostream & os) const;
public:
    player():name("NULL"),source(){}
    explicit player(const string & s) :name(s),source(){}
    explicit player(int n)
        :name("NULL"),source(n){}
    player(const string& na, int n)
        :name(na),source(n){}
    player(const string & na, valarray<double> & va)
        :name(na),source(va){}
    player(const char* str,const double *pd,int n)
        :name(str),source(pd,n){}
    ~player(){}
    double Average() const;
    const string & Name() const;
    double & operator[](int i);
    double operator [](int i) const;
    friend istream & operator>>(istream & is,player &pl);
    friend istream & getline(istream & is,player &pl);
    friend ostream & operator<<(ostream & os,const player &pl);


    
};

#endif // PLAYER_H
