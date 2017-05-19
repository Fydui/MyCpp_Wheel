#ifndef DEEP_H
#define DEEP_H
#include <iostream>
#include <string>
using namespace std;
class deep
{
public:
    deep(const string & s);
    deep(const deep & d);
    deep & operator=(const deep & d);
    friend ostream & operator << (ostream & os,deep & d);
    string* name;
private:

};

#endif // DEEP_H
