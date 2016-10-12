#include <iostream>
using namespace std;

int main()
{
    int sum = 0, head = 0, jishu = 0;
    cout << "请输入数据条数:";
    cin >> sum;
    cout<< "\n请输入数据:" << endl;
    string arr[sum][1];
    for(int i = 0; i<sum; i++)
        cin >> arr[i][0];

    for(int j = 0; j<sum; j++){ //有几条就循环几次
        while(jishu < 4){       //如果计数变量小于4 说明没检查完
                string stemp =  arr[j][0].substr(head,3);//从第head开始截取ip字段 截取到后三个
                int temp = std::atoi(stemp.c_str());     //把截取出来的string转为int类型
                if(0<=temp && temp<=225){                //判断是不是ip
                    head = head+4;                       //把head往后挪
                    jishu++;
                }
                else {
                    cout << "NO" << endl;
                    break;
                }
        }
        if(jishu == 4) cout << "YES" << endl;
    }

    return 0;
}
