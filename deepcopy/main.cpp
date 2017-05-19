#include<deep.h>
#include <iostream>
using namespace std;
int main(){

  deep a("233");
  deep b = a;
  cout <<"b:" <<b << endl;
  cout << "a:" << a << endl;
  cout << "&b:" << &b << endl;
  cout << "&a:" << &a << endl;

  cout << "b.name;" << &b.name << endl;
  cout << "a.name;" << &a.name << endl;
    return 0;
}
