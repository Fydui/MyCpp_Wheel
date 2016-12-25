#ifndef PLAY_P_H
#define PLAY_P_H
#include<iostream>
#include<string>
#include<valarray>
using namespace std;
class play_p : private string,private valarray<double>
{
public:
    play_p() : string("NULL"),valarray<double>(){}
    explicit play_p(const string & s):string(s),valarray<double>(){}
    explicit play_p(int n):string("NULL"),valarray<double>(n){}
    play_p(const string & s,int n) : string(s),valarray<double>(n){}
    play_p(const string & s, valarray<double> & vd) : string(s),valarray<double>(vd){}
    play_p(const char * c,const double d, int i) : string(c),valarray<double>(d,i){}

    double Average() const;
    double & operator[](int i);
    double operator[](int i) const;
    const string & Name() const;

    friend ostream & operator<<(ostream & os,const play_p & p);
    friend istream & operator>>(istream & is,play_p & p);
    friend istream & getline(istream & is,play_p & p);
private:
    valarray<double> ArrayD;
    string name;
    ostream & arr_out(ostream & os) const;
};

#endif // PLAY_P_H
