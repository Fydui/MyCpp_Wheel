/*
 * ��������--�Թ�Ѱ· Ѱ�����·��
 */
#include <iostream>
using namespace std;
void dfs(int &min_ ,int temp, int x, int y, int zx, int zy, int H, int L,int map[51][51], int tag[51][51])
{
    int move[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};   //���� �� �� �� ��
    int nx = 0,ny = 0;   //��ʼ����һ����x��y����
    if(x== zx&& y==zy){  //�����ǰ��xy���յ��xyһ��
            min_  = temp;//�Ѳ�����ֵ��ȫ�ֱ���
        return;
    }
    for(int i = 0; i<4; i++){ //���� �� �� �� �� ���߿�
        nx = x+move[i][0];    //�ѵ�ǰ��������긳ֵ����һ����xy
        ny = y+move[i][1];
        if(nx<1 || nx > H || ny<1 || ny>L) continue; //�����Խ���� ������ѭ��
        if(map[nx][ny] == 0 && tag[nx][ny] == 0){    //���ûԽ�� �鿴��ǰλ���Ƿ����ϰ��ﲢ�Ҳ鿴�Ƿ����߹�
            tag[nx][ny] = 1;                         //���û���ϰ��ﲢ��û�߹� ��������
            dfs(min_,temp+1,nx,ny,zx,zy,H,L,map,tag);//����ݹ� ����������
            tag[nx][ny] = 0;                         //���Խ��� ȡ�����
        }
    }
    return;
}
int main()
{   int min_ = 99;
    int x = 0,y = 0,zx = 0, zy = 0,H = 0,L = 0;
    cout << "�������к���:";
    cin >> H >> L;
    cout << "�������ͼ:" << endl;
    int map[51][51];
    for(int a = 1; a <= H; a++)
        for(int b = 1; b <= L; b++)
            cin >> map[a][b];
    cout << "�������յ�������������:";
    cin >> x >> y >> zx >> zy;
    int tag[51][51]= {0};
    tag[x][y] = 1;
    dfs(min_,0,x,y,zx,zy,H,L,map,tag);
    cout << "\nDONE " << min_ << endl;
    return 0;
}
