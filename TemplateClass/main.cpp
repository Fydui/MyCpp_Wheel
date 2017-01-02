#include <iostream>
#include <string>
#include "Stackk.h"
#include "stackk_g.h"
using namespace std;
int main()
{   /*
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
    */
    int ss;
    cin >> ss;
    Stack_p<const char *> aa(ss);
    const char * list[3] = {"aaa","bbb","ccc"};
    const char * tlist[3];
    int p= 0,n = 0;
    while (p < 3){
        if(aa.isempty())
            aa.push(list[n++]);
        else if (aa.isfull())
            aa.pop(tlist[p++]);
        else
            aa.pop(tlist[p++]);
    }
    for(int i = 0; i<3; i++)
        cout << tlist[i] << endl;
    return 0;
}
