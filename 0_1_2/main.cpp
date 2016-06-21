#include <iostream>
using namespace std;

float C_F(float C)
{
    float c_f =  1.8 * C + 32.00;
    return c_f;
}

float F_C(float F)
{
    float f_c =  (F - 32) / 1.8;
    return f_c;
}

int main()
{
    string L;
    float C;
    cout << "C->F enter C, F->C enter F , Q == Quit" << endl ;
    cin >> L;

    if(L == "C")
        {
        cout << "enter C" << endl;
        cin >> C;
        cout<< "F = " << C_F(C) << endl;
    }

    else if(L == "Q")
    {
        cout << "Quit" << endl;
        return 0;
    }

    else if(L == "F")
    {
        cout << "enter F" << endl;
        cin >> C;
        cout << "C = " << F_C(C) << endl;
    }

    else
        {
            cout << "Error!" << endl;
    }

}
