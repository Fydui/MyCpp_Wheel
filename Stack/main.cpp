#include <iostream>
#include <string.h>
using namespace std;
//简单的栈 判断用户输入是否是回文 既正着读反着读都一样的文字 例: zyzyz;
int main()
{
    int next = 0,top = 0;
    char userin[100],stack[100];
    for(int i = 0; i<100;i++) userin[i] = 0;
    for(int i = 0; i<100;i++) stack[i] = 0;
    cout << "请输入字符:";
    gets(userin);
    int len = strlen(userin);
    int min = len/2;

    for(int i = 0;i<min+1; i++) stack[top++] = userin[i];//入栈
    if(len%2 == 0) next = min-1; //如果是偶数个
    else next = min;             //如果是奇数个

    for(int j = next; j<len; j++)//处栈
        if(userin[j] == stack[top-1]) top--;//比较

    if(top == 0) cout << "YES!";
    else cout << "NO!";

    return 0;
}
