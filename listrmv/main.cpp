#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
const int LIM = 10;
void Show(int v){
    cout << v << ' ';
}
int main(){
    int ar[LIM] = {4,5,4,2,2,3,4,8,1,4};
    list<int> la(ar,ar+LIM);
    list<int> lb(la);
    cout << "原始内容: ";
    for_each(la.begin(),la.end(),Show);
    cout << endl;
    la.remove(4); //这个是list成员,可以调整链表长度;
    cout << "remove():" << endl;
    cout << "la:";
    for_each(la.begin(),la.end(),Show);
    cout << endl;
    list<int>::iterator last;
    last = remove(lb.begin(),lb.end(),4);
    /* 该SLT算法(remove())不是list成员,因此不能调整链表长度.
     * 他将没被删除的元素放在链表的开始,并返回一个指向新的超尾的迭代器 */
    cout << "Remove():";
    cout << "lb: ";
    for_each(lb.begin(),lb.end(),Show);
    cout << endl;
    lb.erase(last,lb.end());
    cout << "erase():";
    cout << "lb: ";
    for_each(lb.begin(),lb.end(),Show);
    cout << endl;

    return 0;
}
