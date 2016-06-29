// maptest_vs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{	
	map<string,string>mymap;
	mymap["你好"] = "你好啊";
	mymap["你多大了"] = "不告诉你";
	mymap["你叫啥"] = "凉果冻";
	string x;
	for (int i = 0; i < 3; i++)
	{	
		cin >> x;
		cout << mymap[x] << endl;
		
	}
	system("pause");
    return 0;
}

