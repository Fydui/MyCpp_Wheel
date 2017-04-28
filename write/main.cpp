#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const char * s1 = "Florida";
    const char * s2 = "Kansas";
    const char * s3 = "Euphoria";

    int len = strlen(s2);
    cout << "Increasing LOOP" << endl;

    int i;
    for(i = 1; i <= len; i++)
    {
        cout.write(s2,i);
        cout <<endl;
    }
    cout << "Decreasing LOOP:";
    for(i = len; i > 0; i--)
    cout.write(s2,i) << endl;
    cout << "Exceeding string length: " << endl;
    cout.write(s2,len+5) << endl;

    return 0;
}
