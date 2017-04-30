#include <iostream>
using namespace std;
int main()
{
    float p1 = 12.40;
    float p2 = 1.9+8.0/9.0;

    cout.setf(ios_base::showpoint);
    cout << "p1:" << p1 << endl;
    cout << "p2:" << p2 << endl;

    cout.precision(2);
    cout << "(2)p1:" << p1 << endl;
    cout << "(2)p2:" << p2 << endl;

    return 0;
}

