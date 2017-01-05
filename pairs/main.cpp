#include <iostream>
#include <string>
template <typename T1, typename T2>
class pairs
{
private:
    T1 t1;
    T2 t2;
public:
    T1 & first();
    T2 & second();
    T1 first() const{return t1;}
    T2 second() const {return t2;}
    pairs(const T1 & t1_,const T2 & t2_) : t1(t1_),t2(t2_){}
    pairs(){}
};
template<typename T1,typename T2>
T1 & pairs<T1,T2>::first(){
    return t1;
}
template<typename T1,typename T2>
T2 & pairs<T1,T2>::second(){
    return t2;
}
int main()
{
    using namespace std;
    pairs<string,int> r[3] ={
        pairs<string,int>("ONE",1),
        pairs<string,int>("TWO",2),
        pairs<string,int>("THREE",3),
    };
    int joint = sizeof(r)/sizeof(pairs<string,int>);
    for(int i = 0; i < joint; i++){
        cout << r[i].first() << endl;
        cout << r[i].second() << endl;
    }/*
    r[3].first() = "23333";
    r[3].second() = 666;
    std::cout << r[3].first() << std::endl;
    std::cout << r[3].second() << std::endl;*/

    return 0;
}
