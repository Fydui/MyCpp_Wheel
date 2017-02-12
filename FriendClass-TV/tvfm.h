#ifndef TVFM_H
#define TVFM_H
#include <iostream>
class Tv;

class Remote{
    enum State{off,on};
    enum{MinVal,MaxVal = 20};
    enum{Antenna,cable};
    enum{tv,dvd};
private:
    int mode;
public:
    Remote(int m = Tv::tv):mode(m){}
    bool volup(Tv & t);
    bool voldown(Tv &t);
    void chanup(Tv &t);
    void chandown(Tv &t);
    void set_mode(Tv &t);
    void set_input(Tv &t);
    void set_chan(Tv &t, int c);
    void onoff(Tv & t);
};

class Tv
{
public:
    friend void Remote::set_chan(Tv &t,int c);
    enum State{off,on};
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

inline bool Remote::volup(Tv &t) {return t.volup();}
inline bool Remote::voldown(Tv &t) {return t.voldown();}
inline void Remote::onoff(Tv &t){t.onoff();}
inline void Remote::chanup(Tv &t) {t.chanup();}
inline void Remote::chandown(Tv &t){t.chandown();}
inline void Remote::set_mode(Tv &t){t.set_mode();}
inline void Remote::set_input(Tv &t){t.set_input();}
inline void Remote::set_chan(Tv &t, int c){t.channel = c;}
#endif // TVFM_H
