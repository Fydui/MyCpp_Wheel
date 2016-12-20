#include "player.h"

using namespace std;

double player::Average() const{
    if(source.size() > 0)
        return source.sum();
    else return 0;
}
const string & player::Name() const{
    return name;
}
double & player::operator [](int i){
    return source[i];
}
double player::operator [](int i) const{
    return source[i];
}
ostream & player::arr_out(ostream & os) const{
    int i =0 ;
    int lim = source.size();
    if(lim > 0){
        for(i = 0; i < lim; i++){
            os<<source[i] << " ";
            if(i%5 == 4) os << endl;
        }
        if(i % 5 != 0) os << endl;
    }
    else 
        os << "empty array" <<endl;
    return os;
}

istream & getline(istream & is, player & pl){
    getline(is,pl.name);
    return is;
}
istream & operator >>(istream & is,player & pl){
    is >> pl.name;
    return is;
}
ostream & operator <<(ostream & os,const player & pl){
    os << "Sources for"<<pl.name<<": \n";
    pl.arr_out(os);
    return os;
}
