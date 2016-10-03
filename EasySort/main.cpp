#include <iostream>
using namespace std;

int main()
{
    int sum,number,a = 0,array[10000];
    cout << "请输入人数: ";
    cin >> sum;
    for(int i = 0; i < 10000; i++) array[i] =0;
    for(int i = 0; i < sum; i++){
        cout << "请输入"<<i+1<<"个编号(0~10000): ";
        cin >> number;
        array[number] = 1;
    }
    for(int j = 0; j < 10000; j++)
        if(array[j] == 1){
            cout << j << " ";
            a++;
        }
    cout << "\n一共需要买: " <<a << " 本;";
}
