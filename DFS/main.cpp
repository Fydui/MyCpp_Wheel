#include <iostream>
using namespace std;
/*
 * 简单深度优先搜索--数字全排列
 * 123的全排列有:123 132 213 231 312 321
 * 现求1~n的全排列
 */
void dfs(int box[],int book[],int step,int n)
{
    if(step == n+1){    //如果step等于n+1 说明前面n个盒子已经摆放好等输出了
        for(int j = 1; j<=n; j++) cout << box[j];//输出一组
        cout<< endl;
        return;
    }
    for(int i = 1; i<=n; i++){
        if(book[i] == 0){ //如果当前的数没被标记过
            box[step] = i;//把当前的数存到一个盒子里
            book[i] = 1;  //存过的数用另一个数组标记一下
            dfs(box,book,step+1,n);//递归
            book[i] = 0;  //把标记抹除 收回当前的数
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
