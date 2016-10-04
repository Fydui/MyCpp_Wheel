#include <iostream>
using namespace std;

int main()
{
    int sum,number,array[100];
    cout << "请输入位数: ";
    cin >> sum;
    int head = 0,tail = sum;
    for(int i = 0; i<sum; i++){ //循环输入加密号码
        cin >> number;
        array[i] = number;
    }
    while(head < tail) {
        cout << array[head];      //输出第一个
        head++;                   //下标往后挪 挪到第二个 相当于删除了刚才输出的
        array[tail] = array[head];//把第二个挪到末尾
        tail++;                   //尾部往后挪 下一个数就放在这
        head++;                   //head下标继续挪 挪到第三个 第三个就是下次循环的第一个
    }
}
