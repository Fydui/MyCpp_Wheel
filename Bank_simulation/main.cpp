#include<iostream>
#include "brass.h"
using namespace std;
const int CLIENTS = 4;
int main(){
    brass * plist[CLIENTS];
    std::string temp = "";
    long tempnum = 0;
    double tempbal = 0.0;
    string kind = "";

    for(int i = 0; i < CLIENTS; i++){
        cout << "请输入名字: " ;
        cin >> temp;
        cout << "请输入初始余额: ";
        cin >> tempnum;
        cout << "Brass类 输入: 1\n Brassplus类 输入: 2";
        while(cin >> kind && (kind !="1" && kind != "2"))
            cout << "请输入1 or 2" << endl;
        if(kind == "1")
            plist[i] = new brass(temp, tempnum, tempbal);
        else{
            double tmax, trate;
            cout << "输入透支限额";
            cin >> tmax;
            cout << "请输入利率(小数): ";
            cin >> trate;
            plist[i] = new brassplus(temp,tempnum,tempbal,tmax,trate);
        }
        while(cin.get() != '\n') continue;
    }
    for(int i = 0; i < CLIENTS; i++){
        plist[i]->ViewAcct();
        cout << endl;
        delete plist[i];
    }
    cout << "Done" << endl;
    return 0;
}
