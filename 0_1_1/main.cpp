#include <iostream>
using namespace std;


void c_in(string text,int s)
{
    for(int i =0;i < s;i++)
    {
        cout << text << endl;
    }
    cout << "done." << endl;
}

int main()
{
    int userS = 0;
    int userK = 0;
    cout << "你想说多少句话?0v0" << endl;
    cin >>  userS;
    cout << "多少次呢?" << endl;
    cin >> userK;
    for(int l = 0; l <userS;l++)
    {
        string userI = "";
        cout << "好吧,你想说啥: " << endl;
        cin >> userI;
        c_in(userI,userK);
    }
    return 0;
}
