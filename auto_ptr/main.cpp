#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Report
{
private:
    string str;
public:
    Report(const string s) : str(s)
    {cout << "Objectt created:" << endl;}
    ~Report() {cout << "Object deleted" << endl;}
    void comment() const {cout << str << endl;}
};
int main()
{
    {
        auto_ptr<Report> ps(new Report("auto_ptr"));
        ps->comment();
    }
    {
        shared_ptr<Report> ps(new Report("shared_ptr"));
        ps->comment();
    }
    {
        unique_ptr<Report> ps(new Report("unique_ptr"));
        ps->comment();
    }
    return 0;
}
