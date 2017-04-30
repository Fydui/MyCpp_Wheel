#include<iostream>

using namespace std;

int main()
{

    float p1 = 20.40;
    float p2 = 1.9 + 8.0 /9.0;

    cout << "p1:" << p1 << endl;
    cout << "p2:" << p2 << endl;

    cout.precision(2);
    cout << "p1(2): " << p1 << endl;
    cout << "p2(2):" << p2 << endl;

    return 0;
}
