#include <iostream>
using namespace std;

int main()
{
    int temp = 63;
    cout.setf(ios_base::showpos);
    cout << "showpos: "<<temp << endl;
    cout << hex << "hex: " << temp << endl;
    cout.setf(ios_base::uppercase);
    cout.setf(ios_base::showbase);
    cout <<"uppercase & showbase: " << temp << endl;
    cout.setf(ios_base::boolalpha);
    cout << "boolalpha(true): " <<true << endl;

    return 0;
}
