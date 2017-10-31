// BFS1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int book[5] = { 0,0,0,0,0 };
struct  que
{
	vector<int> q;
	int begin;
	int end;
};

void BFS_1(vector<vector<int>> map,que m)
{	
	//初始点是0? 此处初始点其实应该是1 不过因为图用了二维数组表示所以.... 
	m.q.push_back(0); //首节点入栈
	m.begin = 0;	  //队列首
	m.end = 1;		  // 队列末

	while (m.begin != m.end) {						//如果首末未相遇
		for (int c = 0; c < map[0].size(); c++) {	//开始遍历与初始点相邻的所有点(邻接矩阵存储法)
			if (map[m.begin][c] == 1 && book[c] == 0) { //条件判断 其m.begin为起始点, c为要去的节点
				m.q.push_back(c);						//通过查看map, 如果值为1表示起始点与要去的节点有边
				book[c] = 1;							//将其节点入栈 且标记已走	
			}
		}
		m.end++;										//队列尾向后移
		m.begin = m.q[++m.begin];						//将已经走过的点出栈 设置新的队列首
	}
	for (int i = 0; i < map.size(); i++) {
		cout << m.q[i] + 1 << " ";						//无所谓啦 +1s比较吼看
	}
	return;
}

int main()
{
	vector<vector<int>> map =	//图的邻接矩阵存储法
	{
		{ 2,1,1,0,1 },
		{ 1,2,0,1,0 },
		{ 1,0,2,0,1 },
		{ 0,1,0,2,0 },
		{ 1,0,1,0,2 },
	};
	que m;
	book[0] = 1;				//初始点标记已走
	BFS_1(map, m);

    return 0;
}

