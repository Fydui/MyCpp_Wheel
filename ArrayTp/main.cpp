#include "arraytp.h"
using namespace std;
int main()
{
    ArrayTp<int,10> sum;
    ArrayTp<double,10> aves;
    ArrayTp<ArrayTp<int,5>,10> douarr;

    int i,j;
    for(i = 0; i < 10; i++)
    {
        sum[i] = 0;
        for(j = 0; j < 5; j++){
            douarr[i][j] = (i+1)*(j+1);
            sum[i] += douarr[i][j];
        }
        aves[i] = (double)sum[i] / 10;
    }
    for(i = 0; j < 10; i++)
    {
        for(j = 0; j < 5; j++)
        {
            cout.width(2);
            cout << douarr[i][j] << " ";
        }
        cout << ":sum = ";
        cout.width(3);
        cout << sum[i] << ", average = " << aves[i] << endl;
    }
    cout << "DONE" << endl;
}

