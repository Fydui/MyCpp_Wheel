#ifndef TMIME_H
#define TMIME_H
#include <iostream>
using namespace std;

class TIME {
friend TIME operator *(double t, const TIME& T); //友元
friend ostream & operator<<(ostream &os ,TIME &time);

private:
    int hour;
    int min;
public:
    TIME();
    TIME(int hour, int min);
    void addHour(int hour);
    void addMin(int min);

    //运算符重载
    TIME operator *(double t);
    TIME operator+(const TIME& t);
    TIME operator-(const TIME& t);

    //转换函数
    operator int();
    operator double();

    //
    void show();

};


#endif // TMIME_H
