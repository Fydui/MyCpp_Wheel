#include <tmime.h>
#include <iostream>
inline double mysqr(double a){

    if(a > 10000){
        std::cout << a;
        return a;
    }
    mysqr(a*a);

}

int main(){

    TIME mytime(1,30);
    mytime.show(); //1:30

    TIME temp1(0,30);
    mytime = mytime + temp1;
    mytime.show(); //2:0

    mytime = mytime*2;
    mytime.show(); //4:0

    temp1.addHour(1);
    mytime = 2 * temp1;
    mytime.show(); //3:0

    mysqr(2);
    cout <<"\n" <<mytime << endl << temp1;
    return 0;
}
