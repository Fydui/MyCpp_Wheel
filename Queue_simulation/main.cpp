#include "queue.h"
#include <ctime>
using namespace std;

bool newcustomer(double x){ return (rand() *x /RAND_MAX < 1);}

int main(){
    srand(time(0));
    cout << "����������������: " ;
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "������ģ���ʱ:";
    int hours;
    cin >> hours;
    long cy = 60 * hours;
    cout<< "������ģ��ʱ����ƽ����: ";
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
        cout << "ͨ���Ŀͻ�: "<< customers << endl;
        cout << "����Ŀͻ�: "<< served << endl;
        cout << "�ܿ���: " << turnaways <<endl;
        cout << "����ƽ������: ";
        cout.ios_base::precision(2);
        cout.ios_base::setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line/cy << endl;
        cout << "ƽ���ȴ�ʱ��: "
             << (double) line_wait / served << "����" << endl;
    }
    else cout << "û�пͻ�" << endl;
    cout << "���" << endl;
}
