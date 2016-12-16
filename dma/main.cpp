#include<DMA.h>
#include<iostream>
using namespace std;
int main(){
    
    DMA a("DMA",0);
    shipDMA b("shipDMA",0,18);
    shipplus c("shipplus",0,"CV");
    
    cout << "DMA: " << a << endl;
    cout << "shipDMA: " << b << endl;
    cout << "shipplus: " << c <<endl;
    
    shipDMA b2(b);
    cout << "B2: " << b2 << endl;
    shipplus c2;
    c2 = c;
    cout << "c2: " << c2 << endl;
    
    return 0;
}
