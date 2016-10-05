#include <iostream>
using namespace std;

struct queue
{
    int head;
    int tail;
    int data[100];
};

int main()
{
    queue my;
    int sum,number;
    cout << "请输入位数: ";
    cin >> sum;
    my.head = 0;
    my.tail = sum;
    for(int i = 0; i<sum; i++){ //循环输入加密号码
        cin >> number;
        my.data[i] = number;
    }
    while(my.head < my.tail) {
        cout << my.data[my.head];           //输出第一位
        my.head++;                          //下标往后挪 挪到第二位 相当于删除了刚才输出的
        my.data[my.tail] = my.data[my.head];//把第二位挪到末尾
        my.tail++;                          //尾部往后挪 下一位数就放在这
        my.head++;                          //head下标继续挪 挪到第三位 第三位就是下次循环的第一位
    }
}
