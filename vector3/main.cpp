#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Rev{
    string title;
    int rating;
};
bool operator < (const Rev & r1, const Rev & r2)
{
    if(r1.title < r2.title)
        return true;
    else if(r1.title == r2.title && r1.rating < r2.rating)
        return true;
    else
        return false;
}

bool worseThan(const Rev & r1, const Rev & r2)
{
    if(r1.rating < r2.rating)
        return true;
    else return false;
}

bool FillRev(Rev & rr)
{
    cout << "请输入书名(quit 退出):";
    getline(cin,rr.title);
    if(rr.title == "quit")
        return false ;
    cout << "请输入评分: ";
    cin >> rr.rating;
    if(!cin)
        return false;
    while (cin.get() != '\n')
        continue;

    return true;
}

void ShowRev(const Rev &rr)
{
    cout << rr.rating << "\t" << rr.title << endl;
}

int main()
{
    vector<Rev> books;
    Rev temp;
    while(FillRev(temp))
        books.push_back(temp);
    if(books.size() > 0)
    {
        cout << "vector<Rev>的大小" << books.size() << endl;
        cout << "原输出:" << endl;
        for_each(books.begin(),books.end(),ShowRev);

        sort(books.begin(),books.end());
        cout << "按照名字排序:" << endl;
        for_each(books.begin(),books.end(),ShowRev);

        sort(books.begin(),books.end(),worseThan);
        cout << "按照分数排序:" << endl;
        for_each(books.begin(),books.end(),ShowRev);

        random_shuffle(books.begin(),books.end());
        cout << "随机排列后: " << endl;
        for_each(books.begin(),books.end(),ShowRev);

    }
    else
        cout << "无条目.." << endl;
    cout << "BYE" << endl;

    return 0;
}

