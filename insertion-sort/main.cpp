#include<iostream>
using namespace std;

int main()
{
    int A[10] = {2,68,21,0,58,6,7,9,745,4};
    for(int i = 1; i < 10; i++ )
    {
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key )
        {
            A[j+1] = A[j];
            j = j -1;
        }
        A[j+1] = key;
    }
    
    for(int k = 0 ; k < 10; k++)
    cout << A[k] << " ";
    
    return 0;
}
