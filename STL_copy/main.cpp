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
    cout << "ԭʼ����: " << endl;
    ostream_iterator<int,char> out_iter(cout," ");
    copy(dice.begin(),dice.end(),out_iter);
    cout << endl;
    cout << "ʹ���˷���������������:" << endl;
    copy(dice.rbegin(),dice.rend(),out_iter);
    cout << endl;
    cout << "ʹ����vector���reverse_iterator: " << endl;
    vector<int>::reverse_iterator ri;
    for(ri = dice.rbegin(); ri != dice.rend(); ++ri)
        cout << *ri << ' ';
    cout << endl;

return 0;
}
