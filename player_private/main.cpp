#include<iostream>
#include <play_p.h>
using namespace std;
const int pupils = 3;
const int quizzes = 5;
void set(play_p & p,int n){
    cout << "请输入名字: ";
    getline(cin,p);
    cout << "请输入: " << n << "分数" << endl;
    for(int i = 0; i < n;i++)
        cin >> p[i];
    while (cin.get() != '/n')
        continue;
}
int main(){
    play_p a[pupils] = {play_p(quizzes),play_p(quizzes),play_p(quizzes)};
    int i;
    for(i = 0; i <pupils; i++)
        set(a[i],quizzes);
    cout << "人物名单:" << endl;
    for(i = 0; i < pupils; i++)
        cout << a[i].Name() << endl;
    cout << "结果: " <<endl;
    for( i = 0; i < pupils; i++)
    {
        cout << endl << a[i];
        cout << "Average:" << a[i].Average() << endl;
    }
    cout << "Done";
    return 0;
}
