#ifndef BRASS_H
#define BRASS_H
#include <iostream>

class brass
{
public:
    brass(const std::string & na,long i = -1,double Nb = 0.0);
    virtual ~brass(){}
    double ShowBalance() const;
    void SetDeposit(double de);
    virtual void ViewAcct() const;
    virtual void withdraw(double de);

private:
    std::string Name;
    long id;
    double NowBalance; //当前余额
};

class brassplus : public brass
{
public:
    brassplus(double Ml= 500, double re = 0.11125, double ob = 0.0,
              const std::string & na,long id = -1, double Nb = 0.0);
    brassplus(const brass & br,double Ml = 500,double re = 0.11125,double ob = 0.0);
    virtual void ViewAcct() const;
    virtual void withdraw(double de);
    void ResetMax(double m){MaxLoan = m;}
    void ResetRate(double r){rate = r;}
    void ResetOwes(double o){owesBank = 0.0;}

private:
    double MaxLoan; //贷款上限
    double rate;    //利率
    double owesBank; //欠款
}

#endif // BRASS_H
