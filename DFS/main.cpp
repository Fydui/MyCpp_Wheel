#include <iostream>
using namespace std;
/*
 * �������������--����ȫ����
 * 123��ȫ������:123 132 213 231 312 321
 * ����1~n��ȫ����
 */
void dfs(int box[],int book[],int step,int n)
{
    if(step == n+1){    //���step����n+1 ˵��ǰ��n�������Ѿ��ڷźõ������
        for(int j = 1; j<=n; j++) cout << box[j];//���һ��
        cout<< endl;
        return;
    }
    for(int i = 1; i<=n; i++){
        if(book[i] == 0){ //�����ǰ����û����ǹ�
            box[step] = i;//�ѵ�ǰ�����浽һ��������
            book[i] = 1;  //�����������һ��������һ��
            dfs(box,book,step+1,n);//�ݹ�
            book[i] = 0;  //�ѱ��Ĩ�� �ջص�ǰ����
        }
    }
     return;
}

int main()
{
    int book[1000],num[1000];
    for(int a = 0; a<1001; a++) book[a] = 0;
    for(int b = 0; b<1001; b++) num[b] = 0;
    int n = 0;
    cin >> n;
    dfs(num,book,1,n);
    return 0;
}
