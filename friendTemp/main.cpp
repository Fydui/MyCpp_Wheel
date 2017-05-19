#include <iostream>
using namespace std;
template <typename T>
class HasFriend
{
private:
    T item;

public:
    HasFriend(const T & i) : item(i){ct++;}
    ~HasFriend() {ct--;}
    friend void conuts();
    friend void report(HasFriend<T> & hf);
    static int ct;
};
template <typename T>
int HasFriend<T>::ct =0;
void counts()
{
    cout << "int count:" << HasFriend<int>::ct <<endl;
    cout << "double count:" << HasFriend<double>::ct <<endl;
}

void report(HasFriend<int> & hf)
{
    cout << "HasFriend<int>" << hf.item << endl;
}

void report(HasFriend<double> & hf)
{
    cout << "HasFriend<double>" << hf.item << endl;
}
int main()
{
    cout << "Start:" << endl;;
    counts();
    HasFriend<int> hfil(10);
    counts();
    HasFriend<int> hfi2(20);
    counts();
    HasFriend<double> hfdb(10.5);
    counts();
    report(hfil);
    report(hfi2);
    report(hfdb);
    return 0;
}
