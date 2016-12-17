#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <valarray>
using namespace std;
class player
{
public:
    player();
    explicit player(const string & s);
    explicit player(int n);
    player(const string& na, int n);
    player(const string & na, valarray<double> & va);
    player(const char* str,const double *pd,int n);
    ~player();
    double Average() const;
    const string & Name() const;
    double & operator[](int i) const;
    double operator [](int i);
    friend istream& operator>>(istream & is,player &pl);
    friend istream & gitline(istream & is,player &pl);
    friend ostream & operator<<(ostream & os,const player &pl);
private:
    valarray<double> source;
    string name;
    ostream & arr_out(ostream & os);
};

#endif // PLAYER_H
