#ifndef STRINGBAD_H
#define STRINGBAD_H
#include <iostream>
#include <cstring>
#include <ostream>
class StringBad
{
public:
    StringBad();
    ~StringBad();
    StringBad(char* s);
    StringBad(const char* s);
    StringBad(const StringBad &st);      //复制构造函数
    StringBad & operator=(const StringBad &st);//赋值运算符
    StringBad & operator=(const char *st);

    friend std::ostream & operator<<(std::ostream &os, StringBad &st);
    friend std::istream & operator >>(std::istream &is,StringBad &st);
    friend bool operator<(const StringBad &st,const StringBad &st2);
    friend bool operator>(const StringBad &st,const StringBad &st2);
    friend bool operator==(const StringBad &st,const StringBad &st2);

    char & operator[](int i);
    const char & operator [](int i) const;

    static int HowMany(){return num_strings;}

private:
    char* str;
    int len;
    static int num_strings;
};

#endif // STRINGBAD_H
