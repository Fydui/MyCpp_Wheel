#include "tv.h"
using namespace std;
int main(){

    using std::cout;
    Tv ccav;
    cout << "initial setting for ccav" << endl;
    ccav.settings();
    ccav.onoff();;
    ccav.chanup();
    cout << "setting ccav" << endl;
    ccav.chanup();
    cout << "setting ccav" << endl;
    ccav.settings();

    Remote grey;
    grey.set_chan(ccav,15);
    grey.volup(ccav);
    grey.voldown(ccav);
    cout << "setting remote" << endl;
    ccav.settings();

    Tv bilibili(Tv::on);
    bilibili.set_mode();
    grey.set_chan(bilibili,20);
    cout << "Bilibili setting" << endl;
    bilibili.settings();

    return 0;
}

