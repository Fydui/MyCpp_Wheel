#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main()
{
    using namespace std;

    int casts[10] = {6,7,2,9,4,11,8,7,10,5};
    vector<int> dice(10);
    copy(casts,casts+10,dice.begin());
    cout << "原始数据: " << endl;
    ostream_iterator<int,char> out_iter(cout," ");
    copy(dice.begin(),dice.end(),out_iter);
    cout << endl;
    cout << "使用了反向迭代器重新输出:" << endl;
    copy(dice.rbegin(),dice.rend(),out_iter);
    cout << endl;
    cout << "使用了vector类的reverse_iterator: " << endl;
    vector<int>::reverse_iterator ri;
    for(ri = dice.rbegin(); ri != dice.rend(); ++ri)
        cout << *ri << ' ';
    cout << endl;

return 0;
}
