#include <iostream>
#include <string.h>
using namespace std;
//�򵥵�ջ �ж��û������Ƿ��ǻ��� �����Ŷ����Ŷ���һ�������� ��: zyzyz;
int main()
{
    int next = 0,top = 0;
    char userin[100],stack[100];
    for(int i = 0; i<100;i++) userin[i] = 0;
    for(int i = 0; i<100;i++) stack[i] = 0;
    cout << "�������ַ�:";
    gets(userin);
    int len = strlen(userin);
    int min = len/2;

    for(int i = 0;i<min+1; i++) stack[top++] = userin[i];//��ջ
    if(len%2 == 0) next = min-1; //�����ż����
    else next = min;             //�����������

    for(int j = next; j<len; j++)//��ջ
        if(userin[j] == stack[top-1]) top--;//�Ƚ�

    if(top == 0) cout << "YES!";
    else cout << "NO!";

    return 0;
}
