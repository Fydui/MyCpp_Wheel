#include"player.h"
const int pupils = 3;
const int quizzes = 5;
void set(player & pl,int n){
    cout << "enter name:";
    getline(cin,pl);
    cout << "please enter " <<n <<"quiz soures: "<<endl;
    for(int i = 0; i<n; i++) 
        cin >> pl[i];
    while(cin.get() != '\n') continue;
}
int main(){
    
    player a[pupils] = {player(quizzes),player(quizzes),player(quizzes)};
    for(int i = 0; i<pupils;++i)
        set(a[i],quizzes);
    cout << "\n player list \n";
    for(int i = 0; i<pupils;++i)
        cout << a[i].Name() << endl;
    cout << "\n Results \n";
    for(int i = 0; i<pupils; i++){
        cout << endl << a[i];
        cout << "average: " << a[i].Average() << endl; 
    }
    cout << "DONE." << endl;
    return 0;
}
