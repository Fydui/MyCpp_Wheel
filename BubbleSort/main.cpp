#include <iostream>
#include <QString>
using namespace std;

struct figure{      //����ṹ
    string name;
    int score;
};

void Name()//1.1�汾 ����������������һ�����
{
    int bt = 0;
    int sum = 0;
    cout << "����һ���ж�����? ";
    cin >> sum;
    figure array[sum];
    string fname;
    for(int i= 0; i<sum; i++){
        array[i].name = "";
        array[i].score = 0;
    }

    for(int j = 0; j < sum; j++){
        cout << "�������"<< j+1 <<"���˵�����: ";
        cin >> fname;
        array[j].name = fname;
        cout << "������ " << array[j].name << " �ķ���: ";
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
    cout << "�Ӵ�С����Ϊ:" << endl;
    for(int b = 0; b < sum; b++)
        cout << array[b].name << " �ķ���Ϊ: "<< array[b].score << " " << endl;
}

int main()
{
    /*
    int bt = 0;                     //����������С��
    int sum = 0;
    cout << "����һ���ж��ٸ���? ";
    cin >> sum;
    int array[sum];             //�洢���ֵ�����(�ϻ�

    for(int i = 0; i < sum; i++)//ѭ����ʼ������
        array[i] = 0;
    for(int j = 0; j < sum; j++){//ѭ������
            cout << "������� " << j+1 << " ����: ";
            cin >> array[j];
    }

    for(int a = 0; a < sum -1; a++)  //��ѭ�� ѭ���ܸ���-1��  (��Ϊ���һ�β���Ҫ�ж� �����ڶ��������K��������) ȷ���������ֶ�����λ
        for(int k = 0; k < sum-a-1; k++) //Сѭ�� ÿ��ѭ�� ��[0]��ʼ�Ƚ�[k]�Ƿ�С��[k+1] �Ǿͽ���λ�� ��С����������
            if(array[k] < array[k+1]){//(��ΪСѭ��ÿ��ֻ�ܽ�һ��С����λ ������Ҫ��ѭ������������ȷ��λ)
                    bt = array[k];
                    array[k] = array[k+1];
                    array[k+1] = bt;
            }

    cout << "�Ӵ�С����: ";
    //��С����ѭ���������
    for(int b = 0; b < sum; b++)
        cout << " " << array[b] ;
        */
    Name();

}
