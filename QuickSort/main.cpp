#include <iostream>
#include <time.h>
using namespace std;
/*��������: ����˵,����Ҫ�����������,����Ҹ���׼��k(��ϰ���õ�һ������k),�������������ñ���� ����� �����
����Ѱ��С�ڻ�׼���� �������Ѱ�Ҵ��ڻ�׼���� ���ҽ��������� ֱ��������ڱ�������� һ��Ѱ�ҽ���,�������鱻���
���Ի�׼Ϊ���ĵ���������(�����߶���δ�����) Ȼ��ͨ���ݹ��������ͬ��������*/
void QSort(int array[], int left, int right)
{
    if(left >= right)       //�ݹ����
        return;

    int bt = 0;
    int l = left;            //��������
    int r = right;           //�����ұ��
    int middle = array[left];//���û�׼��

    while(l != r)                             //��r�����l������(����)��ʱ�����whileѭ��
    {
        while(array[r] >= middle && l<r) r--; //���ҵ��� �ұȻ�׼С�� ���array[r]���ڻ�׼ ����ǰ�ƶ�r����������array[r]
        while(array[l] <= middle && l<r) l++; //������ �ұȻ�׼��� ���array[l]С�ڻ�׼ ������ƶ�l����������array[k]
        if(l != r){                           //���l��������r ˵�������δ���� ˵��һ��������δ���
            bt = array[l];                    //���� ����������while֮�� ��ʱ��array[l]��array[r]����˳��λ�ò��Ե�
            array[l] = array[r];              //���Խ���array[l]��array[r]��λ��
            array[r] = bt;
        }
    }
    array[left] = array[l];                   //��l == rʱ (����ѭ��) ������׼������l��λ�� (��λ��׼��) ��һ���������
    array[l] = middle;                        //��һ�����������ʱ�� ��׼����ߵ�������С�ڻ�׼�� ��׼���ұߵ���������ڻ�׼�� ���������������
    QSort(array,left,l-1);                    //�ѻ�׼����ߵ���������
    QSort(array,l+1,right);                   //�ѻ�׼���ұߵ���������
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

