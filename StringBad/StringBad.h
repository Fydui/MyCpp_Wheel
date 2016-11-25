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
    friend std::ostream & operator<<(std::ostream &os, StringBad &st);

private:
    char* str;
    int len;
    static int num_strings;
};

#endif // STRINGBAD_H
