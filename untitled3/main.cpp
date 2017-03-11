#include <iostream>
using namespace std;

int main(){
    int L = 0;
    int S = 0;
while(cin >>L >> S ){
    for(int a = 0; a < L; a++){
        int temp = L -a;
        if(S == temp* a)
            cout << "H:" << temp << " W:" << a << endl;
    }
}
cout << "done";
return 0;
}
