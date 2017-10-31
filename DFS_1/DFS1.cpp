// DFS1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

struct node {
	vector<int> temp;
	vector<vector<int>> arr;
	int qx;
	int qy;
};
vector<vector<int>> book = {
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 },
	{ 0,0,0,0 }
};

int num = INT_MAX;

void DFS_1(node n, int px, int py, int step)
{
	if (n.qx == px && n.qy == py) {
		if (step< num) 	num = step;
		return;
	}

	int xy[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

	for (int i = 0; i < n.arr[0].size(); i++) {
		int x = px + xy[i][0];
		int y = py + xy[i][1];
		if (0 <= x && x < n.arr[0].size() && y >= 0 && y < n.arr.size()) 
			if (n.arr[y][x] == 0 && book[y][x] == 0) {
				book[y][x] = 1;
				DFS_1(n, x, y, step + 1);
				book[y][x] = 0;
			}
	}

	return;
}


int main()
{
	node my;

	my.arr = {
		{ 0,0,1,0 },
		{ 0,0,0,0 },
		{ 0,0,1,0 },
		{ 0,1,0,0 },
		{ 0,0,0,1 }
	};

	my.qx = 0; //终点x坐标
	my.qy = 4; //终点y坐标
	my.arr[0][0] = 1;
	DFS_1(my, 0, 0, 0); //起点x,y坐标以及起始步数

	cout << " Min step: " << num << endl;

	return 0;
}




