#include <iostream>
#include <string>
#include "brassabc.h"
using namespace std;
const int CLIENTS = 4;

int main(){
    BrassABC * plite[CLIENTS];
    string temp = "";
    string kind = "";
    double tempbal = 0;
    long tempnum = 0.0;

    for(int i = 0; i<CLIENTS; i++){
        cout << "请输入账户名字: ";
        getline(cin,temp);
        cout << "\n请输入账户ID: ";
        cin >> tempnum;
        cout << "\n请输入开户存款: ";
        cin >> tempbal;
        cout << "\n输入1 Brass,输入2 BrassPlus: ";
        while(cin>>kind && (kind != "1" && kind != "2") )
            cout << "\n请输入1或者2" << endl;
        if(kind == "1")
            plite[i] = new Brass(temp,tempnum,tempbal);
        else
        {
            double tmax, trate;
            cout << "\n请输入透支限额: ";
            cin >> tmax;
            cout << "\n输入透利率(小数): ";
            cin >> trate;
            plite[i] = new BrassPlus(temp,tempnum,tempbal,tmax,trate);
        }
        while(cin.get() != '\n') continue;
    }
    cout << endl;
    for(int i = 0; i < CLIENTS; i++){
        plite[i]->ViewAcct();
        delete plite[i];
    }
    cout << "DONE." << endl;
}
