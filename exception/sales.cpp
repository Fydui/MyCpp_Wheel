#include "sales.h"
using std::string;

sales::bad_index::bad_index(int ix, const std::__cxx11::string &s)
    :std::logic_error(s),bi(ix){ }

sales::sales(int yy){
    year = yy;
    for(int i = 0; i < MONTHS; i++)
        gross[i] = 0;
}
sales::sales(int yy, const double *gr, int n)
{
    year=yy;
    int lim = ((n < MONTHS) ? n : MONTHS);
    int i;
    for(i= 0; i < lim; i++)
        gross[i] = gr[i];
    for(;i < MONTHS; ++i)
        gross[i] = 0;
}
double sales::operator [](int i) const
{
    if(i<0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}
double & sales::operator [](int i)
{
    if(i<0 || i >= MONTHS)
        throw bad_index(i);
    return gross[i];
}
LabeledSales::nbad_index::nbad_index(const std::__cxx11::string &lb,
               int ix,const std::__cxx11::string &s) : sales::bad_index(ix,s)
{
    lbl = lb;
}

LabeledSales::LabeledSales(const std::__cxx11::string &lb, int yy) : sales(yy)
{
    label = lb;
}
LabeledSales::LabeledSales(const std::__cxx11::string &lb,
                           int yy, const double *gr, int n) : sales(yy,gr,n)
{
    label = lb;
}
double LabeledSales::operator [](int i)const
{
    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label() , i);
    return sales::operator [](i);
}
double & LabeledSales::operator [](int i)
{
    if(i < 0 || i >= MONTHS)
        throw nbad_index(Label() , i);
    return sales::operator [](i);
}

