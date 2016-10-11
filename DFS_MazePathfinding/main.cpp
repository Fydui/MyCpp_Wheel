/*
 * 深搜轮子--迷宫寻路 寻找最短路径
 */
#include <iostream>
using namespace std;
void dfs(int &min_ ,int temp, int x, int y, int zx, int zy, int H, int L,int map[51][51], int tag[51][51])
{
    int move[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};   //向右 下 左 上 走
    int nx = 0,ny = 0;   //初始化下一步的x跟y坐标
    if(x== zx&& y==zy){  //如果当前的xy跟终点的xy一样
            min_  = temp;//把步数赋值给全局变量
        return;
    }
    for(int i = 0; i<4; i++){ //按照 右 下 左 上 走走看
        nx = x+move[i][0];    //把当前走完的坐标赋值给下一步的xy
        ny = y+move[i][1];
        if(nx<1 || nx > H || ny<1 || ny>L) continue; //如果走越界了 就跳出循环
        if(map[nx][ny] == 0 && tag[nx][ny] == 0){    //如果没越界 查看当前位置是否有障碍物并且查看是否曾走过
            tag[nx][ny] = 1;                         //如果没有障碍物并且没走过 标记这个点
            dfs(min_,temp+1,nx,ny,zx,zy,H,L,map,tag);//进入递归 尝试往下找
            tag[nx][ny] = 0;                         //尝试结束 取消标记
        }
    }
    return;
}
int main()
{   int min_ = 99;
    int x = 0,y = 0,zx = 0, zy = 0,H = 0,L = 0;
    cout << "请输入行和列:";
    cin >> H >> L;
    cout << "请输入地图:" << endl;
    int map[51][51];
    for(int a = 1; a <= H; a++)
        for(int b = 1; b <= L; b++)
            cin >> map[a][b];
    cout << "请输入终点坐标和起点坐标:";
    cin >> x >> y >> zx >> zy;
    int tag[51][51]= {0};
    tag[x][y] = 1;
    dfs(min_,0,x,y,zx,zy,H,L,map,tag);
    cout << "\nDONE " << min_ << endl;
    return 0;
}
