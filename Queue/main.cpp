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
    cout << "������λ��: ";
    cin >> sum;
    my.head = 0;
    my.tail = sum;
    for(int i = 0; i<sum; i++){ //ѭ��������ܺ���
        cin >> number;
        my.data[i] = number;
    }
    while(my.head < my.tail) {
        cout << my.data[my.head];           //�����һλ
        my.head++;                          //�±�����Ų Ų���ڶ�λ �൱��ɾ���˸ղ������
        my.data[my.tail] = my.data[my.head];//�ѵڶ�λŲ��ĩβ
        my.tail++;                          //β������Ų ��һλ���ͷ�����
        my.head++;                          //head�±����Ų Ų������λ ����λ�����´�ѭ���ĵ�һλ
    }
}
