#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Rev{
    string title;
    int rating;
};

bool FillRev(Rev & rr)
{
    cout << "����������(quit�˳�): " ;
    getline(cin,rr.title);
    if(rr.title == "quit") return false;
    cout << "����������:";
    cin >> rr.rating;
    if(!cin) return false;
    while(cin.get() != '\n')
        continue;
    return true;
}

void ShowRev(const Rev &rr)
{
    cout << "����:"<< rr.rating << "\t" <<"����:"<< rr.title << endl;
}

int main()
{
    vector<Rev> books;
    Rev temp;
    while(FillRev(temp))
        books.push_back(temp);
    int sum = books.size();
    if(sum> 0)
    {
        for(int i = 0; i < sum; i++)
            ShowRev(books[i]);

        vector<Rev>::iterator pr;
        for(pr = books.begin();pr != books.end(); pr++)
            ShowRev(*pr);
        vector<Rev> oldliset(books);
        if(sum > 3)
        {
            books.erase(books.begin()+1,books.begin()+3);
            cout << "�Ѿ�ɾ��books[books.begin()+1,books.begin()+3)����:" << endl;
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowRev(*pr);
            books.insert(books.begin(),oldliset.begin()+1,oldliset.begin()+2);
            cout << "�Ѿ�����oldliset��[oldliset.begin()+1,oldliset.begin()+2)���䵽books��books.begin():" << endl;
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowRev(*pr);
        }
        books.swap(oldliset);
        cout << "�Ѿ�������books��oldlist������:" << endl;
        for(pr = books.begin(); pr != books.end(); pr++)
            ShowRev(*pr);
    }
    return 0;
}
