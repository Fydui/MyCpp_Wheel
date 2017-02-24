#ifndef EXC_MEAN_H
#define EXC_MEAN_H
#include <iostream>
class bad_hmean
{
private:
    double a1;
    double a2;
public:
    bad_hmean(double a = 0, double b = 0) : a1(a),a2(b){}
    void mesg();
};
inline void bad_hmean::mesg(){

    std::cout << "hmean("<<a1 << "," << a2 << ") : a == -b" << std::endl;
}
class bad_gmean
{
    public:
    double v1;
    double v2;
    bad_gmean(double a = 0, double b = 0):v1(a),v2(b){}
    const char * mesg();
};
inline const char * bad_gmean::mesg(){
    return "gmean() >= 0";
}
#endif // EXC_MEAN_H
