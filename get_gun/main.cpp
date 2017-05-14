#include <iostream>
using namespace std;
const int Limit = 255;

int main()
{
    char input[Limit];
    cout << "使用getline()接受字符串: " << endl;
    cin.getline(input,Limit,'#');
    cout << "输出: " << endl;
    cout << input << "\n Done" << endl;

    char ch;
    cin.get(ch);
    cout << "下一个输入字符是:" << ch << endl;
    if(ch != '\n')
        cin.ignore(Limit,'\n');
    cout << "使用get()接受字符串:" << endl;
    cin.get(input, Limit, '#');
    cout << "输出:" <<endl;
    cout << input << "\n Done" << endl;

    cin.get(ch);
    cout << "下一个输入字符是:" << ch << endl;

    return 0;
}

