#include <iostream>
#include <string>
#include "Stackk.h"
using namespace std;
int main()
{
    Stack<string> st;
    string po;
    char ch;
    cout << "enter A to add, P to process a PO" << endl;
    while(cin >> ch && toupper(ch) != 'Q')
    {
        while(cin.get() != '\n')
            continue;
        if(!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a':
                cout << "Enter Po number add:";
                cin >> po;
                if(st.isfull())
                    cout << "FULL" << endl;
                else st.push(po);
                break;
            case 'P':
            case 'p':
                if(st.isempty())
                    cout << "EMPTY" << endl;
                else
                {
                    st.pop(po);
                    cout << "PO : " << po << endl;
                    break;
                }
        }
        cout << "enter A to add, P to process a PO" << endl;
    }
    return 0;
}
