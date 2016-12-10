#ifndef BRASS_H
#define BRASS_H
#include <iostream>
class brass
{
public:
    brass(const std::string & na= "NULL",long i = -1,double Nb = 0.0);
    virtual ~brass();
    double ShowBalance() const;
    void SetDeposit(double de);
    virtual void ViewAcct() const;
    virtual void Withdraw(double de);

private:
    std::string Name;
    long id;
    double NowBalance; //当前余额
};

class brassplus : public brass
{
public:
    brassplus(const std::string & na = "NULL",long i = -1,double Nb = 0.0,
              double ml = 500, double r = 0.11125);
    brassplus(const brass & br,double Ml = 500,double re = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double de);
    void ResetMax(double m){MaxLoan = m;}
    void ResetRate(double r){Rate = r;}
    void ResetOwes(double o){OwesBank = o;}

private:
    double MaxLoan; //贷款上限
    double Rate;    //利率
    double OwesBank; //欠款
};

#endif // BRASS_H
