#ifndef SALES_H
#define SALES_H
#include <stdexcept>
#include <exception>
#include <string>
using namespace  std;
class sales
{
public:
    enum{MONTHS = 12};
    class bad_index : public logic_error
    {
       private:
           int bi;
       public:
           explicit bad_index(int ix,const
               std::string & s = "Index error in Sales Object\n");
           int bi_val() const {return bi;}
           virtual ~bad_index() throw() {} //不允许抛出任何异常
    };
    explicit sales(int yy = 0); //禁止隐式转换
    sales(int yy, const double * gr, int n);
    virtual ~sales() {}
    int Year() const {return year;}
    virtual double & operator[](int i);
    virtual double operator[](int i) const;

private:
    double gross[MONTHS];
    int year;
};

class LabeledSales : public sales
{
public:
    class nbad_index : public sales::bad_index
    {
    private:
        std:: string lbl;
    public:
        nbad_index(const std::string & lb, int ix,
                   const std::string & s = "Index error in LabeledSales object \n");
      const std::string & label_val() const {return lbl;}
      virtual ~nbad_index() throw() {}
    };
    explicit LabeledSales(const std::string & lb= "none", int yy = 0);
    LabeledSales(const std::string & lb, int yy, const double * gr, int n);
    virtual ~LabeledSales(){}
    const std::string & Label() const {return label;}
    virtual double operator [](int i)const;
    virtual double & operator [](int i);
private:
    std::string label;

};
#endif // SALES_H
