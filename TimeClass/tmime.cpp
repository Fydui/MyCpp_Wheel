#include "tmime.h"

TIME::TIME(){}
TIME::TIME(int hour, int min){
    this->hour = hour;
    this->min = min;
}
void TIME::addHour(int hour){
    this->hour = hour;
}
void TIME::addMin(int min){
    this->min += min;
    this->hour = this->min/60;
    this->min %= 60;
}
void TIME::show(){
    std::cout << hour << ":" << min << std::endl;
}

//TIME.operator+(ADDTIME);
TIME TIME::operator +(const TIME& t){
    TIME temp;
    temp.min = this->min + t.min;
    temp.hour = this->hour + t.hour + temp.min/60;
    temp.min %= 60;
    return temp;
}
TIME TIME::operator -(const TIME& t){
    TIME temp;
    int t1=0, t2=0;
    t1 = this->hour*60 + this->min;
    t2 = t.hour*60 + t.min;
    temp.hour = (t1 - t2)*60;
    temp.min = (t1 - t2)%60;
    return temp;
}

TIME operator *(double t, const TIME& T){
    TIME temp;
    int t1 = (T.hour*60 + T.min)*t;
    temp.hour = t1/60;
    temp.min = t1%60;
    return temp;
}

TIME TIME::operator *(double t){
    TIME temp;
    int T = (this->hour*60 + this->min)*t;
    temp.hour = T/60;
    temp.min = T%60;
    return temp;
}



