#include <iostream>
using namespace std;

int main()
{
    int sum,number,a = 0,array[10000];
    cout << "����������: ";
    cin >> sum;
    for(int i = 0; i < 10000; i++) array[i] =0;
    for(int i = 0; i < sum; i++){
        cout << "������"<<i+1<<"�����(0~10000): ";
        cin >> number;
        array[number] = 1;
    }
    for(int j = 0; j < 10000; j++)
        if(array[j] == 1){
            cout << j << " ";
            a++;
        }
    cout << "\nһ����Ҫ��: " <<a << " ��;";
}
