#include <iostream>
#include <QString>
#include <windows.h>
#include <time.h>
using namespace std;

struct figure{      //定义结构
    string name;
    int score;
};

void Name()//1.1版本 连人名带分数排序一起输出
{
    int bt = 0;
    int sum = 0;
    cout << "请问一共有多少人? ";
    cin >> sum;
    figure array[sum];
    string fname;
    for(int i= 0; i<sum; i++){
        array[i].name = "";
        array[i].score = 0;
    }

    for(int j = 0; j < sum; j++){
        cout << "请输入第"<< j+1 <<"个人的名字: ";
        cin >> fname;
        array[j].name = fname;
        cout << "请输入 " << array[j].name << " 的分数: ";
        cin >> array[j].score;
        cout << endl;
    }

    for(int a = 0; a < sum-1; a++)
        for(int k = 0; k < sum-a-1; k++)
            if(array[k].score < array[k+1].score){
                bt = array[k+1].score;
                array[k+1].score = array[k].score;
                array[k].score = bt;
            }
    cout << "从大到小排序为:" << endl;
    for(int b = 0; b < sum; b++)
        cout << array[b].name << " 的分数为: "<< array[b].score << " " << endl;
}

void test() //计算时间 10w个数 大约56s
{
    cout << "开始!" << endl;
    time_t start = 0,end = 0;
    time(&start);
    int s = 100000;
    int bt = 0;
    int array[s];
        for(int i = 0; i<s; i++){
            srand((unsigned)time(NULL));
            int md = (rand() % 1000);//产生随机整数
            array[i] = md;
        }
    for(int i = 0; i<s-1; i++)
        for(int a = 0; a <s-1; a++)
            if(array[a] < array[a+1]){
                bt = array[a];
                array[a] = array[a+1];
                array[a+1] = bt;
            }
    time(&end);
        cout << "算法运行了：" << (end-start) << "秒" << endl;

}

int main()
{
    //test();

    int bt = 0;                     //交换变量的小三
    int sum = 0;
    cout << "请问一共有多少个数? ";
    cin >> sum;
    int array[sum];             //存储数字的数组(废话

    for(int i = 0; i < sum; i++)//循环初始化数组
        array[i] = 0;
    for(int j = 0; j < sum; j++){//循环输入
            cout << "请输入第 " << j+1 << " 个数: ";
            cin >> array[j];
    }

    for(int a = 0; a < sum -1; a++)      //大循环 循环总个数-1次  (因为最后一次不需要判断 倒数第二次排序的K就是最大的) 确保所有数字都排完位
        for(int k = 0; k < sum-a-1; k++) //小循环 每次循环 从[0]开始比较[k]是否小于[k+1] 是就交换位置 将小的数往后送
            if(array[k] < array[k+1]){   //(因为小循环每次只能将一个小数归位 所以需要大循环把所有数正确归位)
                    bt = array[k];
                    array[k] = array[k+1];
                    array[k+1] = bt;
            }
    cout << "\n从大到小排序: ";
    //从小到大循环输出数组
    for(int b = 0; b < sum; b++)
        cout << " " << array[b] ;

    //Name();

}
