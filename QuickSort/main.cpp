#include <iostream>
#include <time.h>
using namespace std;
/*快速排序: 简单来说,在需要排序的数组中,随便找个基准数k(我习惯用第一个数当k),在数组两端设置标记左 标记右 标记右
负责寻找小于基准数的 标记左负责寻找大于基准数的 并且交换这俩数 直到标记左于标记右相遇 一轮寻找结束,于是数组被拆分
成以基准为中心的左右两边(这两边都是未排序的) 然后通过递归给两边相同方法排序*/
void QSort(int array[], int left, int right)
{
    if(left >= right)       //递归结束
        return;

    int bt = 0;
    int l = left;            //设置左标记
    int r = right;           //设置右标记
    int middle = array[left];//设置基准数

    while(l != r)                             //当r标记与l标记相等(相遇)的时候结束while循环
    {
        while(array[r] >= middle && l<r) r--; //从右到左 找比基准小的 如果array[r]大于基准 就向前移动r标记跳过这个array[r]
        while(array[l] <= middle && l<r) l++; //从左到右 找比基准大的 如果array[l]小于基准 就向后移动l标记跳过这个array[k]
        if(l != r){                           //如果l不等于于r 说明标记尚未相遇 说明一轮排序尚未完成
            bt = array[l];                    //所以 当经过两次while之后 此时的array[l]与array[r]正是顺序位置不对的
            array[l] = array[r];              //所以交换array[l]与array[r]的位置
            array[r] = bt;
        }
    }
    array[left] = array[l];                   //当l == r时 (结束循环) 交换基准数与标记l的位置 (归位基准数) 第一轮排序结束
    array[l] = middle;                        //第一轮排序结束的时候 基准数左边的数都会小于基准数 基准数右边的数都会大于基准数 但他俩都是无序的
    QSort(array,left,l-1);                    //把基准数左边的数列排序
    QSort(array,l+1,right);                   //把基准数右边的数列排序
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

