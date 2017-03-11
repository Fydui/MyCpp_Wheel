#include <iostream>
using namespace std;
int main(){
    int sum = 0;
for(int a = 0; a < 100; a++)
    for(int b = 0; b < 100; b++)
        for(int c =0; c < 100; c++)
                if((100 >= a+b+c) && (100 == a*3 +b*5 + c*1)){
                    sum++;
                    cout <<"No :" <<sum << endl
                         << "3: " << a << " 5: " << b << " 1: " << c <<endl
                         << "3*A + 5*b + C =" << a*3 +b*5 + c*1 << endl
                         << "a+b+c= " <<a+b+c << endl<< endl;
                }
    cout << "DONE: " << sum << endl;
    return 0;
}

