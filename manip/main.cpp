﻿#include <iostream>
using namespace std;
int main()
{
    cout << "Enter an integer;";
    int n;
    cin >> n;

    cout << "n    n*n" <<endl;
    cout << n << "    " << n*n << "(decimal)" << endl;
    cout << hex;
    cout << n << "    ";
    cout << n*n << " (hexadecimal)" << endl;
    cout << oct << n << "    " << n * n << "(octal)" << endl;
    dec(cout);
    cout << n << "    "<< n *n << " (decimal)" << endl;

    return 0;
}
