#ifndef STRINGPTR_H
#define STRINGPTR_H
#include <memory>
#include <iostream>
using namespace std;
class StringPtr
{
public:
    StringPtr();
    StringPtr(string sp);
    ~StringPtr();
    StringPtr & operator = (const StringPtr & sp);
    StringPtr & operator = (const string & sp);
    const StringPtr  operator+(StringPtr & st);
    friend std::ostream & operator<<(ostream & os, StringPtr & st);

private:
    shared_ptr<string> str;
};

#endif // STRINGPTR_H
