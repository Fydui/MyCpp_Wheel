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
    cout << "请输入书名(quit退出): " ;
    getline(cin,rr.title);
    if(rr.title == "quit") return false;
    cout << "请输入评分:";
    cin >> rr.rating;
    if(!cin) return false;
    while(cin.get() != '\n')
        continue;
    return true;
}

void ShowRev(const Rev &rr)
{
    cout << "评分:"<< rr.rating << "\t" <<"名字:"<< rr.title << endl;
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
            cout << "已经删除books[books.begin()+1,books.begin()+3)区间:" << endl;
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowRev(*pr);
            books.insert(books.begin(),oldliset.begin()+1,oldliset.begin()+2);
            cout << "已经插入oldliset的[oldliset.begin()+1,oldliset.begin()+2)区间到books的books.begin():" << endl;
            for(pr = books.begin(); pr != books.end(); pr++)
                ShowRev(*pr);
        }
        books.swap(oldliset);
        cout << "已经交换了books和oldlist的内容:" << endl;
        for(pr = books.begin(); pr != books.end(); pr++)
            ShowRev(*pr);
    }
    return 0;
}
