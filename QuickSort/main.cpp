#include <iostream>
#include <time.h>
using namespace std;
void QSort(int array[], int left, int right)
{
    if(left >= right)       //递归结束
        return;

    int bt = 0;
    int l = left;
    int r = right;
    int middle = array[left];//设置基准数

    while(l != r)            //当r标记与l标记相等(相遇)的时候结束while循环
    {
        while(array[r] >= middle && l<r) r--; //从右到左 找比基准大的 移动r标记
        while(array[l] <= middle && l<r) l++; //从做导游 找比基准小的 移动l标记
        if(l < r){                            //如果l小于r 则交换l与r的位置
            bt = array[l];
            array[l] = array[r];
            array[r] = bt;
        }
    }
    array[left] = array[l]; //当l == r时 (结束循环) 交换基准数于标记(l/r)的位置 归为基准数 第一轮排序结束
    array[l] = middle;      //第一轮排序结束的时候 基准数左边的数都会小于基准数 基准数右边的数都会大于基准数
    QSort(array,left,l-1);  //把基准数左边的数列排序
    QSort(array,l+1,right); //把基准数右边的数列排序
    //这是一个递归的过程 一直把数列拆分成两份 直到不可拆分
}

void test()
{
    cout << "开始!" << endl;
    clock_t start_time=clock();
    int sum = 10000;
    int tes[sum];
    for(int i = 0; i<sum; i++){
        srand((unsigned)time(NULL));
        int md = (rand() % 1000);//产生随机整数
        tes[i] = md;
    }
        QSort(tes,0,sum);
        clock_t end_time=clock();
        cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
}

int main()
{
    int sum = 0;
    cout << "请问一共有多少数?";
    cin >> sum;
    int array[sum];
    for(int i =0; i < sum; i++){
        cout << "\n请输入第 " << i+1 << "个数: ";
        cin >> array[i];
    }
    QSort(array,0,sum);
    for(int i = 0; i < sum; i++)
        cout << array[i] << " ";
    return 0;
}

