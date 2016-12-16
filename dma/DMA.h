#ifndef DMA_H
#define DMA_H
#include<iostream>
#include<string>
using namespace std;
class DMA
{
public:
    DMA(const string & na = "null",const bool b = 0);
    DMA(const DMA & d);
    virtual ~DMA();
    DMA & operator=(const DMA & d);
    friend ostream & operator <<( ostream & os,const DMA & d);
private:
    string * name;
    bool sex;
};


class shipplus : public DMA{
public:
    shipplus(const string & na = "null",const bool b = 0,const string & ty = "CV");
    shipplus(const DMA & d,const string & ty = "CV");
    shipplus(const shipplus & sp);
    ~shipplus();
    shipplus & operator =(const shipplus & sp);
    friend ostream & operator <<(ostream & os,const shipplus & sp);
private:
    string * type;
};

class shipDMA : public DMA{
public:
    shipDMA(const string & na = "null", const bool b = 0, const int a = 18);
    shipDMA(const DMA & d,const int a = 18);
    friend ostream & operator <<(ostream & os,const shipDMA & sp);
private:
    int age;
};

#endif // DMA_H
