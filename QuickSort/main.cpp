#include <iostream>
#include <time.h>
using namespace std;
void QSort(int array[], int left, int right)
{
    if(left >= right)       //�ݹ����
        return;

    int bt = 0;
    int l = left;
    int r = right;
    int middle = array[left];//���û�׼��

    while(l != r)            //��r�����l������(����)��ʱ�����whileѭ��
    {
        while(array[r] >= middle && l<r) r--; //���ҵ��� �ұȻ�׼��� �ƶ�r���
        while(array[l] <= middle && l<r) l++; //�������� �ұȻ�׼С�� �ƶ�l���
        if(l < r){                            //���lС��r �򽻻�l��r��λ��
            bt = array[l];
            array[l] = array[r];
            array[r] = bt;
        }
    }
    array[left] = array[l]; //��l == rʱ (����ѭ��) ������׼���ڱ��(l/r)��λ�� ��Ϊ��׼�� ��һ���������
    array[l] = middle;      //��һ�����������ʱ�� ��׼����ߵ�������С�ڻ�׼�� ��׼���ұߵ���������ڻ�׼��
    QSort(array,left,l-1);  //�ѻ�׼����ߵ���������
    QSort(array,l+1,right); //�ѻ�׼���ұߵ���������
    //����һ���ݹ�Ĺ��� һֱ�����в�ֳ����� ֱ�����ɲ��
}

void test()
{
    cout << "��ʼ!" << endl;
    clock_t start_time=clock();
    int sum = 10000;
    int tes[sum];
    for(int i = 0; i<sum; i++){
        srand((unsigned)time(NULL));
        int md = (rand() % 1000);//�����������
        tes[i] = md;
    }
        QSort(tes,0,sum);
        clock_t end_time=clock();
        cout<< "Running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
}

int main()
{
    int sum = 0;
    cout << "����һ���ж�����?";
    cin >> sum;
    int array[sum];
    for(int i =0; i < sum; i++){
        cout << "\n������� " << i+1 << "����: ";
        cin >> array[i];
    }
    QSort(array,0,sum);
    for(int i = 0; i < sum; i++)
        cout << array[i] << " ";
    return 0;
}

