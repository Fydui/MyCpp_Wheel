// maptest_vs.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{	
	map<string,string>mymap;
	mymap["���"] = "��ð�";
	mymap["������"] = "��������";
	mymap["���ɶ"] = "������";
	string x;
	for (int i = 0; i < 3; i++)
	{	
		cin >> x;
		cout << mymap[x] << endl;
		
	}
	system("pause");
    return 0;
}

