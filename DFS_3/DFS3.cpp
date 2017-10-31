// DFS3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
//遍历整棵树
int node_num = 0;
vector<int> book;
void DFS_3(vector<vector<int>> map) {

	int node = node_num;
	cout << node + 1 << " ";
	for (int i = 0; i < map.size(); i++) {
		if (map[node][i] == 1 && book[i] == 0) {
			book[i] = 1;
			node_num = i;			
			DFS_3(map);
		}
	}
	return;
}

int main()
{
	//图的邻接矩阵存储法:
	vector<vector<int>> map =
	{
		{2,1,1,0,1},
		{1,2,0,1,0},	
		{1,0,2,0,1},	
		{0,1,0,2,0},		 
		{1,0,1,0,2},	
	};
	book = { 0,0,0,0,0,};
	book[0] = 1;
	DFS_3(map);
    return 0;
}

