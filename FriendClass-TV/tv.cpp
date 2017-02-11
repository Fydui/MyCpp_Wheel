#include "tv.h"

bool Tv::volup()
{
    if(volume < MaxVal){
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if(volume > MinVal){
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chandown()
{
    if (channel >1) channel--;
    else channel = maxchannel;
}
void Tv::chanup()
{
    if (channel < maxchannel) channel++;
    else channel =1;
}
void Tv::settings() const
{
    using std::cout;
    using std::endl;
    cout << "Tv is " << (state == off ? "off" : "on") <<endl;
    if(state == on){
        cout << "Volme setting =" << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode =" << (mode == Antenna? "antenna" : "cable") << endl;
        cout <<"input = " << (input == tv? "tv" :"dvd") << endl;
    }
}
