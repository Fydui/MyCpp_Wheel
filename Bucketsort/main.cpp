#include <iostream>
using namespace std;
int main()
{
    /*��Ͱ����ʵ��
    ����ʮ�� ��n��ͬѧ�ķ������дӴ�С����*/
    int sum = 0;
    int score = 0;
    int array[11] = {0,0,0,0,0,0,0,0,0,0,0};
    cout << "����һ���ж�����?" << endl;
    cin >> sum;
    for(int i = 0; i<sum; i++){
        std::cout << "������� "<< i+1 <<" ���˵ķ���: ";
        cin >> score;
        array[score]++;
    }
    cout << "�Ӵ�С����:" <<endl;
    for(int i = 10; i>=0; i--){
        for(int j = 1; j<=array[i]; j++)
            cout << i << " ";
    }
}
