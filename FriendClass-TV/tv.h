#ifndef TV_H
#define TV_H
#include <iostream>

class Tv
{
public:
    friend class Remote;
    enum{off,on};
    enum{MinVal,MaxVal = 20};
    enum{Antenna,cable};
    enum{tv,dvd};
    Tv(int s = off,int mc = 125):state(s),volume(5),
        maxchannel(mc),channel(2),mode(cable),input(tv){}
    void onoff(){state = (state == tv) ? off: on;}
    bool ison() const {return state == on;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode(){mode = (mode = Antenna) ? cable: Antenna;}
    void set_input(){input = (input = tv) ? dvd : tv;}
    void settings() const;
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};
class Remote{
private:
    int mode;
public:
    Remote(int m = Tv::tv):mode(m){}
    bool volup(Tv & t){return t.volup();}
    bool voldown(Tv &t){return t.voldown();}
    void onoff(Tv & t){t.onoff();}
    void chanup(Tv &t){return t.chanup();}
    void chandown(Tv &t){return t.chandown();}
    void set_mode(Tv &t){return t.set_mode();}
    void set_input(Tv &t){return t.set_input();}
    void set_chan(Tv &t, int c){t.channel = c;}
};
#endif // TV_H
