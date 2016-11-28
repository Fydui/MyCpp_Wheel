#include "stringptr.h"
int main(){
    StringPtr A("a");
    StringPtr B;
    StringPtr C;
    B = A;
    C = B;
    return 0;
}
