#include <iostream>
using namespace std;

int main()
{
    int sum = 0, head = 0, jishu = 0;
    cout << "��������������:";
    cin >> sum;
    cout<< "\n����������:" << endl;
    string arr[sum][1];
    for(int i = 0; i<sum; i++)
        cin >> arr[i][0];

    for(int j = 0; j<sum; j++){ //�м�����ѭ������
        while(jishu < 4){       //�����������С��4 ˵��û�����
                string stemp =  arr[j][0].substr(head,3);//�ӵ�head��ʼ��ȡip�ֶ� ��ȡ��������
                int temp = std::atoi(stemp.c_str());     //�ѽ�ȡ������stringתΪint����
                if(0<=temp && temp<=225){                //�ж��ǲ���ip
                    head = head+4;                       //��head����Ų
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
