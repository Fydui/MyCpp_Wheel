#ifndef BRASSABC_H
#define BRASSABC_H
/*假设你是一个银行经理,你需要一个管理用户账户的程序,下面是你从gayhub复制过来的代码*/
#include <iostream>
#include <string>
using namespace std;
class BrassABC  //抽象基类
{
public:
    BrassABC(const string & n = "null",long an = -1,double bal = 0.0);
    virtual ~BrassABC(){}
    void Deposit(double amt);    //存款
    double Balance() const {return balance;}

    //纯虚函数 各派生类将根据需求来重定义他们 注意写法必须一样
    virtual void Withdraw(double amt) = 0;
    virtual void ViewAcct () const = 0;

private:
    string name;
    long acctNUM;
    double balance;    //结余(结算后余下的)

protected:
    struct Formatting{ //万恶的格式化输出
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const string & Name() const{return name;}
    long AcctNUM() const {return acctNUM;}
    Formatting SetFormat() const;
    void Restore(Formatting & f) const; //用于还原万恶的格式化输出

};

class Brass : public BrassABC
{
public:
    Brass(const std::string & s = "null",long an = -1, double bal = 0.0)
                                        : BrassABC(s,an,bal){}
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass(){}
};

class BrassPlus : public BrassABC
{
public:
    BrassPlus(const std::string & s = "null",long an = -1, double bal = 0.0,
                double ml = 500, double r = 0.10);
    BrassPlus(const BrassABC & b,double ml = 500,double r = 0.10);
    virtual ~BrassPlus(){}
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    void ResetMax(double m){maxLoan = m;}
    void ResetRate(double r){rate = r;}
    void ResetOwesBank(){owesBank = 0;}
private:
    double maxLoan;
    double rate;
    double owesBank;
};
#endif // BRASSABC_H
