#include<iostream>
using namespace std;
/*
void fun(int a){
    if(a == 65535){
        throw "发现65535!";
        cout << "65535!!" << endl;
    }

}*/
/*
*一个数n 除5余1 除6余5 除7余4 除11余10 n求最小值
*
*/
int main(){
    int j = 0;
    int arg[100] = {0};
    for(int i = 0; i < 100000; i++){
        if(1 == i%5 && 5 == i%6 && 4 == i%7 && 10 == i%11){//第一个结果就是..
            arg[j++] = i; //多来几个试试?
        }
    }
    //闲的排个序
    for(int i= 0; i < 100; i++){
        for(int k = 0; k < 100; k++){
            if(arg[k] < arg[k+1]){
                int temp = 0;
                temp = arg[k+1];
                arg[k+1] = arg[k];
                arg[k] = temp;/*
                try{
                    fun(temp);
                }
                catch(const char* s){
                    cout << s;
                    break;
                }*/
            }
        }
    }
    for (int i = 0; i < 100; i++) cout << arg[i] << endl;

    //似乎是个数列 做差发现公差为2310 这是个通项公式为an = 2111+(n-1)*2310的等差数列
    for(int a = 0; a < 100; a++){
        int p = arg[a] - arg[a+1];
        cout<< p << endl;
    }


    return 0;
}

