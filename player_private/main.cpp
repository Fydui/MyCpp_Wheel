#include<iostream>
#include <play_p.h>
using namespace std;
const int pupils = 3;
const int quizzes = 5;
void set(play_p & p,int n){
    cout << "����������: ";
    getline(cin,p);
    cout << "������: " << n << "����" << endl;
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
    cout << "��������:" << endl;
    for(i = 0; i < pupils; i++)
        cout << a[i].Name() << endl;
    cout << "���: " <<endl;
    for( i = 0; i < pupils; i++)
    {
        cout << endl << a[i];
        cout << "Average:" << a[i].Average() << endl;
    }
    cout << "Done";
    return 0;
}
