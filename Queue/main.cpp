#include <iostream>
using namespace std;

int main()
{
    int sum,number,array[100];
    cout << "������λ��: ";
    cin >> sum;
    int head = 0,tail = sum;
    for(int i = 0; i<sum; i++){ //ѭ��������ܺ���
        cin >> number;
        array[i] = number;
    }
    while(head < tail) {
        cout << array[head];      //�����һ��
        head++;                   //�±�����Ų Ų���ڶ��� �൱��ɾ���˸ղ������
        array[tail] = array[head];//�ѵڶ���Ų��ĩβ
        tail++;                   //β������Ų ��һ�����ͷ�����
        head++;                   //head�±����Ų Ų�������� �����������´�ѭ���ĵ�һ��
    }
}
