#include <iostream>
using namespace std;
const int SUM = 10;
//如果超过SUM个字符,则超过的字符将留在输入流中..跳过他们
inline void eatline(){
    while(cin.get() != '\n'){
        cout << "eatline() done..." << endl;
        continue;
    }
}

int main()
{
    char name [SUM] ;
    char title[SUM];

    cout << "输入字符串: " << endl;
    cin.get(name,SUM);
    if (cin.peek() != '\n');
       cout << "对于: "<< name <<" 来说存储空间足够" << endl;
    eatline();
    cout<< "输入字符串2" << endl;

    cin.get(title,SUM);
    if(cin.peek() != '\n')
        cout << "被迫截断字符串2" << endl;
    eatline();
    cout << "字符串1: " << name << " 字符串2: " << title << endl;

    return 0;
}
