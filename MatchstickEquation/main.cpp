#include<iostream>
using namespace std;
/*
 * 火柴棍等式计算:
 * 用火柴棍摆等式一共24根火柴摆出A+B+C的形式 所有火柴必须都用上 等号与加号需要四个火柴
 * 求一共多少种摆法
 * 注:0 1 2 3 4 5 6 7 8 9 每个数字各需 6 2 5 5 4 5 6 3 7 6 根火柴
 */

int fun(int x)//计算单个数所需火柴棍数量
{
    int sum = 0,matchstick[10]{6,2,5,5,4,5,6,3,7,6};//初始化每个数所需要的火柴 存个数组里
    while(x/10 != 0){                               //如果输入的除10不得0 说明x肯定至少有两位
        sum += matchstick[x%10];                    //取其末位所需火柴棍数
        x = x/10;                                   //去其末位
    }
    sum += matchstick[x];                           //x所需要的火柴棍总数
    return sum;
}

int main()
{
    int C = 0,m = 0,sum = 0;
    cout << "请输入火柴棍数:";
    cin >> m;
    for(int a = 0; a < 1111; a++)    //因为去掉符号就剩20根 最少的1需要两根 20根最多组成10个1
        for(int b = 0; b < 1111; b++)//所以A+B=C中任意一个都不能大于1111
        {
            C = a+b;                 //算出C是几
            if(fun(a) + fun(b) + fun(C) == m-4){ //如果A+B+C一共所需的等于总数减去符号的 那么这算一个解
                cout << a << "+" << b << "=" << a+b << endl;
                sum++;//变量存储有多少个解
            }
        }
    cout << "一共有:" << sum << "种拼法" << endl;
    return 0;
}
