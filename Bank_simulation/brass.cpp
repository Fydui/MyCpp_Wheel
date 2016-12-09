#include "brass.h"
using namespace std;
ios_base::fmtflags setFormat();
void restore(ios_base::fmtflags f, streamsize p);
brass::brass(const std::string & na,long i = -1,double Nb = 0.0)
{
    Name = na;
    id = i;
    NowBalance = Nb;
}
void brass::SetDeposit(double de){
    if(de < 0) cout << "请输入正确数值" << endl;
    else NowBalance += de;
}
