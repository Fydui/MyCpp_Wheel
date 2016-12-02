#include<iostream>
#include"TableTennisPlayer.h"
using namespace std;
int main(){
    TableTennisPlayer player1("ysy","A",false);
    RatedPlayer rplayer1(1440,"ysy_","B",true);
    rplayer1.Name();
    if(rplayer1.HasTable()) cout << ":has a table" << endl;
    else cout << ":hasn't' a table"<<endl;
    player1.Name();
    if(player1.HasTable()) cout << ":has a table"<<endl;
    else cout << ":hasn't a table"<<endl;
    cout << "Name: ";
    rplayer1.Name();
    cout << "; Ratting: " << rplayer1.Rating() << endl;
    RatedPlayer rplayer2(1212,player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Ratting: " << rplayer2.Rating() << endl;

    return 0;
}
