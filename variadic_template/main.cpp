#include<iostream>
#include<functional>
using namespace std;

void f_fun(function<void()> f){ //std::function
    f();
}

void ptr_fun(void (*f)()){  //函数指针
    f();
}


template<typename T, typename...Args>    //模板
void template_fun(T f, const Args&... rest){
   
    auto newfun = bind(f,rest...);
    newfun();
}

int fun(string &s, int i){
    cout<<"call fun"<< s << i;
    return i;
};

int main(){

    template_fun(fun,string("one_arg "),2);
    return 0;
}
