#include "queue.h"
#include <ctime>
using namespace std;

bool newcustomer(double x){ return (rand() *x /RAND_MAX < 1);}

int main(){
    srand(time(0));
    cout << "请输入队列最大容量: " ;
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "请输入模拟的时:";
    int hours;
    cin >> hours;
    long cy = 60 * hours;
    cout<< "请输入模拟时长的平均数: ";
    double perhour;
    cin >> perhour;
    double min_cust;
    min_cust = 60/perhour;

    Customer temp;
    long turnaways = 0,
         customers = 0,
         served = 0,
         sum_line = 0,
         line_wait= 0;
    int wait_time = 0;

    for(int cycle = 0; cycle<cy; cycle++)
        {
            if(newcustomer(min_cust))
            {
                if(line.isfull()) turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);
                    line.enqueue(temp);
                }
            }
            if(wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.prime();
                line_wait += cycle - temp.when();
                served--;
            }
            if(wait_time > 0) wait_time--;
            sum_line += line.queuecount();
    }

    if(customers > 0)
    {
        cout << "通过的客户: "<< customers << endl;
        cout << "保存的客户: "<< served << endl;
        cout << "避开的: " << turnaways <<endl;
        cout << "队列平均长度: ";
        cout.ios_base::precision(2);
        cout.ios_base::setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line/cy << endl;
        cout << "平均等待时间: "
             << (double) line_wait / served << "分钟" << endl;
    }
    else cout << "没有客户" << endl;
    cout << "完成" << endl;
}
