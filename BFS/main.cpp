#include <iostream>
using namespace std;
struct note{ //队列结构
    int x = 0;
    int y = 0;
    int s = 0; //步长
};

int main(){
    struct note que[2500]; //地图
    int a[50][50] = {0};
    bool book[50][50] = {false}; //标记用于检查当前的格子是否走过
    int next[4][2] = {      //用于检查周围格子 顺时针
        {1,0}, //向右走
        {0,1}, //向下走
        {-1,0},//向左走
        {0,-1} //向上走
    };
    int c[5][4] = {
    {0,0,1,0},
    {0,0,0,0},
    {0,0,1,0},
    {0,1,0,1},
    {0,0,0,1},
    };
    cout << c[3][3];
    int startx = 0, starty = 0; //起始坐标
    int mx = 0, my = 0;         //目标坐标
    int m = 0,n =0;             //地图长宽
    cout << "请输入地图长宽:" << endl;
    cin >> m >>n;
    cout << "请输入地图(1表示无障碍,0表示有障碍)" << endl;
    for(int i = 0; i<m; i++)
        for(int j = 0; j<n;j++)
            cin >> a[i][j];
    cout << "请输入起始坐标与目标坐标 "<< a[2][2] <<endl;
    cin >> startx >> starty >> mx >> my;

    //初始化队列
    int head = 0, tail = 0;
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].s = 0;
    tail++;
    book[tail][tail] = 1;

    bool flag = 0; //用于标记是否达到目标点
    while(head<tail){
        for(int k = 0; k<4; k++){
            int nx = que[head].x + next[k][0];
            int ny = que[head].y + next[k][1];
                    //检查是否越界
            if(nx<0 || nx>n || ny<0 || ny>m)
                continue;
                    //检查是否碰到障碍
            if(a[ny][nx] == 0 && book[ny][nx] == false){
                book[ny][nx] = true; //标记已经走过
                que[tail].x = nx;
                que[tail].y = ny;
                que[tail].s = que[head].s + 1;//步长是前面的+1
                tail++;
            }
            if(nx == mx && ny == my){         //如果到达目标点
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
