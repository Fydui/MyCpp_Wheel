#include"StringBad.h"
#include "stringptr.h"
using namespace std;
int main(){
    StringPtr ice("ice");
    StringPtr t("jelly");
    StringPtr a;
    a = ice + t;
    cout << a;
    return 0;
}
