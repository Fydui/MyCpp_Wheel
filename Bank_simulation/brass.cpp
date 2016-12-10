#include "brass.h"
using namespace std;
ios_base::fmtflags setFormat(){
    return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}
void restore(ios_base::fmtflags f, streamsize p){
    cout.setf(f,std::ios_base::floatfield);
    cout.precision(p);
}

brass::brass(const string & na, long i, double Nb){
    Name = na;
    id = i;
    NowBalance = Nb;
}
brass::~brass(){}

void brass::SetDeposit(double de){
    if(de < 0) cout << "请输入正确数值" << endl;
    else NowBalance += de;
}

double brass::ShowBalance() const{ return NowBalance;}

void brass::Withdraw(double de){
    ios_base::fmtflags initialState =  setFormat();
    streamsize precis = cout.precision(2);
    if(de < 0) cout << "提款金额必须为正数\n 提款被取消" << endl;
    else if(de <= NowBalance) NowBalance -= de;
    else cout << "提款:"<< de <<"大洋" << endl;
    restore(initialState,precis);
}
void brass::ViewAcct() const {
    ios_base::fmtflags initialste = setFormat();
    streamsize prec = cout.precision(2);
    cout << "客户: "<<Name << endl;
    cout << "ID: " << id << endl;
    cout << "余额: " << NowBalance << endl;
    restore(initialste,prec);
}
brassplus::brassplus(const std::string & na,long i,double Nb,
                     double ml, double r) : brass(na,i,Nb)
{
    MaxLoan = ml;
    OwesBank = 0.0;
    Rate = r;
}

brassplus::brassplus(const brass & br,double Ml,double re) : brass(br)
{
    MaxLoan = Ml;
    OwesBank = 0.0;
    Rate = re;
}

void brassplus::ViewAcct() const{
    ios_base::fmtflags initialste = setFormat();
    streamsize prec = cout.precision(2);

    brass::ViewAcct();
    cout << "最大贷款: "<<MaxLoan << endl;
    cout << "拖欠率: " << OwesBank << endl;
    cout.precision(3);
    cout << "贷款利率: " << 100* Rate << endl;
    restore(initialste,prec);
}

void brassplus::Withdraw(double de){
    ios_base::fmtflags initialste= setFormat();
    streamsize prec = cout.precision(2);

    double b = ShowBalance();
    if(de <= b) brass::Withdraw(de);
    else if(de <= b + MaxLoan - OwesBank){
        double advance = de - b;
        OwesBank += advance * (1.0 + Rate);
        cout << "银行预付: " << advance << endl;
        cout << "财务费用: " << advance * Rate << "大洋." << endl;
        SetDeposit(advance);
        brass::Withdraw(de);
    }
    else cout << "超过信贷限额。交易取消\n";
    restore(initialste,prec);
}

