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

void dfs2(bool book[] ,int step, int a[])
{
    if(step == 10){
        if(a[1]*100+a[2]*10+a[3] + a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9]){
            cout << a[1] << a[2] << a[3]
                    << "+" << a[4] << a[5] << a[6]
                                        << " = " << a[7] << a[8] << a[9] << endl;
                    jishu++;
        }
            return;
    }
    for(int i = 1; i <=9; i++){
        if(book[i] == false){
            a[step] = i;
            book[i] = true;
            dfs2(book,step+1,a);
            book[i] = false;
        }
    }
    return;
}


int main()
{
    bool book[1000];
    int num[1000],arr[10];
    for(int c = 1; c<=9; c++) arr[c] = 0;
    for(int a = 0; a<1001; a++) book[a] = false;
    for(int b = 0; b<1000; b++) num[b] = 0;
    int n = 0;
    //cin >> n;
    dfs2(book,1,arr);
    cout <<"+:"<<jishu<<"\nDONE";
    return 0;
}
