#include <iostream>
using namespace std;
struct note{ //���нṹ
    int x = 0;
    int y = 0;
    int s = 0; //����
};

int main(){
    struct note que[2500]; //��ͼ
    int a[50][50] = {0};
    bool book[50][50] = {false}; //������ڼ�鵱ǰ�ĸ����Ƿ��߹�
    int next[4][2] = {      //���ڼ����Χ���� ˳ʱ��
        {1,0}, //������
        {0,1}, //������
        {-1,0},//������
        {0,-1} //������
    };
    int c[5][4] = {
    {0,0,1,0},
    {0,0,0,0},
    {0,0,1,0},
    {0,1,0,1},
    {0,0,0,1},
    };
    cout << c[3][3];
    int startx = 0, starty = 0; //��ʼ����
    int mx = 0, my = 0;         //Ŀ������
    int m = 0,n =0;             //��ͼ����
    cout << "�������ͼ����:" << endl;
    cin >> m >>n;
    cout << "�������ͼ(1��ʾ���ϰ�,0��ʾ���ϰ�)" << endl;
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n;j++)
            cin >> a[i][j];
    cout << "��������ʼ������Ŀ������ "<< a[2][2] <<endl;
    cin >> startx >> starty >> mx >> my;

    //��ʼ������
    int head = 0, tail = 0;
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].s = 0;
    tail++;
    book[tail][tail] = 1;

    bool flag = 0; //���ڱ���Ƿ�ﵽĿ���
    while(head<tail){
        for(int k = 0; k<4; k++){
            int nx = que[head].x + next[k][0];
            int ny = que[head].y + next[k][1];
                    //����Ƿ�Խ��
            if(nx<0 || nx>n || ny<0 || ny>m)
                continue;
                    //����Ƿ������ϰ�
            if(a[ny][nx] == 0 && book[ny][nx] == false){
                book[ny][nx] = true; //����Ѿ��߹�
                que[tail].x = nx;
                que[tail].y = ny;
                que[tail].s = que[head].s + 1;//������ǰ���+1
                tail++;
            }
            if(nx == mx && ny == my){         //�������Ŀ���
                flag = 1;
                break;
            }
        }
        if(flag == 1)
            break;
        head++;
    }
    cout << que[tail-1].s<<endl;
    return 0;
}
