#include <iostream>
using namespace std;

void dms(int d, int m, int s)
{
    const double K = 60.00;
    double result = (m/K)+((s/K)/K)+d;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    cout << d << " degrees, " << m << " minutes,"
         << s << " seconds = " << result << " derees. " << endl;
}

int main()
{
    int d,m,s;
    cout << "enter a latitude in dergees,mintues, and seconds: " << endl;
    cout << "First enter the degrees:";
    cin >> d;
    cout << "enter the minutes of arc:";
    cin >> m;
    cout << "enter the senconds of arc:";
    cin >> s;
    dms(d,m,s);

    return 0;
}
