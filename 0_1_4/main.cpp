#include<iostream>
using namespace std;

struct pizza
{
    pizza(){name = new char[50];}
    char* name;
    double d;
    double kg;

    ~pizza()
    {
        delete [] name;
    }
};

int main()
{
    //pizza* mypiz = new pizza;
    pizza mypiz;

    cout << "enter pizza name" << endl;
    cin >> mypiz.name;

    cout << "enter pizza diameter" << endl;
    cin >> mypiz.d;

    cout << "enter pizza mass" << endl;
    cin >> mypiz.kg;

    cout << "pizza name: " << mypiz.name
         << "\npizza diameter: " << mypiz.d
         << "\npizza mass: " << mypiz.kg << endl;

    return 0;

}

