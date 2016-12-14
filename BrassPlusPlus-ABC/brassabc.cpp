#include "brassabc.h"
#include <iostream>
#include <string>
using namespace std;

BrassABC::BrassABC(const string & n,long an, double bal )
{
    name = n;
    acctNUM = an;
    balance = bal;
}

void BrassABC::Deposit(double amt){
    if(amt < 0)  cout << "请输入正确数值" << endl;
    else balance += amt;
}

void BrassABC::Withdraw(double amt){
    balance -= amt;
}

BrassABC::Formatting BrassABC::SetFormat() const{
    Formatting f;
    f.flag =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}
void BrassABC::Restore(Formatting &f) const
{
    cout.setf(f.flag,ios_base::floatfield);
    cout.precision(f.pr);
}
void Brass::Withdraw(double amt){
    if(amt < 0)
        cout << "提款金额必须为正数\n 提款被取消" << endl;
    else if(amt <= Balance())
        BrassABC::Withdraw(amt);
    else
        cout << "提款:"<< amt <<"大洋" << endl;
}
void::Brass::ViewAcct() const{
    Formatting f = SetFormat();
    cout << "客户: "<< Name() << endl;
    cout << "ID: " << AcctNUM() << endl;
    cout << "余额: " << Balance() << endl;
    Restore(f);
}
BrassPlus::BrassPlus(const std::string & s,long an, double bal,
                     double ml, double r) : BrassABC(s,an,bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}
void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "你の名字: " << Name() << endl;
    cout << "ID: " << AcctNUM() << endl;
    cout << "最大贷款: " << maxLoan << endl;
    cout << "欠款: " << owesBank << endl;
    cout.precision(3);
    Restore(f);
}
void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();
    double bal =Balance();
    if(amt < bal)
        BrassABC::Withdraw(amt);
    else if(amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank +=advance*(1.0+rate);
        cout << "银行预付款: " << advance <<endl;
        cout << "财务费用: " << advance*rate << endl;
        Deposit(advance);
        BrassABC::Withdraw(amt);
    }
    else
        cout << "信用限额已超过。交易已取消." << endl;
    Restore(f);
}
