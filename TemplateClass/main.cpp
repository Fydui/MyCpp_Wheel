#include <iostream>
#include <string>
#include "Stackk.h"
#include "stackk_g.h"
#include <ctime>
#include <cstdlib>
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
    //stackk_g
    srand(time(0));
    cout << "Enter Stack Size:";
    int sta;
    cin >> sta;
    Stack_p<const char *> st(sta);
    const char * in[3] = {"ONE","TWO","THREE"};
    const char * out[3];
    int p = 0;
    int n = 0;
    while(p < 3)
    {
        if(st.isempty())
            st.push(in[n++]);
        else if(st.isfull())
            st.pop(out[p++]);
        else if(rand() % 2 && n < 3)
            st.push(in[n++]);
        else
            st.pop(out[p++]);
    }
    for (int i = 0; i < 3; i++)
        cout << out[i] << endl;

    return 0;
}
