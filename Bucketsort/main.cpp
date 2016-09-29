#include <iostream>
using namespace std;
int main()
{
    /*简单桶排序实现
    满分十分 对n个同学的分数进行从大到小排序*/
    int sum = 0;
    int score = 0;
    int array[11] = {0,0,0,0,0,0,0,0,0,0,0};
    cout << "请问一共有多少人?" << endl;
    cin >> sum;
    for(int i = 0; i<sum; i++){
        std::cout << "请输入第 "<< i+1 <<" 个人的分数: ";
        cin >> score;
        array[score]++;
    }
    cout << "从大到小排序:" <<endl;
    for(int i = 10; i>=0; i--){
        for(int j = 1; j<=array[i]; j++)
            cout << i << " ";
    }
}
