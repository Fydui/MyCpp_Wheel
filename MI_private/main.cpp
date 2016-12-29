#include <Worker.h>
const int LIM = 4;
int main(){
    Waiter ysy("ysy",314L,5);
    Singer bev("ysy_2",522,3);
    Waiter w_temp;
    Singer s_temp;
    Worker * pw[LIM] = {&ysy,&bev,&w_temp,&s_temp};

    for(int i = 2; i<LIM; i++)
        pw[i]->Set();
    for(int i = 0;i < LIM; i++){
        pw[i]->Show();
        cout<<endl;
    }
return 0;
}
